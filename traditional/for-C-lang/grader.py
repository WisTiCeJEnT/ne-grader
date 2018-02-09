import sys
import os
detail = False
keep = False
if len(sys.argv)==3:
    if sys.argv[1]=="-d":
        detail = True
        f = sys.argv[2]
    elif sys.argv[1]=="-k":
        keep = True
        f = sys.argv[2]
    else:
        f = sys.argv[2]
else:
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
    if detail:
        print("True answer : Your answer : Result")
for i in range(1,numOfTestCase+1):
    sol = open(f"testcase/{f}/{i}.sol").read()
    ans = open(f"{f}/{i}.ans").read()
    if detail:
        print(sol,":",ans,end=" : ")
        if sol==ans:
            print("P")
            score += 1
        else:
            print("-")
    else:
        if sol==ans:
            print("P",end='')
            score += 1
        else:
            print("-",end='')
print(f"\nScore = {score}/{numOfTestCase}")
if not keep:
    os.system(f"rm -r {f}/")
