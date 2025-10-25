// https://leetcode.com/problems/house-robber-iii
class Solution {
public:
    int ans;

    pair<int, int> dfs(TreeNode* root) {
        if(root == NULL) return {0, 0};
        
        pair<int, int> left = dfs(root -> left);
        pair<int, int> right = dfs(root -> right);

        ans = max(
                ans, 
                max(
                    left.first - ((root -> left) ? (root -> left -> val) : 0) + right.first - ((root -> right) ? (root -> right -> val) : 0) + root -> val, 
                    left.second + right.second + root -> val
                )    
            );

        ans = max(
                ans, 
                left.first + right.first
            );

        ans = max(
                ans, 
                max(
                    left.first + right.second, 
                    left.second + right.first
                )
            );

        ans = max(
                ans, 
                left.second + right.second
            );

        return {
            max(
                left.first - ((root -> left) ? (root -> left -> val) : 0) + right.first - ((root -> right) ? (root -> right -> val) : 0) + root -> val, 
                left.second + right.second + root -> val), 
            max(
                max(
                    max(
                        left.first + right.second, 
                        left.second + right.first
                    ), 
                    left.first + right.first
                ), 
                left.second + right.second
             )
            };
    }

    int rob(TreeNode* root) {
        ans = 0;
        dfs(root);
        return ans;
    }
};
