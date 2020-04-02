import os

output = []
answer = []

with open('../output.txt', 'r') as inputfile:
  output = [x.split("\n")[0] for x in inputfile.readlines()]

with open('../answer.txt', 'r') as inputfile:
  answer = [x.split("\n")[0] for x in inputfile.readlines()]

fail=0
print("\n")
if(len(output) != len(answer)): 
  print('\033[91mOutput != Answer \033[0m')
  quit()

for counter, x in enumerate(output):
  if(x != answer[counter]):
    print('\033[91m'+"TESTCASE "+str(counter) + '\033[0m : ' + str(x) +"-->"+str(answer[counter]))
    fail += 1

print("\n\033[95mREPORT--------- \033[0m")
print('\033[92m'+str(counter - fail + 1) + " Passed "+'\033[0m' + '\033[91m'+str(fail) + " Failed "+'\033[0m')