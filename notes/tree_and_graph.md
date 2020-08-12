---
title: "Habits"
author: John Doe

html:
  offline: false
  path: t.html

export_on_save:
  html: true

print_background: true
---

# Graph and Tree Algorithms

Graph algorithms with potiential implementation overview and Application.[[link]](https://www.geeksforgeeks.org/graph-data-structure-and-algorithms/)

## Strategies and methods

* BFS
* DFS
  * Coloring method
  * Low Link method(bridge detection)
* Topological Sort
* Tree Flattening 
  * Eulerian Path
* DSU
* Heavy-Light Decomposition
* Binary lifting(similiar to sparse table)

## Benchmark Problems

* Paths
  * Shortest Path
    * Single Source Shortest Path
    * All Source Shortest Path
  * Longest Path

* Connectivity
  * Find Connected Components.**[BFS, DFS, DSU]**
  * Lowest common Ancestor. **[(Euler Tour, RMQ {optimization using Farach-Colton and Bender Algorithm}), Binary lIfting, (DFS+DSU{Tarjan's Algo})]**
  * Minimum spaning Tree. **[DSU]**
  * Biconectivity
  * Cycle and Negative cycle detection
  * Strongly Connected components
  * Bridges and Articulation point.
    * Offline **[DFS(low-link method)]**
    * Online **[DSU]**

* Flow Network

## Derived Problems

* Shortest path from a source to destination in a unweighted graph. **{shortest path}[BFS]**
* Finding a solution to a problem or a game with the least number of moves. **{shortest path}[BFS]**
* Finding the shortest cycle in a directed unweighted graph. **{Cycle detection}[BFS]**
* Find any path in the graph from source vertex u to all vertices. **{path finding}[DFS]**
* Check if a vertex in a tree is an ancestor of some other vertex. **{path}[DFS]**

# Important Points

* Problems in Tree are very often to applying some sort of dfs or dynamic programming
* Terminologies: Root, Grand parent, parent, child, siblings, leaf, Ancestor, decendent, cousion, depth, height, diameter, etc.
* Types of Tree: Binary Tree, Binary Search Tree, Red Black Tree, Self Balanced Tree, B Tree, B+ Tree, etc.
* Full Binary Tree, Complete binary tree, Perfect Binary Tree, Balanced Binary Search Tree,
* Problems of tree are very open to dfs (using dp).
* Tree Traversal
  * BFS or (Level order traversal)
  * DFS
    * Inorder (left->root->right)
    * Preorder (root->left->right)
    * Post order (left->right->root)

## Optimal Binary Search Tree

* For n keys (i.e n nodes) there are $\frac{2n_{C_n}}{n+1}$ binary trees are possible
* Tree for which the no. of comparisions are minimum is Balanced binary Search Tree.
* But when the frequencies of keys are given then the balanced binary search tree will not be an optimal search tree.
* So basically optimal binary search tree is more a problem then the concept, that is solved using dynamic programming.


## Flattening of Tree (Eulerian Path) and Heavy Light Decomposition

* So questions about point updates and path sum queries can be handled by flattening the tree, rudimentary heavy-light decomposition, etc
