#include <bits/stdc++.h>
#include <cmath>
using namespace std;
// #define int long long
#define endl '\n'
const int mod=1e9+7;
const int INF = 1e9;
using ll = long long int;

int n;

void solve(){
    vector<int> dp(n+1,INF);
    dp[0] = 0;
    
    for (int i=1; i<=n; i++) {

        string num = to_string(i);
        int len = num.size();

        for (int j=0; j<len; j++) {

            if(num[j]!= '0') dp[i] = min(dp[i], 1 + dp[i-(num[j]-'0')] );
            // always change the var. in tabn
        }
    }

    cout << dp[n] << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n;
    solve();
       
    return 0;
}


/* #include <bits/stdc++.h>
#include <cmath>
using namespace std;
// #define int long long
#define endl '\n'
const int mod=1e9+7;
const int INF = 1e9;
using ll = long long int;

int n;
int dp[1000005];

int solve(int n){
    if(n==0) return 0;
    if(n<0) return INF;

    if(dp[n] != -1) return dp[n];

    string num = to_string(n);
    int len = num.size();

    int ans = INF;
    for (int i=0; i<len; i++) {

        if(num[i]!= '0') ans =min(ans, 1 + solve(n-(num[i]-'0')) );
    }

    return dp[n] = ans;

}

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n;
    memset(dp,-1,sizeof(dp));

    cout << solve(n) << endl;
       
    return 0;
} */