# SortNebula

Heap sort:

 void heapify() 

    To heapify a subtree rooted with node i which is an index in arr[]. n1 is size of heap. Whether the left child or the 
    right child is greater than the root determines largest and recursively calls heapify().

 void h_sort()

   Build heap (rearrange array) and one by one extract an element from heap. 
   Then call max heapify on the reduced heap.

 int main ()

  Accept the mapping. Then find the no of digits of the largest second coordinate. then val = 10**(the number of digits).
  new array will have data as x*val + y and will be sorted by calling the sorting function. The respective index(in second row)
 is also swapped. finally the order of index in sorted array is used to produce the ascending sort of actual array. 
        