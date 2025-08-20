#!/bin/bash

newname=$(echo $1 | sed "s/\.md//")

echo "Documenting $newname"

echo "nvimdoc/panvimdoc.sh --input-file $1 --project-name banana-$newname --scripts-dir ../panvimdoc/scripts"

OLDGH=$GITHUB_ACTIONS
GITHUB_ACTIONS=
../panvimdoc/panvimdoc.sh --input-file $1 --project-name banana-$newname || echo "Failed"
GITHUB_ACTIONS=$OLDGH

