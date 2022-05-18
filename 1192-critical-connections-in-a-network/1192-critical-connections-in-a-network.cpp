//What we have been asked is to find bridges and we have been given edges.
//So, first we just have to make bi-directional graph.
//second we will need three arrays,
//one will store time for firstTime we see that node,
//second we will have arr where we store minimumTime needed to reach that node. 
//Third is the visited array.
//Now after we have made the graph we will call dfs on first node, i.e. 0.
//In our dfs fn, we will insert value in array of both firstTime, and minTime for that node,
//and increase the time. So now we know with every dfs time will increase and we will mark that node visited.
//Now we will go to every neighbour of that node, in the graph, nbr or child or whatever u want to call it.
//we have three conditions only.
//nbr == parent, move to next iteration should not call dfs again or 
//we won't have anything in our answer, we will just be calling our parent and child again and again in timeless loop.
//if it hasn't been visited we call dfs and pass, the nbr as the node, and its parent as our initial node.
//Now we update minTime from what we have got from child and check if minTime of nbr is
//greater than firstTime of node, if it is true, it means this is our bridge. ans we insert it in our ans array. That is all it to bridges.
//


class Solution {
public:
    vector<vector<int>>graph,ans;
    vector<int>firstTime,minTime,vis;
    int time;
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        time=0;
        firstTime.resize(n), minTime.resize(n), vis.resize(n), graph.resize(n);
        for(vector<int>&edge:connections)
        {
            int u=edge[0],v=edge[1];
            graph[v].push_back(u);
            graph[u].push_back(v);
        }
        dfs(0);
        return ans;
    }
    void dfs(int node, int parent = -1)
    {
        firstTime[node] = minTime[node] = time++;
        vis[node] = 1;
        for(int nbr:graph[node])
        {
            if(nbr==parent) continue;
            if(!vis[nbr]) dfs(nbr,node);
            //the main two condition one is to update minTime and
		    //second is to check if it is a bridge.
            minTime[node] = min(minTime[node], minTime[nbr]);
            if(firstTime[node] < minTime[nbr]) ans.push_back({node, nbr});
        }
    }
};