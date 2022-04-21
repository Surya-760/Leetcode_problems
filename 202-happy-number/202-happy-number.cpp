class Solution {
public:
    bool isHappy(int n) {
        set<int>s;
        int sum=0,x=n,a;
        while(true){
            while(x!=0)
            {
                a=x%10;
                sum=sum+pow(a,2);
                x=x/10;
            }
            if(n==1)
                return true;
            else if(s.find(n)!=s.end())
                return false;
            s.insert(n);
            x=sum;
            n=sum;
            sum=0;
            
        }
        return false;
    }
};