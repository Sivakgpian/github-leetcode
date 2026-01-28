class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int mn = m*n;
        vector<pair<int, int>> gridOrder; // from large to small
        gridOrder.reserve(m*n);
        for(int r=0; r<m; ++r){
            for(int c=0; c<n; ++c){
                gridOrder.emplace_back(r,c);
            }
        }
        sort(gridOrder.begin(), gridOrder.end(), [&](pair<int, int>& a, pair<int, int>& b){
            return grid[a.first][a.second] > grid[b.first][b.second];
        });

        vector<vector<int>> cost(m, vector<int>(n, INT_MAX/2));
        for(int loop=0; loop<=k; ++loop){ // at most k times
            // Try Teleportation move first
            // Use sliding window from big grid to samll grid
            int l = 0, r = 0;
            int minCost = INT_MAX / 2;
            while(r < mn){
                while(r < mn && grid[gridOrder[r].first][gridOrder[r].second] == grid[gridOrder[l].first][gridOrder[l].second]){
                    minCost = min(minCost, cost[gridOrder[r].first][gridOrder[r].second]);
                    ++r;
                }
                for(int i=l; i<r; ++i) cost[gridOrder[i].first][gridOrder[i].second] = minCost;
                l = r;
            }
            
            // Try normal move
            cost[0][0] = 0;
            for(int r=0; r<m; ++r){
                for(int c=0; c<n; ++c){
                    if(r != 0) cost[r][c] = min(cost[r][c], grid[r][c] + cost[r-1][c]);
                    if(c != 0) cost[r][c] = min(cost[r][c], grid[r][c] + cost[r][c-1]);
                }
            }
        }
        return cost[m-1][n-1];
    }
};