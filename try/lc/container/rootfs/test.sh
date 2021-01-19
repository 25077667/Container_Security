#!/bin/bash

echo "This is the self test script in contaiiner!"
echo "Support bash cat echo ls rm hostname, 5 commands."

echo $0

echo "-----------FILE: test.sh ------------"
cat -n test.sh
echo "--------------------------------------"

echo $(hostname) >天竺鼠車車
cat 天竺鼠車車
rm 天竺鼠車車
ls
