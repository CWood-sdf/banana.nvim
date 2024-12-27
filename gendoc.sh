#!/bin/bash

cd gendoc

echo "Making temp dir"
mkdir temp

echo "Cloning wiki and panvimdoc"
git clone https://github.com/CWood-sdf/banana.nvim.wiki wiki
git clone https://github.com/kdheepak/panvimdoc

echo "running ./doc.sh"
./doc.sh

echo "cleanup"
rm wiki temp panvimdoc -rf

cd ..

echo "moving doc to here"
rm doc -rf
mv gendoc/doc doc

echo "generating helptags"
vim -c "helpt doc" -c q

