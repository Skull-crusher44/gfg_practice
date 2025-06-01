class Solution {
  public:
  vector<string>ans;
  void backtrack(vector<vector<int>>&maze, string temp, int i, int j){
      //Boundry condition
    //   if(i<0||j<0||i>=maze.size()||j>=maze.size()|| maze[i][j]==0)return;
      
      
      
      //Base case
      if(i==maze.size()-1&&j==maze[0].size()-1){
          ans.push_back(temp);
          return;
      }
      
      // logic
      maze[i][j] = -1;
      
      vector<pair<pair<int,int>,char>>dir = {
          {{1,0},'D'},
          {{-1,0},'U'},
          {{0,1},'R'},
          {{0,-1},'L'}};
          
      for(auto pair:dir){
          int x = pair.first.first;
          int y = pair.first.second;
          char move = pair.second;
          int newx = i+x;
          int newy = j+y;
          if(newx>=0 && newy>=0 && newx<maze.size() && newy<maze.size()&& maze[newx][newy]!=0 && maze[newx][newy]!=-1){
              backtrack(maze,temp+move,newx,newy);
            }
        }
          maze[i][j] = 1;
  }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        backtrack(maze,"",0,0);
        sort(ans.begin(),ans.end());
        return ans;
    }
};