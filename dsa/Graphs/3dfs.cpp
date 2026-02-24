//DFS - Depth First Search, takes O(n) analytically
//it is the pre order traversal of tree
//it uses stack
//visited and explored the vertices
/*steps 
- start with any vertex
- visit the vertex and mark it as visited
- explore the one of the child and suspend other exploration and put the vertex to stack so that we can explore it later
- pop the vertex from stack and visit one of its neighbours and suspend exploration of current vertex and push it to stack
- repeat until stack is empty

eg:
    1---2                                          1
    | \ |                                         /
    |  \|                                        2
    4---3      ---dfs spanning tree--->         /                  
     \ /                                       3 --- 1
      5                                       / 
     / \                                     5
    6   7                                  / | \ 
                                          7  6  4 --- 3 and 1

    V 1                St            1 is visited now explore 1 
    V 1 2              St 1          2 is visited now explore 2 and suspend exploring 1 by adding it to stack
    V 1 2 3            St 1 2        3 is visited now explore 3 and suspend exploring 2 by adding it to stack
    V 1 2 3 5          St 1 2 3      5 is visited now explore 5 and suspend exploring 3 by adding it to stack
    V 1 2 3 5 7        St 1 2 3 5    7 is visited now explore 7 and suspend exploring 5 by adding it to stack
    V 1 2 3 5 7        St 1 2 3      7 is explored now pop 5 from stack and explore it 
    V 1 2 3 5 7 6      St 1 2 3 5    6 is visited now explore 6 and suspend exploring 5 by adding it to stack
    V 1 2 3 5 7 6      St 1 2 3      6 is explored now pop 5 from stack and explore it
    V 1 2 3 5 7 6 4    St 1 2 3 5    4 is visited now explore 4 and suspend exploring 5 by adding it to stack
    V 1 2 3 5 7 6 4    St 1 2 3      from 4 we can go to 1,3 which is already visited, 4 is explored now pop 5 from stack and explore it
    V 1 2 3 5 7 6 4    St 1 2        from 5 we can go to 3,4,6,7 which is already visited, 5 is explored now pop 3 from stack and explore it
    V 1 2 3 5 7 6 4    St 1          from 3 we can go to 1,2,4 which is already visited, 3 is explored now pop 2 from stack and explore it
    V 1 2 3 5 7 6 4    St            from 2 we can go to 1,3 which is already visited, 2 is explored now pop 1 from stack and explore it
    V 1 2 3 5 7 6 4    St            from 1 we can go to 2,3,4 which is already visited, 1 is explored now, and stack is empty stop it
    
    dfs can have many results not just one
    we can visit vertices in any order and can take any vertex as starting vertex
    
*/

#include <iostream>
#include <stack>
using namespace std;

void dfs(int A[][7], int u, int n){
    static int visited[10] = {0}; //static is used to maintain the value of visited array in every recursive call
    if(visited[u]==0){
        cout<<u<<" ";
        visited[u] = 1;
        for(int v = 1; v < n; v++){
            if(A[u][v]==1 && visited[v]==0){
                dfs(A, v, n);
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
    dfs(G, 1, 7);
    return 0; 
}
