#!/bin/sh

/tracee/tracee-ebpf -t c --output json 1>/mnt/out 2>/mnt/err &
sleep 5
python /app/hello.py

pkill trace
