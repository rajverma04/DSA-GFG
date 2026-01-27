class Solution {
  public:
    bool checkValidMove(int i, int j, int m, int n) {
        return (i > -1 && j > -1 && i < m && j < n);
    }
    void BFS(int i, int j, vector<vector<char>> &grid) {
        int row[8] = {-1, -1, -1, 0, 0, 1, 1, 1};        // can move -1 to 1
        int col[8] = {-1, 0, 1, -1, 1, -1, 0, 1};        // can move -1 to 1
        
        int m = grid.size();    // grid row size
        int n = grid[0].size();     // grid col size 
        
        queue<pair<int, int>> q;        // {row, col}
        q.push({i, j});
        grid[i][j] = 'W';
        
        while(!q.empty()) {
            i = q.front().first;
            j = q.front().second;
            q.pop();
            
            for(int k = 0; k < 8; k++) {
                if(checkValidMove(i + row[k], j + col[k], m, n) && grid[i + row[k]][j + col[k]] == 'L') {
                    grid[i + row[k]][j + col[k]] = 'W';
                    q.push({i + row[k], j + col[k]});
                }
            }
        }
    }
    int countIslands(vector<vector<char>>& grid) {
        int m = grid.size();    // row size
        int n = grid[0].size();     // col size
        int count = 0;          // no of islands
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 'L') {
                    count++;
                    BFS(i, j, grid);        // traverse its neighbour
                }
            }
        }
        
        return count;
    }
};