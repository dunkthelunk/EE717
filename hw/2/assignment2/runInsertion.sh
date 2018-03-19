#!/bin/bash

for i in `ls -Sr input*.txt`; do ./insertionSort < "$i" ; done
