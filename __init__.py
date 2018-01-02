import sys
import os
import random
name = "final_data"

def convert_bits(numList):
    s= map(str,numList)
    s =''.join(s)
#    s = int(s)
    return s


def ram_num():
    n = random.sample(range(10),5)
    l = random.sample(range(10),4)
    m = random.sample(range(10),3)
    k = random.randint(1,100)
    if (k % 53) == 3:
        return convert_bits(n) + '248'
    elif (k % 53) ==5:
        return '55899892'
    elif (k % 53) == 7:
        return convert_bits(m) + '20791'
    elif (k % 53) == 8:
        return convert_bits(l) + '9892'
    elif (k % 53) == 41:
        return '37266877' #200w
    elif (k % 53) == 0:
        return '26638985' #1000w
    else:
        return convert_bits(n) + convert_bits(m)


def main():
    file_W = open(name,'w')
    for i in range(200):
        file_W.writelines(ram_num()+'\n')
    file_W.close()
if __name__ == "__main__":
    main()
