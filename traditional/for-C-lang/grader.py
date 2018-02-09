import sys
import os
f = sys.argv[1]
f = f[0:-2]
os.system(f"mkdir {f}/")
os.system(f"gcc {f}.c -o {f}.out")
os.system(f"mv {f}.out {f}/")
config = open(f"gcf/{f}.gcf",'r').read()
print(config)
