class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        for(int i=0;i<n;i++){
            int l=0,r=n-1;
            int d=arr[i]*2;
            while(l<=r){
                int m=l+(r-l)/2;
                if(arr[m]==d){
                    r=m-1;
                }else if(arr[m]>d){
                    r=m-1;
                }else
                    l=m+1;
            }
            if(l<n&&l!=i&&arr[l]==d){
                return true;
            }
        }
        return false;
    }
};