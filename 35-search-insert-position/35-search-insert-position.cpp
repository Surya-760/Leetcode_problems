class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0,m,h=nums.size()-1;
        while(l<=h)
        {
            m=l + (h - l) / 2;
            if(target==nums[m])
            {
                return m;
            }
            else if(target>nums[m])
            {
                l=l+1;
                
            }
            else
            {
                h=m-1;
            }
        }
        return l;
    }
};