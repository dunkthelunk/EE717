#!/bin/bash

for i in `ls -Sr input*.txt`; do ./heapSort < "$i" ; done
