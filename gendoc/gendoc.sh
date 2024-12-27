#!/bin/bash

newname=$(echo $1)

echo "Documenting $newname"

echo "nvimdoc/panvimdoc.sh --input-file $1 --project-name banana-$1 --scripts-dir ../panvimdoc/scripts"

OLDGH=$GITHUB_ACTIONS
GITHUB_ACTIONS=
../panvimdoc/panvimdoc.sh --input-file $1 --project-name banana-$1 || echo "Failed"
GITHUB_ACTIONS=$OLDGH

