class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();           
        int n = (m > 0) ? grid[0].size() : 0;
        
        if (m == 0 || n == 0) return grid;

        k = k % (m * n);
        if (k == 0) return grid;

        for (int iterator = 0; iterator < k; iterator++) {
            int last_element = grid[m - 1][n - 1];
            
            for (int i = m - 1; i >= 0; i--) {
                for (int j = n - 1; j >= 0; j--) {
                
                    if (j > 0) {
                        grid[i][j] = grid[i][j - 1];
                    }
                    else if (i > 0) {
                        grid[i][0] = grid[i - 1][n - 1];
                    }
                    else {
                        grid[0][0] = last_element;
                    }
                }
            }
        }
        return grid;
    }
};
