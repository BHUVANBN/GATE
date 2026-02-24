/*
Traversal of graph
BFS - Breadth First Search, takes O(n) analytically
    goal is to traverse all vertices of graph
    graph without any closed edges (cycles) is tree
    bfs is the level order traversal of converted tree
    
    1---2                           1
    | \ |                         / | \
    |  \|      ---tree-->        2--3--4                --level order---> 1 2 3 4 5 6 7
    4---3                           |
     \ /                            5 --- 4
      5                            / \
     / \                          6   7
    6   7                      bfs spanning tree                       
    
    the dotted edges in the tree which makes tree cyclic - cross edges
    the solid edges in the tree which makes tree acyclic - tree edges
    
    bfs can have many results not just one
    we can construct tree in any order and can take root as any vertex

    the rule of bfs is select a vertex and explore all its neighbours in any order

    it consists of visiting and exploring
    uses queue
    visit a vertex and add to queue
    get the first element from queue and visit all its neighbours and add to queue
    repeat until queue is empty
    eg: Q 1             take out 1 and visit 2, 3, 4 and add them to queue 
        Q 2 3 4         take out 2 and visit 1 and 3 which is already visited so no need to add them to queue
        Q 3 4           take out 3 and visit 4 and 5, 4 is already visited ao add 5 to queue
        Q 4 5           take out 4 and visit 3 and 5, 3 and 5 are already visited ao no need to add them to queue
        Q 5             take out 5 and visit 6 and 7, and add them to queue 
        Q 6 7           take out 6 and nothing to explore
        Q 7             take out 7 and nothing to explore   

*/
#include <iostream>
#include <queue>
using namespace std;

void bfs(int A[][7], int i, int n) {
    queue<int> q;
    int visited[10] = {0};

    cout << i << " "; //starting vertex v1
    visited[i] = 1; //mark v1 as visited
    q.push(i); //push v1 to queue

    while(!q.empty()){  //O(n^2) because of adjacency matrix
        int u = q.front(); //get the first element from queue 
        q.pop(); //donot return any value it just removes the element from queue 
        for(int v = 1; v < n; v++){
            if(A[u][v]==1 && visited[v]==0){  //has connection(edge) and not visited
                cout << v << " ";
                visited[v] = 1;
                q.push(v);
            }
        }

    }
}
int main(){
    int G[7][7] ={  {0,0,0,0,0,0,0},
                    {0,0,1,1,0,0,0},
                    {0,1,0,0,1,0,0},
                    {0,1,0,0,1,0,0},
                    {0,0,1,1,0,1,1},
                    {0,0,0,0,1,0,0},
                    {0,0,0,0,1,0,0} };  
    bfs(G, 1, 7);
    return 0; 
}