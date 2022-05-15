class Solution {
public:
    
    // I'm going to use Bellman Ford Algorithm
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        // just created a dis vector that will store the distance for reaching the node
        // and assign dis[k]=0 because we will start searching from k 
        vector<int>dis(n+1,INT_MAX);
        dis[k]=0;
        
        
        // we will update our dis vector upto (n-1) times according to bellman's ford algo
        for(int i=1;i<n;i++)
        {
            // just checking for all the nodes that are available in our graph
            for(int j=0;j<times.size();j++)
            {
                // extracting source, destination, weight
                int u=times[j][0];     // source
                int v=times[j][1];     // destination
                int w=times[j][2];     // weight
                 
                // if current source is not finite value then we can not pick that path 
                // so just check current source is finite or not
                // and if we have better path for reaching V from U by using W then we update dis[v]
                if(dis[u]!=INT_MAX && dis[u]+w<dis[v])
                {
                    // if we are having better path available then just update our dis
                    dis[v]=w+dis[u];
                }
            }
        }
		 
        // take out the best value to reach n from k
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            // If any node is not reachable from k return -1
            if(dis[i]==INT_MAX) 
                return -1;  
            
            // else take best path
            ans=max(ans,dis[i]);
        }
        return ans;
        
    }
};