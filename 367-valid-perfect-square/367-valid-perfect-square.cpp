class Solution {
public:
    bool isPerfectSquare(int num) {
        int l=1,h=num,m;
        if(num==1)
            return true;
        while(l<=h)
        {
            float m=l+(h-l)/2;
            if(m==num/m)
                return true;
            else if(m<num/m)
                l=m+1;
            else
                h=m-1;
        }
        return false;
    }
};