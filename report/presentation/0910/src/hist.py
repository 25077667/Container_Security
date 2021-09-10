#!/usr/bin/python3
import matplotlib.pyplot as plt 

FILE = "./all_func_called"

def draw(table : dict) -> None:
    plt.bar(table.keys(), table.values(), color='b')
    plt.xticks(rotation=75)
    plt.subplots_adjust(bottom=0.3)
    plt.show()

def read_file(filename : str) -> dict:
    f = open(filename, "r")
    table = dict()
    for line in f:
        key, val = line.split()
        table[key[1:-1]] = int(val)
    return table

def main() -> None:
    called_table = read_file(FILE)
    draw(called_table)

if __name__ == '__main__':
    main()