class Solution {
  public:
    int m, n;
    bool checkValidMove(int i, int j) {
        return (i > -1 && j > -1 && i < m && j < n);
    }
    void bfs(int i, int j, int initColor, int newColor, vector<vector<int>>& image) {
        int row[4] = {-1, 0, 0, 1};
        int col[4] = {0, -1, 1, 0};
        
        queue<pair<int, int>> q;
        q.push({i, j});
        image[i][j] = newColor;
        
        while(!q.empty()) {
            i = q.front().first;
            j = q.front().second;
            q.pop(); 
            
            for(int k = 0; k < 4; k++) {
                if(checkValidMove(i + row[k], j + col[k]) && image[i + row[k]][j + col[k]] == initColor) {
                    image[i + row[k]][j + col[k]] = newColor;
                    q.push({i + row[k], j + col[k]});
                }
            }
        }
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        
        m = image.size();        // grid row size
        n = image[0].size();        // grid col size
        int initColor = image[sr][sc];       // initial Color
        
        if(initColor == newColor) {
            return image;
        }
        
        
        bfs(sr, sc, initColor, newColor, image);
        return image;
    }
};