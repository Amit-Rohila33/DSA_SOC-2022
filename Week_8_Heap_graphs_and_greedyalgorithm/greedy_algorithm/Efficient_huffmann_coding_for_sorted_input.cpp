// In the previous Huffman code problem, the frequency was not sorted. If the frequency list is given in sorted order, the task of assigning code is being more efficient.

// In this problem, we will use two empty queues. Then create a leaf node for each unique character and insert it into the queue in increasing order of frequency.

// In this approach, the complexity of the algorithm is O(n).


// Ans:- The code for the above question is as follows:-


#include<iostream>
#include<queue>
using namespace std;

struct node {
   char data;
   int freq;
   node *child0, *child1;
};

node *getNode(char d, int f) {
   node *newNode = new node;
   newNode->data = d;
   newNode->freq = f;
   newNode->child0 = NULL;
   newNode->child1 = NULL;
   return newNode;
}

node *findMinNode(queue<node*>&q1, queue<node*>&q2) {
   node *minNode;
   if(q1.empty()) { //if first queue is empty, delete and return node from second queue
      minNode = q2.front();
      q2.pop();
      return minNode;
   }

   if(q2.empty()) { //if second queue is empty, delete and return node from first queue
      minNode = q1.front();
      q1.pop();
      return minNode;
   }

   if((q1.front()->freq) < (q2.front()->freq)) { //find smaller from two queues
      minNode = q1.front();
      q1.pop();
      return minNode;
   }else {
      minNode = q2.front();
      q2.pop();
      return minNode;
   }
}

node *huffmanTree(char data[], int frequency[], int n) {
   node *c0, *c1, *par;
   node *newNode;
   queue<node*> qu1, qu2;

   for(int i = 0; i<n; i++) { //add all node to queue 1
      newNode = getNode(data[i], frequency[i]);
      qu1.push(newNode);
   }

   while(!(qu1.empty() && (qu2.size() == 1))) {
      c0 = findMinNode(qu1, qu2); //find two minimum as two child
      c1 = findMinNode(qu1, qu2);
      node *newNode = getNode('#', c0->freq+c1->freq);

      //intermediate node holds special character
      par = newNode;
      par->child0 = c0;
      par->child1 = c1;
      qu2.push(par); //add sub tree into queue 2
   }

   node *retNode = qu2.front();
   qu2.pop();
   return retNode;
}

void getCodes(node *rootNode, int array[], int n) {  //array to store the code
   if(rootNode->child0 != NULL) {
      array[n] = 0;
      getCodes(rootNode->child0, array, n+1);
   }

   if(rootNode->child1 != NULL) {
      array[n] = 1;
      getCodes(rootNode->child1, array, n+1);
   }

   if(rootNode->child0 == NULL && rootNode->child1 == NULL) {  // when root is leaf node
      cout << rootNode->data << ": ";

      for(int i = 0; i<n; i++)
         cout << array[i];
      cout << endl;
   }
}

void huffmanCodes(char data[], int frequency[], int n) {
   node *rootNode = huffmanTree(data, frequency, n);
   int array[50], top = 0;
   getCodes(rootNode, array, top);
}

int main() {
   char data[] = {'L', 'K', 'X', 'C', 'E', 'B', 'A', 'F'};
   int frequency[] = {1, 1, 2, 2, 2, 2, 3, 4};
   int n = sizeof(data)/sizeof(data[0]);
   huffmanCodes(data, frequency, n);
}