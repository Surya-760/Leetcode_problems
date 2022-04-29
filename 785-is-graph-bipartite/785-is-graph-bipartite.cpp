// A graph is said to be bipartite if we can divide all its vertices into two mutually 
// exclusive and exhaustive sets such that none of the edge is within the set(i.e. all the 
//  edges of graph are across the sets)

/*
    1) A acyclic graph is always bipartite because we can easily put all the connected vertices
        into different sets.
    2) A cyclic graph with even number of vertices in the cycle is bipartite. This is because when we visit the cycle detection vertex, it would be at the same level in BFS.
    3) a cyclic graph with odd number of vertices in the cycle is always non-bipartite because in a BFS, we would visit the cycle detection vertex twice and each time this vertex would be at different levels in BFS.
*/

class Solution {
public:
    
    // Simple BFS modification.
    bool checkComponentsForBipartiteness(vector<vector<int>>& graph, int src, vector<int>&marked_levels){
        queue<pair<int,int>> q; // stores the vertex and its corresponding level .
        q.push({src,0});
        while(q.size() > 0){
            pair<int,int> vertex = q.front();
            q.pop();
            
            // if the vertex is already visited that means there exists a cycle.
            // If the level stored in marked_levels and the level of popped vertex differ, that means the cycle is odd. hence, return false;
            if(marked_levels[vertex.first] != -1){
                if(marked_levels[vertex.first] != vertex.second){
                    return false;
                }
            }
            
            // else simply store the level of vertex into marked levels.
            else{
                marked_levels[vertex.first] = vertex.second;
            }
            
            
            // add all the connected vertices of vertex into the queue as they are the next level in BFS.
            for(int v : graph[vertex.first]){
                if(marked_levels[v] == -1){
                    q.push({v,vertex.second+1});
                }
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        // define a vector say marked_levels that stores/marks the level at which the vertex was visited during BFS at the corresponding vertex index.
        vector<int> marked_levels(graph.size(), -1);
        
        // even if a single component of a graph is non-bipartite the entire graph will be bipartite . Hence, checking bipartiteness for all the components.
        for(int i=0;i<graph.size();i++){
            if(marked_levels[i] == -1){
                bool bipartite = checkComponentsForBipartiteness(graph, i, marked_levels);
                if(bipartite == false){
                    return false;
                }
            }
        }
        return true;
    }
};


/*
Analysis:
1) TC :-  O(N + E)   as we are doing a simple BFS.
2) SC :-  O(N)       we are using a queue which will store at max N vertices.


*/