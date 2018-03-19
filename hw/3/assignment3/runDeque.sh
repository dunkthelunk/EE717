#!/bin/bash

for i in `ls -v deque_testcases/input*.txt`; do 
    echo $i;
    ./deque < "$i" | md5sum;
done
