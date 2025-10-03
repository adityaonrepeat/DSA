#include <bits/stdc++.h>
#include <cmath>
using namespace std;
#define int long long
#define endl '\n'
const int mod=1e9+7;
const int INF = 1e9;
// using ll = long long int;

int n;
char grid[1001][1001];

void solve(){
    vector<vector<int>> dp(n+1,vector<int>(n+1));

    // dp[0][0] = 1;

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {

            if (grid[i][j] == '*') {
                dp[i][j] = 0;
            } 
            else if (i == 0 && j == 0) {
                dp[i][j] = 1;  // starting point
            } 
            else {
                int up =0, left = 0;

                if(i>=1 ) up = dp[i-1][j];
                if(j>=1 ) left = dp[i][j-1];

                dp[i][j] = (up + left) % mod;
            }

        }
    }

    cout << dp[n-1][n-1] << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n;

    for(int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> grid[i][j];
        }
    }
    
    solve();

    return 0;
}

/* #include <bits/stdc++.h>
#include <cmath>
using namespace std;
#define int long long
#define endl '\n'
const int mod=1e9+7;
const int INF = 1e9;
// using ll = long long int;

int n;
char grid[1001][1001];
int dp[1001][1001];

int solve(int i,int j){
    if(i==0 && j==0) return 1;
    if(i<0 || j<0 || grid[i][j] =='*') return 0;
    
    if(dp[i][j] !=-1 ) return dp[i][j];

    int up = solve(i,j-1);
    int left = solve(i-1,j);

    return dp[i][j] = (up + left)%mod;
}

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n;

    for(int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> grid[i][j];
        }
    }

    memset(dp,-1,sizeof(dp));

    if(grid[0][0] == '*') cout << "0" << endl;
    else cout << solve(n-1,n-1) << endl;
        

    return 0;
} */