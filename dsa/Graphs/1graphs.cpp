//Graph is a collection of vertices and edges
//Vertices are connected by edges
//Edges can be directed or undirected
//Edges can have weight

//path - sequence of vertices connected by edges
//cycle - path that starts and ends at same vertex

//parallel edges - multiple edges between same vertices
//self loop - edge between same vertices

//in degree of a vertex - number of edges coming to a vertex
//out degree of a vertex - number of edges going from a vertex

//articulation point - vertex whose removal increases the number of connected components(i.e splits the graph)
//bridge - edge whose removal increases the number of connected components

/*types of graphs - 
    1. Simple graph - no parallel edges and no self loop
    2. Multi graph - parallel edges allowed but no self loop
    3. Pseudo graph - parallel edges and self loop allowed
    4. undirected graph (graph)- edges are undirected , so it is bidirectional and degree of a vertex is number of edges connected to it 
    5. directed graph (di-graph)- edges are directed
    6. weighted graph - edges have weight
    7. unweighted graph - edges have no weight
    8. non connected graph - graph is not connected i.e two or more components
    9. connected graph - graph is connected i.e one component
    10. strongly connected graph - when all vertices are reachable from every vertex
    11. acyclic graph - graph has no cycle
    12. cyclic graph - graph has cycle

Directed Acyclic Graph (DAG) - directed graph with no cycle
Topological ordering - linear ordering of vertices such that for every directed edge uv, vertex u comes before v in the ordering
*/

/*
Representation of undirected graph - 
        0--1
        |\ |       
        | \|
        3--2
         \/
          4 
    1. Adjacency matrix - 2D array of size V x V, where V is number of vertices
            0 1 2 3 4
        0   0 1 1 1 0
        1   1 0 1 0 0
        2   1 1 0 1 0
        3   1 0 1 0 0
        4   0 0 1 1 0 

        if there is an edge between vertex u and v, then matrix[u][v] = 1, else matrix[u][v] = 0
        diagonals represent self loop
        space complexity - O(V^2)
        time complexity - O(V^2)

        in weighted graph, we store weight of edge in matrix instead of 1
        then it is called cost adjacency matrix

    2. Adjacency list - array of size V, where each element is a linked list of vertices connected to it
        0 -> 1 -> 2 -> 3
        1 -> 0 -> 2
        2 -> 0 -> 1 -> 3
        3 -> 0 -> 2
        4 -> 2 -> 3
        space complexity - O(V + 2E)
        time complexity - O(V + 2E)

        in weighted graph, we store weight of edge in linked list. node = |edge|weight|next|
        then it is called cost adjacency list

    3. Compact list representation - uses a 1D array 
        size of array = number of vertices + 2*number of edges + 1 + 1  //1 for extra space and 1 for starting index =1(not 0)
        index 0 is not used
        index 1 to V stores indexes of array which stores the starting subarray of edges
        index V + 1 is empty - indicates start of vertices array
        index V + 2 to V + E stores vertices which are connected to each other
        1--2
        |\ |       
        | \|
        4--3
         \/
          5

        eg:
        V = 5, E = 6 , array size = 5 + 2*7 + 1 + 1 = 21
        step 1 - leave 0+5+1 = 6 spaces for indexes
        step 2 - from 7th index store the vertices that are connected to vertices from 1 to 5
        step 3 - now fill the vertices array by starting index of subarrays and the last position(i.e idx 6) holdes the last index of subarray
            /  7  10  12  16  19  21   2   3   4    1    3    1    2    4    5    1    3    5    3    4
indexes     0  1   2   3   4   5   6   7   8   9   10   11   12   13   14   15   16   17   18   19   20
                                       |_______|  |______|   |_______________|   |___________|  |______| 
               |________________|       vs of v1  vs of v2        vs of v3          vs of v4    vs of v5
               indexes of subarray of each vertex

            space complexity - O(V + 2E + 2)
            time complexity - O(V + 2E + 2)
        to store the weights of edges we can use another array i.e 2D array of 2 rows and V+2E+2 columns

*/
/*
Representation of directed graph - 
    1. Adjacency matrix - 2D array of size V x V, where V is number of vertices
          0 1 2 3 
        0 0 1 1 0 
        1 1 0 1 0 
        2 1 1 0 1 
        3 0 0 1 0 

        out-degree can be known from row sum
        in-degree can be known from column sum 
        
        space complexity - O(V^2)
        time complexity - O(V^2)

        in weighted graph, we store weight of edge in matrix instead of 1
        then it is called cost adjacency matrix
    2. Adjacency list - array of size V, where each element is a linked list of vertices connected to it
        0 -> 1 -> 2 -> 3
        1 -> 0 -> 2
        2 -> 0 -> 1 -> 3
        3 -> 0 -> 2
        4 -> 2 -> 3
        space complexity - O(V + 2E)
        time complexity - O(V + 2E)

        in weighted graph, we store weight of edge in linked list. node = |edge|weight|next|
        then it is called cost adjacency list
*/
//we use adjacency list for graph as it is space and time efficient