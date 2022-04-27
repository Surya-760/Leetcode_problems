class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int count = 0;
        char a, b;
        for(int i = 0; i < s1.size(); ++i){
            if(s1[i] != s2[i]){
                if(count == 0){
                    ++count;
                    a = s1[i];
                    b = s2[i];   
                }else if(count == 1){
                    if(s1[i] == b && s2[i] == a){
                        ++count;
                    }else{
                        return false;
                    }
                }else{
                   ++count; 
                }
            }
        }
        return count == 2 || count == 0;
    }
};