class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l=0,h=arr.size()-1,m;
        while(l<h)
        {
            m=l+(h-l)/2;
            if(arr[m]<arr[m+1])
            {
                l=m+1;
            }
            else
            {
                h=m;
            }
        }
        return l;
    }
};