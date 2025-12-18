// https://leetcode.com/problems/reducing-dishes
class Solution {
public:
    int solveRec(vector<int>& satisfaction, int i, int time) {
        
        if (i == satisfaction.size())
            return 0;
        
        int inc =
            satisfaction[i] * (time) + solveRec(satisfaction, i + 1, time + 1);
        int exc = 0 + solveRec(satisfaction, i + 1, time);
        return max(inc, exc);
    }
    int solveMem(vector<int>& satisfaction, int i, int time,
                 vector<vector<int>>& dp) {
        
        if (i == satisfaction.size())
            return 0;
        if (dp[i][time] != -1)
            return dp[i][time];
        
        int inc = satisfaction[i] * (time) +
                  solveMem(satisfaction, i + 1, time + 1, dp);
        int exc = 0 + solveMem(satisfaction, i + 1, time, dp);
        return dp[i][time] = max(inc, exc);
    }
    int solveTab(vector<int>& satisfaction){
        vector<vector<int>> dp(satisfaction.size() + 1,
                               vector<int>(satisfaction.size() + 2, 0));
        for(int i = satisfaction.size()-1;i>=0;i--){
            for(int time = satisfaction.size();time>=1;time--){
                int inc = satisfaction[i] * (time) + dp[i + 1][time + 1];
                int exc = 0 + dp[i + 1][time];
                dp[i][time] = max(inc, exc);
            }
        }
        return dp[0][1];
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        
        return solveTab(satisfaction);
    }
};
