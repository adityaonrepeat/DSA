class Solution {
public:
    int solve(int idx, int weight, int W, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp) {
        if (idx == wt.size()) return 0;

        if (dp[idx][weight] != -1) return dp[idx][weight];

        int take = 0;
        if (wt[idx] + weight <= W)
            take = val[idx] + solve(idx + 1, weight + wt[idx], W, val, wt, dp);

        int notTake = solve(idx + 1, weight, W, val, wt, dp);

        return dp[idx][weight] = max(take, notTake);
    }

    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = wt.size();
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
        
        return solve(0, 0, W, val, wt, dp);
    }
};

