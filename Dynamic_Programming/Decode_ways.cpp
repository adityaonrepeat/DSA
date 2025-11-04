//
class Solution {
public:
    int dp[101];
    int stoi(string s) {
        int ans=0;
        for(int i=0;i<s.length();i++) {
            ans = ans * 10 + (s[i] - '0');
        }
        return ans;
    }
    int solve(string s, int i) {
        if(i==s.length()) {
            return 1;
        }
        if(s[i]=='0') return 0;
        if(dp[i]!=-1) return dp[i];
        int ans = 0;
        if(i+1<s.length()) {
            string dig = s.substr(i,2);
            int x = stoi(dig);        
            if(x>0 && x<=26) {
                ans+=solve(s, i+2);
            }
        }
        ans+=solve(s,i+1);
        return dp[i]=ans;
    }
    int numDecodings(string s) {
        memset(dp, -1, sizeof(dp));
        return solve(s,0);
    }
};
