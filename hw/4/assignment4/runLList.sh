#!/bin/bash

for i in `ls -v llist_testcases/input*.txt`; do 
    echo $i;
    ./llist < "$i" | md5sum;
done
