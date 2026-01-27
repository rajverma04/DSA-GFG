class Solution {
  public:
    int m, n;

    bool checkValidMove(int i, int j) {
        return (i >= 0 && j >= 0 && i < m && j < n);
    }

    // ✅ BFS now returns minutes taken
    int bfs(queue<pair<int,int>> &q, vector<vector<int>>& mat, int &fresh) {
        int row[4] = {-1, 0, 0, 1};
        int col[4] = {0, -1, 1, 0};

        int minutes = 0;

        while(!q.empty()) {
            int sz = q.size();
            bool rotted = false;

            for(int s = 0; s < sz; s++) {
                auto [i, j] = q.front();
                q.pop();

                for(int k = 0; k < 4; k++) {
                    int ni = i + row[k];
                    int nj = j + col[k];

                    if(checkValidMove(ni, nj) && mat[ni][nj] == 1) {
                        mat[ni][nj] = 2;
                        fresh--;
                        q.push({ni, nj});
                        rotted = true;
                    }
                }
            }

            if(rotted) minutes++;
        }
        return minutes;
    }

    int orangesRot(vector<vector<int>>& mat) {
        m = mat.size();
        n = mat[0].size();

        queue<pair<int,int>> q;
        int fresh = 0;

        // ✅ Multi-source initialization
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 2) q.push({i, j});
                else if(mat[i][j] == 1) fresh++;
            }
        }

        if(fresh == 0) return 0;

        int minutes = bfs(q, mat, fresh);

        return (fresh == 0) ? minutes : -1;
    }
};
