#!/bin/bash

newname=$(echo $1)

echo "Documenting $newname"

echo "nvimdoc/panvimdoc.sh --input-file $1 --project-name banana-$1 --scripts-dir ../panvimdoc/scripts"

../panvimdoc/panvimdoc.sh --input-file $1 --project-name banana-$1 --scripts-dir ../panvimdoc/scripts || echo "Failed"

