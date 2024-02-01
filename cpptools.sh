#!/bin/bash

echo "__Project starter generator__"

echo "Enter project name:"
read NAME

echo "Enter project dirname:"
read DIRNAME

echo "Do you want to create a git repository? (y/n)"
read GIT

echo "Do you want separate directories for headers and sources? (y/n)"
read SUBDIRS

echo "Enter files to create (separated by spaces):"
read FILES

CPPFILES=()
HPPFILES=()
MAKEFILE=0
MAINFILE=""
SRCDIR=""
OBJDIR=""
INCDIR=""

mkdir $DIRNAME && cd $DIRNAME

if [[ $SUBDIRS == "y" ]]; then
    SRCDIR="src/"
    OBJDIR="obj/"
    INCDIR="inc/"
    mkdir src inc
fi

for FILE in $FILES; do
    if [[ $FILE == "Makefile" ]]; then
        MAKEFILE=1
    elif [[ $FILE == "main" ]]; then
        MAINFILE="$SRCDIR$FILE.cpp"
    elif [[ $FILE =~ ^[A-Z] ]]; then
        CPPFILES+=("$SRCDIR$FILE.cpp")
        HPPFILES+=("$INCDIR$FILE.hpp")
    fi
done

if [[ $GIT == "y" ]]; then
    git init
    touch .gitignore
    echo ".DS_Store" >> .gitignore
    echo "a.out" >> .gitignore
    echo "obj" >> .gitignore
    echo "$NAME" >> .gitignore
    echo "*.o" >> .gitignore
    echo ".vscode/" >> .gitignore
    echo "*.dSYM/" >> .gitignore
    echo "" >> .gitignore
fi

echo -e "\033[32mGenerating files...\033[0m"

if [[ $MAINFILE != "" ]]; then
    touch $MAINFILE
    for FILE in ${HPPFILES[@]}; do
        BASENAME=$(basename $FILE .cpp)
        echo "#include \"$BASENAME\"" >> $MAINFILE
    done
    echo "" >> $MAINFILE
    echo "int main(void)" >> $MAINFILE
    echo "{" >> $MAINFILE
    echo "    // std::cout << \"Hello world!\" << std::endl;" >> $MAINFILE
    echo "    return 0;" >> $MAINFILE
    echo "}" >> $MAINFILE
    echo "" >> $MAINFILE
    echo -e "\033[32m$MAINFILE created!\033[0m"
fi

for FILE in ${CPPFILES[@]}; do
    touch $FILE
    BASENAME=$(basename $FILE .cpp)
    echo "#include \"$BASENAME.hpp\"" >> $FILE
    echo "" >> $FILE
    echo "$BASENAME::$BASENAME(void)" >> $FILE
    echo "{" >> $FILE
    echo "    // std::cout << \"Default constructor called\" << std::endl;" >> $FILE
    echo "    return ;" >> $FILE
    echo "}" >> $FILE
    echo "" >> $FILE
    echo "$BASENAME::$BASENAME($BASENAME const & src)" >> $FILE
    echo "{" >> $FILE
    echo "    // std::cout << \"Copy constructor called\" << std::endl;" >> $FILE
    echo "    *this = src;" >> $FILE
    echo "    return ;" >> $FILE
    echo "}" >> $FILE
    echo "" >> $FILE
    echo "$BASENAME::~$BASENAME(void)" >> $FILE
    echo "{" >> $FILE
    echo "    // std::cout << \"Destructor called\" << std::endl;" >> $FILE
    echo "    return ;" >> $FILE
    echo "}" >> $FILE
    echo "" >> $FILE
    echo "$BASENAME & $BASENAME::operator=($BASENAME const & src)" >> $FILE
    echo "{" >> $FILE
    echo "    if (this != &src)" >> $FILE
    echo "    {" >> $FILE
    echo "        // std::cout << \"Assignation operator called\" << std::endl;" >> $FILE
    echo "    }" >> $FILE
    echo "    return *this;" >> $FILE
    echo "}" >> $FILE
    echo "" >> $FILE
    echo "std::ostream & operator<<(std::ostream & o, $BASENAME const & src)" >> $FILE
    echo "{" >> $FILE
    echo "    // o << \"ostream operator called\";" >> $FILE
    echo "    return o;" >> $FILE
    echo "}" >> $FILE
    echo "" >> $FILE
    echo -e "\033[32m$FILE created!\033[0m"
done

for FILE in ${HPPFILES[@]}; do
    touch $FILE
    BASENAME=$(basename $FILE .hpp)
    echo "#pragma once" >> $FILE
    echo "" >> $FILE
    echo "#include <iostream>" >> $FILE
    echo "" >> $FILE
    echo "class $BASENAME" >> $FILE
    echo "{" >> $FILE
    echo "" >> $FILE
    echo "public:" >> $FILE
    echo "    $BASENAME(void);" >> $FILE
    echo "    $BASENAME($BASENAME const & src);" >> $FILE
    echo "    ~$BASENAME(void);" >> $FILE
    echo "" >> $FILE
    echo "    $BASENAME & operator=($BASENAME const & src);" >> $FILE
    echo "};" >> $FILE
    echo "" >> $FILE
    echo "std::ostream & operator<<(std::ostream & o, $BASENAME const & src);" >> $FILE
    echo "" >> $FILE
    echo -e "\033[32m$FILE created!\033[0m"
done

if [[ $MAKEFILE == 1 ]]; then
    touch Makefile
    echo "NAME = $NAME" >> Makefile
    echo "SRCS = $MAINFILE ${CPPFILES[@]}" >> Makefile
    echo "OBJS = \$(patsubst %.cpp, %.o, \$(SRCS))" >> Makefile
    echo "CPPFLAGS = -std=c++98 -Wall -Wextra -Werror" >> Makefile
    echo "CC = c++" >> Makefile
    echo "" >> Makefile
    echo "all: \$(NAME)" >> Makefile
    echo "" >> Makefile
    echo "\$(NAME): \$(OBJS)" >> Makefile
    echo "	\$(CC) \$(CPPFLAGS) \$(OBJS) -o \$(NAME)" >> Makefile
    echo "" >> Makefile
    if [[ $SUBDIRS == "y" ]]; then
        echo "$OBJDIR:" >> Makefile
        echo "	mkdir $OBJDIR" >> Makefile
        echo "" >> Makefile
        echo "$OBJDIR%.o: $SRCDIR%.cpp ${HPPFILES[@]} $OBJDIR" >> Makefile
        echo "	\$(CC) \$(CPPFLAGS) -c $< -I $INCDIR -o \$@" >> Makefile
    else
        echo "%.o: %.cpp ${HPPFILES[@]}" >> Makefile
        echo "	\$(CC) \$(CPPFLAGS) -c $< -o \$@" >> Makefile
    fi
    echo "" >> Makefile
    echo "clean:" >> Makefile
    echo "	rm -f \$(OBJS)" >> Makefile
    echo "" >> Makefile
    echo "fclean: clean" >> Makefile
    echo "	rm -f \$(NAME)" >> Makefile
    echo "" >> Makefile
    echo "re: fclean all" >> Makefile
    echo "" >> Makefile
    echo ".PHONY: all clean fclean re" >> Makefile
    echo "" >> Makefile
    echo -e "\033[32mMakefile created!\033[0m"
fi

echo "Done!"