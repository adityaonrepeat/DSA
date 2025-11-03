// https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/
class Solution {
public:
    int maximumSum(vector<int>& nums) {
         int n=nums.size();
         int maxi=nums[0];
         int nd=nums[0]; 
         int od=INT_MIN;

         for(int i=1;i<n;i++){
           
            od=max(nd, od==INT_MIN?INT_MIN:od+nums[i]);
             nd=max(nums[i],nums[i]+nd);
            maxi=max({maxi,od,nd});
         }


       return maxi;
    }
};
