#!/bin/bash

echo "This is the self test script in contaiiner!"
echo "Support bash cat echo ls rm hostname tree, 7 commands."

echo "$SHELL\n$PATH"
echo $0

echo "-----------FILE: $0 ------------"
cat -n $0
echo "--------------------------------------"

echo $(hostname) > 天竺鼠車車
cat 天竺鼠車車
rm 天竺鼠車車
ls
tree
