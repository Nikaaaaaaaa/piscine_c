#!/bin/sh

touch ' '
touch '\'
touch '|'
touch '"'
touch "'"
touch '# Exams are fun!'
touch ';`kill -9 0`'
touch -- '--'
touch -- '--$i*'"'"'"\'

chmod 0644 ' '
chmod 0644 '\'
chmod 0644 '|'
chmod 0644 '"'
chmod 0644 "'"
chmod 0644 '# Exams are fun!'
chmod 0644 ';`kill -9 0`'
chmod 0644 -- '--'
chmod 0644 -- '--$i*'"'"'"\'

dir=1
for i in $(seq 2 50); do
    dir="$dir/$i"
done
mkdir -p "$dir"
touch "$dir/farfaraway"
chmod 0644 "$dir/farfaraway"
