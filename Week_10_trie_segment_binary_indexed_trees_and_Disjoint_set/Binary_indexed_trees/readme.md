<!-- Binary Indexed Tree or Fenwick Tree -->

<!-- About binary indexed trees -->



Let us consider the following problem to understand Binary Indexed Tree.
We have an array arr[0 . . . n-1]. We would like to 
1). Compute the sum of the first i elements. 
2). Modify the value of a specified element of the array arr[i] = x where 0 <= i <= n-1.


<!-- Solution -->


A simple solution is to run a loop from 0 to i-1 and calculate the sum of the elements. To update a value, simply do arr[i] = x. The first operation takes O(n) time and the second operation takes O(1) time. Another simple solution is to create an extra array and store the sum of the first i-th elements at the i-th index in this new array. The sum of a given range can now be calculated in O(1) time, but the update operation takes O(n) time now. This works well if there are a large number of query operations but a very few number of update operations.



<!-- Construction  -->


getSum(x): Returns the sum of the sub-array arr[0,…,x] 
// Returns the sum of the sub-array arr[0,…,x] using BITree[0..n], which is constructed from arr[0..n-1] 
1) Initialize the output sum as 0, the current index as x+1. 
2) Do following while the current index is greater than 0. 
…a) Add BITree[index] to sum 
…b) Go to the parent of BITree[index]. The parent can be obtained by removing 
the last set bit from the current index, i.e., index = index – (index & (-index)) 
3) Return sum.


<!-- Updation -->


update(x, val): Updates the Binary Indexed Tree (BIT) by performing arr[index] += val 
// Note that the update(x, val) operation will not change arr[]. It only makes changes to BITree[] 
1) Initialize the current index as x+1. 
2) Do the following while the current index is smaller than or equal to n. 
…a) Add the val to BITree[index] 
…b) Go to next element of BITree[index]. The next element can be obtained by incrementing the last set bit of the current index, i.e., index = index + (index & (-index))



<!-- Code -->



The code for this algorithm is written in <BIT.py>


