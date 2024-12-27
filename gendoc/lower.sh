#!/bin/bash

echo "Lowercasing $1"

new=$(echo $1 | sed "s/^[A-Z].*/\L&/" | sed "s/\.md//")

mv $1 $new
