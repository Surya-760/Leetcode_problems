class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum=0,product=1;
        while(n)
        {
            int a=n%10;
            sum+=a;
            product*=a;
            n=n/10;;
        }
        return product-sum;
    }
};