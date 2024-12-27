#!/bin/bash

echo "Removing table of contents in $1"

cat $1 | sed "s/^##\s*TOC\s*$//" | sed "s/^- \[.*\](#\w*)$//" | sed '/^$/N;/^\n$/D' > $1-new

rm $1

mv $1-new $1
