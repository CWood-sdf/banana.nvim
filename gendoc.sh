#!/bin/bash

cd gendoc

echo "Making temp dir"
mkdir temp

echo "Cloning wiki and panvimdoc"
git clone https://github.com/CWood-sdf/banana.nvim.wiki wiki

cd wiki

echo "running ./doc.sh"
# the shell files for this are in https://github.com/CWood-sdf/banana.nvim.wiki
./doc.sh

cd ..

echo "moving doc/ to here"
mv wiki/doc doc

echo "removing wiki/"
rm wiki -rf

echo "generating helptags"
vim -c "helpt doc" -c q
