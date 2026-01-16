// https://leetcode.com/problems/split-array-with-same-average
class Solution {
public:
    bool find(vector<int>& nums, int target, int l) {
        int n = nums.size();
        vector<vector<bool>> dp(l + 1, vector<bool>(target + 1, false));
        dp[0][0] = true;

        for (int num : nums) {
            for (int len = l; len >= 1; len--) {
                for (int s = target; s >= num; s--) {
                    dp[len][s] = dp[len][s] || dp[len - 1][s - num];
                }
            }
        }
        return dp[l][target];
    }

    bool splitArraySameAverage(vector<int>& nums) {
        if (nums.size() < 2)   return false;
        int n = nums.size();
        sort(nums.begin(), nums.end());
    
        int avg = 0;
        for (auto i : nums) avg += i;

        for (int l = 1; l < n; l++) {
            if (((l) * (avg)) % n != 0) continue;
            int req_sum = (l * avg) / n; 

            bool ans = find(nums, req_sum, l);
            if (ans)
                return true;
        }
        return false;
    }
};
