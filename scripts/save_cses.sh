#!/bin/bash

# SAVE_FOLDER="searching_and_sorting"
# SAVE_FOLDER="graph"
SAVE_FOLDER="mathematics"
FOLDER_PATH="solved_problems/CSES/${SAVE_FOLDER}"

DIRNAME=$(dirname $0)
cd $DIRNAME/..

if [ ! -d "$FOLDER_PATH" ]; then
    mkdir -p $FOLDER_PATH
    echo "Directory created: $FOLDER_PATH"
fi

if [ $# -le 0 ]; then
    echo "usage: $0 <problem-name>"
    exit 1
else
    cp main.cpp solved_problems/CSES/${SAVE_FOLDER}/${1}.cpp
fi