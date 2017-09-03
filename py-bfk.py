#! /usr/bin/env python

import sys

# initialize dc array with 30000 "0"s
data_array = [0]*30000

# make a list of commands
program = input().strip()

# program counter
pc = 0

# data counter
dc = 0

# stack for storing loop counter
loop = []

# run forever
# we can have potential infinite loops
while (1):
    try:
        cmd = program[pc]
    except IndexError:
        # we have reached the end
        break

    if cmd == '+':
        data_array[dc] += 1
    elif cmd == '-':
        data_array[dc] -= 1
    elif cmd == '>':
        dc += 1
    elif cmd == '<':
        dc -= 1
        if dc < 0:
            print ("whatttt")
            print (loop)
            print (pc)
            sys.exit()
    elif cmd == '.':
        try:
            asc = chr(data_array[dc])
        except ValueError:
            print(dc)
            print(pc)
            print(data_array[dc])
        print (asc, end='', flush=True)
    elif cmd == ',':
        ch = input().strip()
        data_array[dc] = ord(ch)
    elif cmd == '[':
        if data_array[dc] == 0:
            while (program[pc] != ']'):
                pc += 1
            continue
        else:
            # store the loop program counter
            # maintain a stack for nested loops
            loop.append(pc)
    if cmd == ']':
        if data_array[dc] != 0:
            pc = loop.pop()
            continue
        loop.pop()

    # move to next command
    pc += 1

# a new line in the end
print()

