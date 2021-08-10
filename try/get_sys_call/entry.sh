#!/bin/sh

/tracee/tracee-ebpf -t c --output out-file:/mnt/out err-file:/mnt/err &
sleep 5
python /app/hello.py

pkill trace
