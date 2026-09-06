#!/bin/sh

if [ "$#" -eq 0 ]; then
    extension=txt
else
    extension="$1"
fi

if [ -e *."$extension" ]; then
    rm *."$extension"
else
    exit 1
fi
