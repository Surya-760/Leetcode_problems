class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=0,h=nums.size()-1;
        vector<int>a(2,-1);
        while(l<=h)
        {
            int m=l+(h-l)/2;
            if(nums[m]==target)
            {
                a[0]=m;
                h=m-1;
            }
            else if(nums[m]<target)
                l=m+1;
            else
                h=m-1;
        }
        l=0,h=nums.size()-1;
        while(l<=h)
        {
            int m=l+(h-l)/2;
            if(nums[m]==target)
            {
                a[1]=m;
                l=m+1;
            }
            else if(nums[m]<target)
                l=m+1;
            else
                h=m-1;
        }
        return a;
    }
    
};