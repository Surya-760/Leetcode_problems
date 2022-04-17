class Solution {
public:
    double average(vector<int>& salary) {
        double sum=0,avg;
        double x=salary.size();
        sort(salary.begin(),salary.end());
        sum=accumulate(salary.begin(),salary.end(),sum);
        avg=(sum-salary[0]-salary[x-1])/(x-2);
        return avg;
    }
};