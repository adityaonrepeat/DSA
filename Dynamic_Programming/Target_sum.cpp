class Solution {
public:
    int solve(int n,vector<int>& arr, int target,vector<vector<int>>&dp){
        
        for(int i=0;i<n+1;i++){
            for(int j=0; j<target+1; j++){
                
                if(i==0 && j>=1) dp[i][j] = 0;
                if(j==0) dp[i][j] = 1;
            }
        }
        
        for(int i=1;i<n+1;i++){
            for(int j=1; j<target+1; j++){
                
                if(arr[i-1]<=j){
                    dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
                }else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][target];
    }
    
    int perfectSum(vector<int>& arr, int target) {
        int n= arr.size();
        int cnt = count(arr.begin(),arr.end(),0);
        
        vector<int> temp;
        
        for(int i=0; i<n; i++){
            if(arr[i]!=0) temp.push_back(arr[i]);
        }
        
	    int n1 = temp.size();
	    
        vector<vector<int>> dp(n1+1,vector<int>(target+1));
        
        int ans = solve(n1,temp,target,dp);
        return ((1<<cnt)* ans);
    }
    
    int countPartitions(vector<int>& arr, int d) {
        int sum = 0,n = arr.size();
        
        for(int i=0; i<n; i++){
            sum += arr[i];
        }
        
        if((sum+d)%2!=0) return 0;
        return perfectSum(arr,(sum+d)/2);
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(),nums.end(),0);

        if(sum < abs(target)) return 0;
        return countPartitions(nums,target);
    }
};
