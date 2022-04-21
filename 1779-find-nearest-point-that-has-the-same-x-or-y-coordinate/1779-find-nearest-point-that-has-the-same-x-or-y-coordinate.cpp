class Solution {
public:
    int mDist(int x, int y, int a, int b)
    {
        return abs(x-a)+abs(y-b);
    }
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) 
    {
        int minDistVal = INT_MAX; // intializing to max so that first dist is always smaller
        int minDistIndx = -1; // if no point is Valid
        for(int i=0;i<points.size();i++)
        {
            // Check if the point is Valid
            if(points[i][0]==x || points[i][1]==y)
            {
                int dist = mDist(x,y,points[i][0],points[i][1]);
                // if dist is smaller than min than replace (not replace if dist==min so as to not change indx value) 
                if(minDistVal>dist)
                {
                    minDistVal = dist;
                    minDistIndx = i;
                }
            }
        }
        return minDistIndx;
    }
};