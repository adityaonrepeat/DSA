//https://www.geeksforgeeks.org/problems/geek-jump/1
class Solution {
  public:
  
    int dp[100005];
    
    int solve(int level, vector<int>& height ){
        
        // sub problem = what's the cost of reaching 0 from i;
        
        if(level<0) return 1e9;
        if(level==0) return 0;
        
        if(dp[level]!=-1) return dp[level] ;
        
        int left = solve(level-1,height) + abs(height[level] - height[level-1]);
        int right = INT_MAX;
        
        /* if (level > 1)*/ right = solve(level-2,height) + abs(height[level] - height[level-2]);    
        
        return dp[level] = min(left, right) ;
    }
    int minCost(vector<int>& height) {
        
        int n = height.size();
        memset(dp, -1, sizeof(dp));
        
        return solve(n-1,height);
    }
};
