#!/bin/bash
mkdir executables
executables="`pwd`/executables"
for source in $(ls *.c); do
	executable=`ls $source | cut -d "." -f 1`
	clang -Wall $source -o $executables/$executable
done