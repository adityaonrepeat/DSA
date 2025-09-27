#include <bits/stdc++.h>
#include <cmath>
using namespace std;
#define int long long
#define endl '\n'
const int mod=1e9+7;
const int INF = 1e9;
// using ll = long long int;

int n,m;
vector<int> arr;

void solve(){
    
    int dp[n+2][m+2];
    memset(dp,0,sizeof(dp));

    for (int i=1; i<=n; i++) {
        for(int x=1; x<=m; x++) {

            if(i == 1)
            {
                if(arr[i]==0 || arr[i] == x) dp[i][x] = 1;
                else dp[i][x] = 0;

            }
            else
            {
                if(arr[i] == 0 || arr[i] == x) dp[i][x] = ( (dp[i-1][x-1] + dp[i-1][x]) % mod + dp[i-1][x+1]) % mod;
                else dp[i][x] = 0;
            }

        }
    }
    int ans = 0;
    for(int x=1; x<=m; x++) ans = (ans + dp[n][x]) % mod;

    cout << ans << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n >> m;
    arr.resize(n+1);
        
    for(int i=1; i<=n; i++) cin>>arr[i];

    solve();

    return 0;
}