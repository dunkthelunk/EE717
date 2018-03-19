#!/bin/bash

for i in `seq 6 1 20`; do
    echo bst_LCA_testcases/input$i.txt
    ./bst_LCA < bst_LCA_testcases/input"$i".txt | md5sum ;
done
