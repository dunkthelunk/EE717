#!/bin/bash

for i in `ls -v stack_testcases/input*.txt`; do 
    echo $i;
    ./stack < "$i" | md5sum;
done
