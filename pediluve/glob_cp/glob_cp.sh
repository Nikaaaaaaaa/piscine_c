#!/bin/sh

extensions=""

for ext in "$@"; do
    extensions="$extensions$ext"
done

mv *."[!$extensions]" trash
