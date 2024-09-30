#!/bin/bash

SAVE_FOLDER="searching_and_sorting"

DIRNAME=$(dirname $0)
cd $DIRNAME/..

if [ $# -le 0 ]; then
    echo "usage: $0 <problem-name>"
    exit 1
else
    cp main.cpp solved_problems/CSES/${SAVE_FOLDER}/${1}.cpp
fi