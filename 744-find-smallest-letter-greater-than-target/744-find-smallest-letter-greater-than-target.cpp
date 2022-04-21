class Solution {
public:
    char nextGreatestLetter(vector<char>& l, char target) {
        int low=0,mid,high=l.size()-1;
        if(target>=l[high])
        {
            return l[0];
        }
        if(target<l[0])
        {
            return l[0];
        }
        while(low<high)
        {
            mid=(low+high)/2;
            if(l[mid]==target&&l[mid+1]!=target)
            {
                break;
            }
            else if(l[mid]<=target)
            {
                low=mid+1;
                if(low==high)
                    return l[mid+1];
            }
            else
            {
                high=mid;
                if(low==high)
                    return l[mid];
            }
        }
        return l[mid+1];
    }
};