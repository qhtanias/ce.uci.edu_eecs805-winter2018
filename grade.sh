#!/bin/bash

#set -o errexit # -e
#set -o xtrace # -x
#set -o verbose #

firstPass=${1:-0}

if [ -d submissions ]
then
    rm -rf submissions
fi

mkdir submissions
cd submissions
cp ~/Downloads/submissions.zip .
unzip submissions.zip

for file in `ls *.gz`
do
    filename=$(basename "$file")
    dir="${filename%%.*}"

    mkdir $dir
    mv $file $dir
    cd $dir
    tar -xvzf $file

    cd ..
done

if [ "$firstPass" = "1" ]
then
    exit 1
fi

for homework in `find . -type f`
do
    less $homework
done

for makeFile in `find . -name Makefile`
do
    dir=$(dirname "$makeFile")
    cd $dir
    echo $dir
    make
    cd -
done

exit 0
