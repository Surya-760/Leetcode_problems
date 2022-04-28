class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int high = nums.size() -1;
        int low = 0;
        int index = low + (high-low)/2;
        
        while (low <= high) {
            index = low + (high-low)/2;
            if (nums[index] == target)
                return index;
            if (nums[low] <= nums[index]) {
                if (target <= nums[index] && target >= nums[low])
                    high = index -1;
                else
                    low = index +1;
            } else {
                if (target >= nums[index] && target <= nums[high])
                    low = index +1;
                else
                    high = index -1;
            }
        }
        return -1;
    }
};