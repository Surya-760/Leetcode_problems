class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>vec;
  for(int i=0;i<numbers.size();i++){
      int remained=target-numbers[i];
      int k=0;
      int l=numbers.size()-1;
      while(k<=l){
          int mid=k+(l-k)/2;
          if(mid==i){
              k=mid+1;
          }
          
          else if(numbers[mid]==remained){
              vec.push_back(i+1);
              vec.push_back(mid+1);
              return vec;
          }
          else if(numbers[mid]<remained){
              k=mid+1;
          }
          else{
              l=mid-1;
          }
        }
    }      
        
      return vec;  
        
    }
};