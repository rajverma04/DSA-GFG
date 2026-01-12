// User function template for C++

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        int n = dist.size();
        
        // for(int i = 0; i < n; i++) {
        //     for(int j = 0; j < n; j++) {
        //         if (i == j) {
        //           dist[i][j] = 0;  
        //         } 
        //         else if (dist[i][j] == -1) {
        //             dist[i][j] = INT_MAX;
        //         }
        //     }
        // }
        const int INF = 100000000;
        
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if (dist[i][k] != INF && dist[k][j] != INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        
        // for(int i = 0; i < n; i++) {
        //     for(int j = 0; j < n; j++) {
        //         if(dist[i][j] == INT_MAX) {
        //             dist[i][j] = -1;
        //         }
        //     }
        // }
        
    }
};