class Solution {
public:
    bool diagonal(vector<vector<int>>& grid, int i, int j, int k, int curr) {
        int d1 = 0, d2 = 0;
        int size = k - j + 1;
        for (int t = 0; t < size; t++) {
            d1 += grid[i + t][j + t];
        }
        for (int t = 0; t < size; t++) {
            d2 += grid[i + t][j + size - 1 - t];
        }
        
        return (d1 == curr && d2 == curr);
    }
    
    int largestMagicSquare(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 1;
        vector<vector<int>> rowSum(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            rowSum[i][0] = grid[i][0];
            for (int j = 1; j < m; j++) {
                rowSum[i][j] = grid[i][j] + rowSum[i][j - 1];
            }
        }
        vector<vector<int>> colSum(n, vector<int>(m, 0));
        for (int j = 0; j < m; j++) {
            colSum[0][j] = grid[0][j];
            for (int i = 1; i < n; i++) {
                colSum[i][j] = grid[i][j] + colSum[i - 1][j];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int size = ans + 1; size <= min(n - i, m - j); size++) {
                    bool isMagic = true;
                    int targetSum = -1;
                    for (int r = i; r < i + size; r++) {
                        int rowSumVal = rowSum[r][j + size - 1] - (j > 0 ? rowSum[r][j - 1] : 0);
                        if (targetSum == -1) {
                            targetSum = rowSumVal;
                        } else if (rowSumVal != targetSum) {
                            isMagic = false;
                            break;
                        }
                    }
                    
                    if (!isMagic) continue;
                    for (int c = j; c < j + size; c++) {
                        int colSumVal = colSum[i + size - 1][c] - (i > 0 ? colSum[i - 1][c] : 0);
                        if (colSumVal != targetSum) {
                            isMagic = false;
                            break;
                        }
                    }
                    if (!isMagic) continue;                   
                    if (diagonal(grid, i, j, j + size - 1, targetSum)) {
                        ans = max(ans, size);
                    }
                }
            }
        }
        
        return ans;
    }
};