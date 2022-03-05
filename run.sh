#!/bin/bash

if [ -z $1 ]; then
    echo "Please supply the number of the problem you want to run. (e.g. './run.sh 4')"
    exit 1
fi

if [ ! -d "build" ]; then
    mkdir build
fi

g++ -Wall --pedantic-errors -std=c++20 -O2 -o build/$1 src/$1.cpp

if [ $? == 0 ]; then
    ./build/$1
fi
