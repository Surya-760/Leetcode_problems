class Solution {
public:
    int signFunc(int x){
        if(x>0)
            return 1;
        else if(x<0)
            return -1;
        else
            return 0;
    }
    int arraySign(vector<int>& nums) {
        long long product=1;
        long s=1000000007;
        for(auto x:nums)
        {
            product=(product*x)%s;
        }
            
        
        return signFunc(product);
    }
};