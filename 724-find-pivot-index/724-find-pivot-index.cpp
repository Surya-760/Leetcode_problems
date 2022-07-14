class Solution {
public:
     int pivotIndex(vector<int>& nums) {
        int totsum = 0;
        totsum=accumulate(nums.begin(),nums.end(),totsum);
        int sum = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(totsum - sum - nums[i] == sum) return i;
            sum += nums[i];
        }
        return -1;
    }
};