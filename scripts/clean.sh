#!/bin/bash

DIRNAME=$(dirname $0)
cd $DIRNAME/..

echo "Removing all files from $(pwd)/data"
rm data/*