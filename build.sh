#!/bin/bash

cd tree-sitter-ncss/src
bash ./build
mv ./ncssParser2.so ../../bin/ncssParser2.so
