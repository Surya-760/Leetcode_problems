class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> vec( n , vector<int> (n, 0));
        int left=0;
        int right=n-1;
        int upper=0;
        int lower=n-1;
        int num=1;
        while(left<=right&&upper<=lower)
        {
            for(int i=left;i<=right;i++)
            {
                vec[upper][i]=num++;
            }
            upper++;
            if(upper>lower)break;
            for(int i=upper;i<=lower;i++)
            {
                vec[i][right]=num++;
            }
            right--;
            if(left>right)break;
            for(int i=right;i>=left;i--)
            {
                vec[lower][i]=num++;
            }
            lower--;
            if(lower<upper)break;
            for(int i=lower;i>=upper;i--)
            {
                vec[i][left]=num++;
            }
            left++;
            if(left>right)break;
        }
        return vec;
    }
};