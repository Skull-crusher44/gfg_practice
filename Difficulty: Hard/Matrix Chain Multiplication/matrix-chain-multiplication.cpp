class Solution {
    vector<vector<int>> dp;

public:
    int solve(vector<int>& arr, int i, int j) {
        if (i >= j) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int total_cost = INT_MAX;
        for (int k = i; k <= j - 1; k++) {
            int temp_cost = solve(arr, i, k) +
                            solve(arr, k + 1, j) +
                            arr[i - 1] * arr[k] * arr[j];
            total_cost = min(total_cost, temp_cost);
        }
        return dp[i][j] = total_cost;
    }

    int matrixMultiplication(vector<int>& arr) {
        int n = arr.size();
        dp = vector<vector<int>>(n, vector<int>(n, -1));  // ✅ Initialized properly
        return solve(arr, 1, n - 1);
    }
};
