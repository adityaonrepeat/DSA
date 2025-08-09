class Solution {
  public:
    bool exist(int n, vector<int>& arr, int sum, vector<vector<bool>>& dp) {
        for (int i=0; i <n+1; i++) {
            for (int j=0; j<sum+1; j++) {
                if (i == 0 && j>0) dp[i][j] = false;
                if (j == 0) dp[i][j] = true;
            }
        }

        for (int i=1; i<n+1; i++) {
            for (int j=1; j<sum+1; j++) {
                if (arr[i-1] <= j) {
                    dp[i][j] = dp[i-1][ j-arr[i - 1]] || dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n][sum];
    }
    
    bool equalPartition(vector<int>& arr) {
        int sum = 0;
        int n= arr.size();
        
        for(auto& it: arr) sum+=it;
        vector<vector<bool>> dp(n+1,vector<bool>((sum/2)+1) );
        
        if(sum%2==1) return false;
        else return exist(n,arr,sum/2,dp);
    }
};
