import sys
import os
detail = False
keep = False
exception = ["\n"]
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
    while sol[-1] in exception:
        sol = sol[0:-1]
    while ans[-1] in exception:
        ans = ans[0:-1]
    sol = sol.split('\n')
    ans = ans.split('\n')
    for j in range(len(sol)):
        while sol[j][-1] == ' ':
            sol[j] = sol[j][0:-1]
    for j in range(len(ans)):
        while ans[j][-1] == ' ':
            ans[j] = ans[j][0:-1]
    if detail:
        if len(sol) == 1 and len(ans)==1:
            print(f"{sol[0]:12}: {ans[0]:12}",end=": ")
        else:
            for j in range(min(len(sol),len(ans))):
                print(f"{sol[j]:12}| {ans[j]:12}")
            print(" "*26,end=": ")
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
