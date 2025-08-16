//problem_link : https://www.geeksforgeeks.org/problems/rod-cutting0840/1
class Solution {
  public:
    int solve(int n,vector<int> &length,vector<int> &price,vector<vector<int>> &dp ){
        for(int i=0; i<n+1; i++){
            for(int j=0; j<n+1; j++){
                
                if(i==0 || j==0) dp[i][j] = 0;
            }
        }
        
        for(int i=1; i<n+1; i++){
            for(int j=1; j<n+1; j++){
                
                if(length[i-1]<=j){dp[i][j] = max(price[i-1]+dp[i][j-length[i-1]] , dp[i-1][j]);}
                else dp[i][j] = dp[i-1][j];
            }
        }
    return dp[n][length.size()];
    }
    
    int cutRod(vector<int> &price) {
        
        int n = price.size();
        vector<int> length;
        for(int i=1; i<=n; i++) length.push_back(i);
        
        vector<vector<int>> dp(n+1, vector<int>(length.size()+1));
        
        return solve(n,length,price,dp);
    }
};
