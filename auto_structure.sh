#!/bin/bash

if [ -z "$1" ]
then
	echo "usage : $0 dirName"
else
	mkdir $1
	cd $1
	touch $1.c

#makefile
	echo "all: $1Test" > makefile
	echo -e "\n$1Test: $1.c $1Test.c" >> makefile
	echo "	gcc $1Test.c -o $1Test" >> makefile
	echo -e "\nclean:"	>> makefile
	echo "	rm $1Test" >> makefile

#Test file
	echo "#include <stdio.h>" > $1Test.c
	echo -e "#include \"$1.c\"" >> $1Test.c
	echo -e "\nint main(int argc, char *argv[]){\n\n}" >> $1Test.c
fi
