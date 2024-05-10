#!/bin/bash

DIRNAME=$(dirname $0)
cd $DIRNAME

if [ $# -le 0 ]; then
    echo "usage: $0 <path-to-zip-file>"
    exit 1
else
    unzip $1 -d ../data/
fi