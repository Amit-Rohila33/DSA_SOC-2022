// It is similar to the previous algorithm. Here the only difference is, the Graph G(V, E) is represented by an adjacency list.

// Time complexity adjacency list representation is O(E log V).


// Ans:- The code for the above problem is as follows:-


#include<iostream>
#include<list>
#include<set>
using namespace std;

typedef struct nodes {
   int dest;
   int cost;
}node;

class Graph {
   int n;
   list<node> *adjList;
   private:
      void showList(int src, list<node> lt) {
         list<node> :: iterator i;
         node tempNode;

         for(i = lt.begin(); i != lt.end(); i++) {
            tempNode = *i;
            cout << "(" << src << ")---("<<tempNode.dest << "|"<<tempNode.cost<<") ";
         }
         cout << endl;
      }

   public:
      Graph() {
         n = 0;
      }

      Graph(int nodeCount) {
         n = nodeCount;
         adjList = new list<node>[n];
      }

      void addEdge(int source, int dest, int cost) {
         node newNode;
         newNode.dest = dest;
         newNode.cost = cost;
         adjList[source].push_back(newNode);
      }

      void displayEdges() {
         for(int i = 0; i<n; i++) {
            list<node> tempList = adjList[i];
            showList(i, tempList);
         }
      }

      friend Graph primsMST(Graph g, int start);
};

set<int> difference(set<int> first, set<int> second) {
   set<int> :: iterator it;
   set<int> res;

   for(it = first.begin(); it != first.end(); it++) {
      if(second.find(*it) == second.end())
         res.insert(*it);    //add those item which are not in the second list
   }

   return res;    //the set (first-second)
}

Graph primsMST(Graph g, int start) {
   int n = g.n;
   set<int> B, N, diff;
   Graph tree(n);        //make tree with same node as graph
   B.insert(start);     //insert start node in the B set

   for(int u = 0; u<n; u++) {
      N.insert(u); //add all vertices in the N set
   }

   while(B != N) {
      int min = 9999;             //set as infinity
      int v, par;
      diff = difference(N, B);    //find the set N - B

      for(int u = 0; u < n; u++) {
         if(B.find(u) != B.end()) {
            list<node>::iterator it;
            for(it = g.adjList[u].begin(); it != g.adjList[u].end(); it++) {
               if(diff.find(it->dest) != diff.end()) {
                  if(min > it->cost) {
                     min = it->cost;    //update cost
                     par = u;
                     v = it->dest;
                  }
               }
            }
         }
      }

      B.insert(v);
      tree.addEdge(par, v, min);
      tree.addEdge(v, par, min);
   }
   return tree;
}

main() {
   Graph g(7), tree(7);
   g.addEdge(0, 1, 1);
   g.addEdge(0, 2, 3);
   g.addEdge(0, 3, 4);
   g.addEdge(0, 5, 5);
   g.addEdge(1, 0, 1);
   g.addEdge(1, 3, 7);
   g.addEdge(1, 4, 2);
   g.addEdge(2, 0, 3);
   g.addEdge(2, 4, 8);
   g.addEdge(3, 0, 4);
   g.addEdge(3, 1, 7);
   g.addEdge(4, 1, 2);
   g.addEdge(4, 2, 8);
   g.addEdge(4, 5, 2);
   g.addEdge(4, 6, 4);
   g.addEdge(5, 0, 5);
   g.addEdge(5, 4, 2);
   g.addEdge(5, 6, 3);
   g.addEdge(6, 4, 4);
   g.addEdge(6, 5, 3);

   tree = primsMST(g, 0);
   tree.displayEdges();
}