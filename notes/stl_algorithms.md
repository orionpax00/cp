# Top Use Case Stl Algorithms
Link of video discription: [105 STL Algorithms in less Than an Hour]()

### Heap
* Heapify an array, cpp make_heap() function create an array representation of max heap. Stl also provide way to add and delete in to the heap.
  ```c
  make_heap();

  make_heap(vec.begin(), vec.end()); //create 
  pop_heap(vec.begin(), vec.end()); //max element out
  push_heap(vec.begin(), vec.end()); //random element in
  ```


### Sorting
* there are various sorting stategies available in cpp stl

  * sort(): sort the complete array
    ```c
    sort(vec.begin(), vec.end(), comp);
    ```
  * partial_sort(): sort segement of an array
    ```c
    partial_sort(vec.begin(), vec.begin()+5, vec.end(), comp)
    ```
  * nth_element: put the element at the sort location like sorted pivot in quick sort
    ```c
    nth_element(vec.begin(), vec.begin()+2, vec.end(), comp)
    ```
  * sort_heap()
  * implace_merge()


### Combinotorics
  * rotate()
  * shuffle()
  * next_permutation()
  * perv_permutation(): lexographically just smallest permutation
    ```c
    prev_permutation(vec.begin(), vec.end())
    ```
  * reverse(): 
    ```c
    reverse(vec.begin(), vec.end())
    ```





