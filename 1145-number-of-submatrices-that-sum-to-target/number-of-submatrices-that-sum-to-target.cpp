class Solution {
public:
  int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    int ans = 0;
    vector<vector<int>> cumsum(m, vector<int>(n));
    // Precompute the cumulative sum
    cumsum[0][0] = matrix[0][0];
    for (int i = 1; i < n; i++) {
      cumsum[0][i] = cumsum[0][i - 1] + matrix[0][i];
    }
    for (int i = 1; i < m; i++) {
      cumsum[i][0] = cumsum[i - 1][0] + matrix[i][0];
      int rowSum = matrix[i][0];
      for (int j = 1; j < n; j++) {
        rowSum += matrix[i][j];
        cumsum[i][j] = cumsum[i - 1][j] + rowSum;
      }
    }

    // Iterate over all submatrices
    for (int x1 = 0; x1 < m; x1++) {
      for (int x2 = x1; x2 < m; x2++) {
        for (int y1 = 0; y1 < n; y1++) {
          for (int y2 = y1; y2 < n; y2++) {
            // Calculate the sum of the submatrix and compare with target
            int sum = cumsum[x2][y2];
            if (y1 != 0) {
              sum -= cumsum[x2][y1 - 1];
            }
            if (x1 != 0) {
              sum -= cumsum[x1 - 1][y2];
              if (y1 != 0) {
                sum += cumsum[x1 - 1][y1 - 1];
              }
            }
            if (sum == target) {
              ans++;
            }
          }
        }
      }
    }
    return ans;
  }
};