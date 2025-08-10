class Solution {
public:
    int solve(int n, int sum, vector<int>& arr, vector<vector<int>>& dp) {
        // Initialize DP table
        for(int i = 0; i < n+1; i++) {
            for(int j = 0; j < sum+1; j++) {
                if(i == 0 && j >= 1) dp[i][j] = 0; 
                if(j == 0) dp[i][j] = 1;           
            }
        }
        
        for(int i = 1; i < n+1; i++) {
            for(int j = 1; j < sum+1; j++) {
                if(arr[i-1] <= j) {
                    dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        
        int ans = INT_MAX;
        for(int j = 0; j <= sum/2; j++) {
            if(dp[n][j] == 1) {
                ans = min(ans, abs(sum - 2*j)); 
            }
        }
        return ans;
    }

    int minDifference(vector<int> &arr) {  
        int n = arr.size();  
        int sum = 0;
        for(int num : arr) sum += num;
        
        vector<vector<int>> dp(n+1, vector<int>(sum+1));
        
        return solve(n, sum, arr, dp);
    }
};
