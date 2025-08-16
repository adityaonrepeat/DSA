// using dp(for better tc: use greedy
// problem link : https://leetcode.com/problems/assign-cookies/
class Solution {
public:
    int n,m;
    // int dp[30005][30005];

    int solve(int i,int j,vector<int>& g, vector<int>& s,vector<vector<int>> &dp){
        if(i==n || j==m) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int notgive = solve(i,j+1,g,s,dp);
        int give = 0;
        if(g[i]<=s[j]) give = 1 + solve(i+1,j+1,g,s,dp);

        return dp[i][j] = max(give,notgive);    
    }

    int findContentChildren(vector<int>& g, vector<int>& s) {
        n = g.size();
        m = s.size();

        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        vector<vector<int>> dp(n,vector<int>(m,-1));
        // memset(dp,-1,sizeof(dp));

        return solve(0,0,g,s,dp);

    }
};
