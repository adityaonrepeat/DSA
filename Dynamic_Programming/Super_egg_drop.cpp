// https://leetcode.com/problems/super-egg-drop/
class Solution {
public:
    int solve(int k, int n, vector<vector<int>>& t){
        if(k == 1 || n == 0 || n == 1) return n;
        if(t[k][n] != -1) return t[k][n];
        int mn = INT_MAX;
        int low = 1, high = n;
        while(low <= high){
            int mid = (low + high) / 2;
            int left = solve(k - 1, mid - 1, t);
            int right = solve(k, n - mid, t);
            int tmp = 1 + max(left, right);
            mn = min(mn, tmp);
            if(left < right) low = mid + 1;
            else high = mid - 1;
        }
        return t[k][n] = mn;
    }
    int superEggDrop(int k, int n) {
        vector<vector<int>> t(k+1, vector<int>(n+1, -1));
        return solve(k, n, t);
    }
};
