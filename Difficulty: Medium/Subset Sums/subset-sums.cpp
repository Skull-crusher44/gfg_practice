class Solution {
  public:
  vector<int>ans;
  int calculateSum(vector<int>&temp){
      int sum = 0;
      for(int x:temp){
          sum+=x;
      }
      return sum;
  }
  void backtrack(vector<int>&arr,vector<int>&temp,int index){
      if(index>=arr.size()){
          int sum = calculateSum(temp);
          ans.push_back(sum);
          return;
      }
      int current=arr[index];
      // if considering current element
      temp.push_back(current);
      backtrack(arr,temp,index+1);
      temp.pop_back();
      
      //if not considering current element 
      backtrack(arr,temp,index+1);
  }
  
    vector<int> subsetSums(vector<int>& arr) {
        vector<int>temp;
        backtrack(arr,temp,0);
        return ans;
    }
};