#!/bin/bash

support_list=("bash" "cat" "echo" "hostname" "ls" "rm" "tree")
rootfs=$1
root_dirs=("bin" "dev" "etc" "home" "lib" "lib64" "mnt" "opt" "proc" "root" "run" "sbin" "sys" "tmp" "usr" "var")

#----------clean root fs----------
rm -rf $rootfs

#----------create root fs----------
echo "Creating rootfs"
mkdir $rootfs
for i in ${root_dirs[@]}; do
    mkdir $rootfs/$i
done
echo

#----------Copy commands----------
for app in ${support_list[@]}; do
    echo "Copying $app from $(which $app) to $rootfs/usr/bin/"
    cp $(which $app) $rootfs/bin/
done
echo

libs=()
#----------Copy lib----------
for app in ${support_list[@]}; do
    echo "Add $(which $app | xargs ldd | grep '\(\(\/usr\)\?\/lib[^\ ]\+\)' -o | tr '\n' ' ')for $app"
    for l in $(which $app | xargs ldd | grep '\(\(\/usr\)\?\/lib[^\ ]\+\)' -o | tr '\n' ' '); do
        if [[ ! " ${libs[@]} " =~ " $l " ]]; then
            libs+=("$l")
        fi
    done
done
echo
echo ${libs[@]}

for l in ${libs[@]}; do
    echo "Copying lib"
    cp -f $l "$rootfs$l"
    if [[ $? != 0 ]]; then
        mkdir -p "$rootfs$l" # the end of $l is file name, not the dir name
        rmdir "$rootfs$l"
        cp -f $l "$rootfs$l"
    fi
done

#----------Copy test---------
cp test.sh $rootfs
