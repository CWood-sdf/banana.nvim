#!/bin/bash

mkdir temp

echo "sourcing files.sh"
source wiki/files.sh

IFS=,

for item in $DOC_FILES ;
do
    cp wiki/$item.md temp/$item.md
done

cd temp
mkdir doc

echo "lowercasing files"
find * -type f -exec ../lower.sh {} \;

echo "removing table of contents"
find * -type f -exec ../rmtoc.sh {} \;

echo "generating documentation"
find * -type f -exec ../gendoc.sh {} \;

cd ..
mv temp/doc doc
