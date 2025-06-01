// User function Template for C++

class Solution {
  public:
  void insertAtBottom(stack<int>&s, int elementToBeInserted){
      if(s.empty())
      s.push(elementToBeInserted);
      else{
          int temp = s.top();
          s.pop();
          insertAtBottom(s,elementToBeInserted);
          s.push(temp);
      }
  }
    void Reverse(stack<int> &s) {
        
        if(!s.empty()){
            int temp = s.top();
            s.pop();
            Reverse(s);
            insertAtBottom(s,temp);
        }
        else return;
        
        
    }
};