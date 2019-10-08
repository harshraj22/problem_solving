# For command line argument
from sys import argv

def fact(x):
    return x if x is 1 else x*fact(x-1)
shortFact = lambda x: x if x is 1 else x*shortFact(x-1)

try :
    print(shortFact(int(argv[1])))    
except :
    print("No argument passed")
finally:
    pass
