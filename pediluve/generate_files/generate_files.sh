#!/bin/sh

filename=default
number=1
extension=txt

while [ "$#" -gt 0 ]; do
    if [ "$1" = "-f" ] || [ "$1" = "--filename" ]; then
        if [ "$#" -lt 2 ]; then
            exit 1
        fi
        filename="$2"
        shift 2
    elif [ "$1" = "-n" ] || [ "$1" = "--number" ]; then
        if [ "$#" -lt 2 ]; then
            exit 1
        fi
        number="$2"
        shift 2
    elif [ "$1" = "-e" ] || [ "$1" = "--extension" ]; then
        if [ "$#" -lt 2 ]; then
            exit 1
        fi
        extension="$2"
        shift 2
    else
        exit 1
    fi
done

for i in $(seq 1 "$number"); do
    touch "$filename-$i.$extension"
done
