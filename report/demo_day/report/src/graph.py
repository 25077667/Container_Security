#!/usr/bin/python3

import matplotlib.pyplot as plt


def read_local_data(filename: str) -> tuple():
    lc = []
    lvm = []
    with open(filename) as f:
        for line in f:
            cont, vm = line.split(" ")
            lc.append(float(cont))
            lvm.append(float(vm[:-1]))
    return lc, lvm


def draw(lc: list, lvm: list) -> None:
    plt.plot([*range(1, len(lc)+1)], lc, 'b*', label='Alpine container in archlinux')
    plt.plot([*range(1, len(lvm)+1)], lvm, 'r+',
             label='Ubuntu 20.04 in QEMU/KVM')
    plt.legend()
    plt.xlabel('the number of concurrent processes sending 100 requests')
    plt.ylabel('time cost (ms)')
    plt.show()


def main() -> None:
    # Read data
    lc, lvm = read_local_data("./data")
    # Draw
    draw(lc, lvm)


if __name__ == '__main__':
    main()
