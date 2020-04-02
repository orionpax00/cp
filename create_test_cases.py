import os

testcase = []

for i in range(1,2501,1):
  testcase.append(str(i))
  testcase.append(str(i))

print(len(testcase))

with open('./input.txt', 'w') as inputfile:
  inputfile.write("1\n")
  inputfile.write(" ".join(testcase))

