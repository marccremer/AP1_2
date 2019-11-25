#!/bin/sh
for file in ../src/*.c
do
	gcc -lm -o "$(basename "$file" .c)" "$file"  
  done
