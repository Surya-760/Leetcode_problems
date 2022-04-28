class Solution {
public:
    int calculateSoldierCount(vector<int> v) {
        int lo = 0;
        int hi = v.size() - 1;
        
        while(lo <= hi) {
            int mid = (lo + hi) / 2;
            
            if (v[mid] == 0) hi = mid - 1;
            else lo = mid + 1;
        }
        
        return lo;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int ,int>>a;
        vector<int>result;
        for(int i=0;i<mat.size();i++)
        {
            a.push_back( make_pair(calculateSoldierCount(mat[i]),i) );
        }
        sort(a.begin(),a.end());
  
        for(int i=0;i<k;i++)
        {
            result.push_back(a[i].second);
        }
        return result;
    }
};