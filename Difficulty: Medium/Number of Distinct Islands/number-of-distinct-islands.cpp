//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    // This function performs BFS to explore an island and mark all of its cells as visited.
    void find(vector<vector<int>>& grid, int row, int col, vector<pair<int,int>>& temp) {
        int rows = grid.size();          // Number of rows in the grid
        int cols = grid[0].size();       // Number of columns in the grid
        queue<pair<int,int>> q;          // Queue for BFS
        q.push({row, col});              // Push the starting cell (row, col) of the island into the queue
        grid[row][col] = 2;              // Mark the cell as visited by changing '1' to '2'
        temp.push_back({0, 0});          // Correct initialization
        
        // Perform BFS to visit all cells in the island
        while (!q.empty()) {
            int row_no = q.front().first;    // Get the row of the current cell
            int col_no = q.front().second;   // Get the column of the current cell
            q.pop();                         // Remove the cell from the queue
            
            // Define all four possible directions (up, down, left, right)
            vector<pair<int,int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            for (auto dir : directions) {
                int new_row = row_no + dir.first;  // New row after moving in a direction
                int new_col = col_no + dir.second; // New column after moving in a direction
                
                // Check if the new position is within bounds and is a land cell ('1')
                if (new_row >= 0 && new_row < rows && new_col >= 0 && new_col < cols && grid[new_row][new_col] == 1) {
                    grid[new_row][new_col] = 2;  // Mark the new cell as visited
                    q.push({new_row, new_col});    // Add the new cell to the queue for further exploration
                    temp.push_back({new_row - row, new_col - col}); // Record relative position
                }
            }
        }
    }
    
    // This function counts the number of distinct islands in the grid.
    int countDistinctIslands(vector<vector<int>>& grid) {
        int rows = grid.size();           // Get the number of rows in the grid
        int cols = grid[0].size();        // Get the number of columns in the grid
        set<vector<pair<int,int>>> ans; // Set to store unique island shapes
        
        // Traverse the entire grid
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // If we find a land cell ('1'), it means we have found a new island
                vector<pair<int,int>> temp;
                if (grid[i][j] == 1) {
                    find(grid, i, j, temp);  // Perform BFS to explore and mark the entire island
                    if (!temp.empty()) {      // Only insert if temp has valid values
                        ans.insert(temp);     // Insert the island shape into the set
                    }
                }
            }
        }
        return ans.size();  // Return the total distinct number of islands
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends