import sys
import os
f = sys.argv[1]
f = f[0:-2]
os.system(f"mkdir {f}/")
os.system(f"gcc {f}.c -o {f}.out")
os.system(f"mv {f}.out {f}/")
config = open(f"gcf/{f}.gcf",'r').read().split()
numOfTestCase = int(config[0])
score = 0
for i in range(1,numOfTestCase+1):
    os.system(f"{f}/{f}.out < testcase/{f}/{i}.in > {f}/{i}.ans")
for i in range(1,numOfTestCase+1):
    sol = open(f"testcase/{f}/{i}.sol").read()
    ans = open(f"{f}/{i}.ans").read()
    if sol==ans:
        print("P",end='')
        score += 1
    else:
        print("-",end='')
print(f"\nScore = {score}/{numOfTestCase}")
os.system(f"rm -r {f}/")
