#!/usr/bin/env python3

import sys
import random 

def problem1() : 
    n1 = int(input("Enter number of nodes in T1: "))
    n2 = int(input("Enter number of nodes in T2: "))
    f = open("input.txt","w+")
    for i in range(n1):
        f.write("1 " + str(random.randint(1,100000)) + "\n")
    f.write("2\n")
    for i in range(n2):
        f.write("1 " + str(random.randint(100000,1000000)) + "\n")
    f.write("2\n")
    f.close()


def problem2() : 
    n1 = int(input("Enter number of nodes in T1: "))
    n2 = int(input("Enter number of nodes in T2: "))
    


if __name__ == "__main__" : 

    if(len(sys.argv) != 2):
        print("Usage: $", sys.argv[0], " <problem1 / problem2>")
        sys.exit()

    if sys.argv[1] == "problem1" : 
        problem1()
    
    elif sys.argv[1] == "problem2": 
        problem2()