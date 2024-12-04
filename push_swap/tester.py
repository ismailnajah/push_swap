#!/usr/bin/env python3
import itertools
import subprocess


def main():
    errors = list()
    nb_inst = list()
    for p in itertools.permutations([12, -3, 10, 5, 0, 4]):
        arg = ' '.join(map(str,p))
        command = f"./push_swap {arg}"
        inst = subprocess.run(command, shell=True, capture_output=True,text=True)
        inst = inst.stdout.strip().split('\n')
        nb_inst.append(len(inst))
        command = f"./push_swap {arg} | ../checker_linux {arg}"
        output = subprocess.run(command, shell=True, capture_output=True,text=True)
        errors.append(0 if output.stdout.strip() == "OK" else 1)
    print("Total errors: ", sum(errors))
    print("Max instructions: ", max(nb_inst))

if __name__ == "__main__":
    main()
