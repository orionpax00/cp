## Tree Data Structures 
### Square Root Decompostion

* It is a method (or a data structure) that allow range query opertion too be answer in O(sqrt(N)) time complexity.
* In this method we divide an array into sqrt(N) chucks having sqrt(N) items each. 
* And type of query is pre computed for each of these chunks.
* Answer will be the Union of answers from the chunks.
* ***MO's Algrithm:*** Suppose range query to find the mode, in this case the merging step will be a bit problematic with only a single precompute lookup table. 
  * Here, MO's algorithm helps which can answer queries like above in O((N+Q)sqrt(N)) time complexity where Q is the number of queries.
  * The idea is to answer the queries in a special order based on the indices. We will first answer all queries which have the left index in block 0, then answer all queries which have left index in block 1 and so on. And also we will have to answer the queries of a block is a special order, namely sorted by the right index of the queries.

  //TODO: complete MO's Algorithms

### Segment Tree

* Leaf node are just the array elements
* 