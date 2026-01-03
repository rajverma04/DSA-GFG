class Solution {
  public:
  
    bool check(int i, int j, int n, int m) {
        return i > -1 && i < n && j > -1 && j < m;
    }
    
    void fill(vector<vector<char>>& grid) {
        int row[4] = {1,-1,0,0};
        int col[4] = {0,0,1,-1};
        
        queue<pair<int, int>> q;
        
        vector<vector<char>> ans(grid.size(), vector<char>(grid[0].size(), 'X'));
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        
        // first row
        for(int i = 0; i < grid[0].size(); i++) {
            if(grid[0][i] == 'O') {
                q.push({0, i});
                ans[0][i] = 'O';
            }
            visited[0][i] = true;
        }
        // last row
        for(int i = 0; i < grid[0].size(); i++) {
            int n = grid.size();
            if(grid[n - 1][i] == 'O') {
                q.push({n - 1, i});
                ans[n - 1][i] = 'O';
            }
            visited[n - 1][i] = true;
        }
        // first col
        for(int i = 1; i < grid.size() - 1; i++) {
            if(grid[i][0] == 'O') {
                q.push({i, 0});
                ans[i][0] = 'O';
            }
            visited[i][0] = true;
        }
        // last col
        for(int i = 1; i < grid.size() - 1; i++) {
            int n = grid[0].size();
            if(grid[i][n - 1] == 'O') {
                q.push({i, n - 1});
                ans[i][n - 1] = 'O';
            }
            visited[i][n -  1] = true;
        }
        
        int u, v;
        int n = grid.size();
        int m = grid[0].size();
        while(!q.empty()) {
            u = q.front().first;
            v = q.front().second;
            q.pop();
            
            for(int k = 0; k < 4; k++) {
                if(check(u + row[k], v + col[k], n, m) && !visited[u + row[k]][v + col[k]]) {
                    visited[u + row[k]][v + col[k]] = true;
                    if(grid[u + row[k]][v + col[k]] == 'O') {
                        ans[u + row[k]][v + col[k]] = 'O';
                        q.push({u + row[k], v + col[k]});
                    }
                }
            }
        }
        
        // Flip remaining 'O' to 'X'
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 'O' && !visited[i][j]) {
                    grid[i][j] = 'X';
                }
            }
        }
    }
};