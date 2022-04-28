class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int ,int>>a;
        vector<int>result;
        for(int i=0;i<mat.size();i++)
        {
            a.push_back( make_pair(count(mat[i].begin(), mat[i].end(), 1),i) );
        }
        sort(a.begin(),a.end());
  
        for(int i=0;i<k;i++)
        {
            result.push_back(a[i].second);
        }
        return result;
    }
};