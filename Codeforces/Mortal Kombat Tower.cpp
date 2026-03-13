// https://codeforces.com/problemset/problem/1418/C

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

int minSkips(int index, int frend, int own, vector<int>& array, vector<vector<vector<int>>>& dp) {
    if (index == array.size()) return 0;
    if (dp[index][frend][own]!=-1) return dp[index][frend][own];
    int skips = INT_MAX;
    if (own!=2) skips = min(skips, minSkips(index+1, 0, own+1, array, dp));
    if (frend!=2) {
        if (array[index]==0) skips = min(skips, minSkips(index+1, frend+1, 0, array, dp));
        else skips = min(skips, 1+minSkips(index+1, frend+1, 0, array, dp));
    }
    return dp[index][frend][own] = skips;
}

void solve() {
    int n;
    cin >> n;
    vector<int> array(n);
    for (int i=0; i<n; i++) {
        cin >> array[i];
    }   
    
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(3, vector<int>(3, INT_MAX)));
    for (int i=0; i<3; i++) { // Base case
        for (int j=0; j<3; j++) {
            dp[n][i][j] = 0;
        }
    }
    for (int i=n-1; i>=0; i--) {
        for (int j=0; j<3; j++) {
            for (int k=0; k<3; k++) {
                if (j!=2) dp[i][j][k] = min(dp[i][j][k], dp[i+1][j+1][0]);
                if (k!=2) {
                    if (array[i] == 1) dp[i][j][k] = min(dp[i][j][k], dp[i+1][0][k+1]+1);
                    else dp[i][j][k] = min(dp[i][j][k], dp[i+1][0][k+1]);
                }
            }
        }
    }
    cout << dp[0][0][2] << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--){
        solve();
    }
    
    return 0;
}
