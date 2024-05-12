#!/bin/bash

DIRNAME=$(dirname $0)
cd $DIRNAME/..

if [ $# -le 2 ]; then
    echo "usage: $0 <contest-number> <problem-letter> <problem-name>"
    exit 1
else
    NAME="contest$1-$2-$3"
    zip solved_problems/${NAME}_samples.zip data/*
    cp main.cpp solved_problems/$NAME.cpp
fi