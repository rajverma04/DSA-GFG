class Solution {
  public:
    void solve(int i, int j, vector<vector<int>>& maze, vector<string> &ans, vector<vector<int>> &vis, string str) {
        int n = maze.size();
        // string str = "";
        if(i >= n || j >= n || i < 0 || j < 0) {
            return;
        }
        if(maze[i][j] == 0 || vis[i][j] == 1) {
            return;
        }
        
        if(i == n - 1 && j == n - 1) {
            ans.push_back(str);
            return;
        }
        
        vis[i][j] = 1;
        
        
        solve(i + 1, j, maze, ans, vis, str + "D");

        solve(i, j - 1, maze, ans, vis, str + "L");

        solve(i, j + 1, maze, ans, vis, str + "R");

        solve(i - 1, j, maze, ans, vis, str + "U");
        
        vis[i][j] = 0;
        
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n = maze.size();
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int> (n, 0));
        solve(0, 0, maze, ans, vis, "");
        return ans;
    }
};