#!/bin/bash

DIRNAME=$(dirname $0)
cd $DIRNAME

if [ $# -le 0 ]; then
    echo "usage: $0 <problem-letter>"
    exit 1
else
    unzip ~/Downloads/samples-$1.zip -d ../data/
fi