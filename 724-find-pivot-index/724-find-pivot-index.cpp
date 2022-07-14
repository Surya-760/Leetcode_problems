class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=0;
        vector<int>n;
        n.push_back(0);
        for(auto x:nums)
            n.push_back(x);
        n.push_back(0);
        sum=accumulate(nums.begin(),nums.end(),sum);
        for(int i=1;i<n.size()-1;i++)
        {
            int left_sum=0,right_sum=0;
            for(int j=0;j<i;j++)
                left_sum+=n[j];
            right_sum=sum-left_sum-nums[i-1];
            if(left_sum==right_sum)
                return i-1;
        }
        return -1;
    }
};