#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

int minDeletions(int index, vector<int>& array, vector<int>& dp) {
    if (index==array.size()) return 0;
    if (index > array.size()) return INT_MAX;
    if (dp[index]!=-1) return dp[index];
    int include = minDeletions(index+array[index]+1, array, dp);
    int notInclude = 1 + minDeletions(index+1, array, dp);
    return dp[index] = min(include, notInclude);    
}

void solve() {
    int n;
    cin >> n;
    vector<int> array(n);
    for (int i=0; i<n; i++) {
        cin >> array[i];
    }   

    vector<int> dp(n+1, INT_MAX);
    dp[n] = 0;
    for (int i=n-1; i>=0; i--) {
        dp[i] = min(dp[i], 1+dp[i+1]); // not include case
        if (i+array[i]+1 <= n) dp[i] = min(dp[i], dp[i+array[i]+1]); // include case
    }
    cout << dp[0] << endl;
    
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
