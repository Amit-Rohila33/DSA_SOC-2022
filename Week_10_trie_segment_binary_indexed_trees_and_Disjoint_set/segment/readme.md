<!-- About Segment tree -->

Let us consider the following problem to understand Segment Trees.
We have an array arr[0 . . . n-1]. We should be able to 

1). Find the sum of elements from index l to r where 0 <= l <= r <= n-1
2). Change value of a specified element of the array to a new value x. We need to do arr[i] = x where 0 <= i <= n-1.

<!-- Solutions -->


A simple solution is to run a loop from l to r and calculate the sum of elements in the given range. To update a value, simply do arr[i] = x. The first operation takes O(n) time and the second operation takes 
O(1) time. 


Another solution is to create another array and store sum from start to i at the ith index in this array. The sum of a given range can now be calculated in O(1) time, but update operation takes O(n) time now. This works well if the number of query operations is large and very few updates.
What if the number of query and updates are equal? Can we perform both the operations in O(log n) time once given the array? We can use a Segment Tree to do both operations in O(Logn) time.


<!-- Representation -->


Representation of Segment trees:- 

1). Leaf Nodes are the elements of the input array. 
2). Each internal node represents some merging of the leaf nodes. The merging may be different for different problems. For this problem, merging is sum of leaves under a node.
An array representation of tree is used to represent Segment Trees. For each node at index i, the left child is at index 2*i+1, right child at 2*i+2 and the parent is at  ⌊(i – 1) / 2⌋.



<!-- Construction and updation of a segmented tree using python -->


The code for the contruction and updation for the segmented tree is given in <segment.cpp>



