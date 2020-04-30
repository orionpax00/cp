import networkx as nx
import matplotlib.pyplot as plt

x = nx.fast_gnp_random_graph(10, 0.3)
#uncomment if you wanna visualize
# nx.draw(x)
# plt.draw()
# plt.show()
nx.write_edgelist(x, "../input.txt", data=False)

count = 0
lines = []

with open('../input.txt', 'r')  as inputFile:
    lines = inputFile.readlines()
    count = len(lines)

with open('../input.txt', 'w')  as inputFile:
    inputFile.write(str(count)+"\n")
    [inputFile.write(line) for line in lines]