class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        int a=0;
        for(int i=0;i<nums.size()-2;i++)
        {
            if(nums[i]<(nums[i+1]+nums[i+2]))
            {
                a=nums[i]+nums[i+1]+nums[i+2];
                break;
            }
        }
            return a;
    }
};