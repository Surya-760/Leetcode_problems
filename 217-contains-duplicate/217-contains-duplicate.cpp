class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> a;
        for(auto x:nums)
            a.insert(x);
        if(a.size()==nums.size())
            return false;
        else
            return true;
    }
};