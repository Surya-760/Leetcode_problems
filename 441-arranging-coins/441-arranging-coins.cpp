class Solution {
public:
    int arrangeCoins(int n) {
        long l=0,h=n;
        long k,curr;
        while(l<=h)
        {
            k=l+(h-l)/2;
            curr=k*(k+1)/2;
            if(curr==n)
                return (int)k;
            if(n<curr)
                h=k-1;
            else
                l=k+1;
        }
        return (int)h;
    }
};