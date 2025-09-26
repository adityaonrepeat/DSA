#include <bits/stdc++.h>
#include <cmath>
using namespace std;
// #define int long long
#define endl '\n'
const int mod=1e9+7;
using ll = long long int;

int n,x;
vector<int> arr;
int dp[1000005];

void solve(int x){

    dp[0] = 1;

    for(int i=1; i<=x; i++) {
        for(int j=0 ; j<n; j++){
            if(i-arr[j]>=0) dp[i] += dp[(i-arr[j])]; // x<-> i; and j used in arr;
            dp[i] %= mod;
        }
    }

    cout << dp[x] << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n >> x;
    arr.resize(n);
    for(int i =0; i<n; i++) cin >> arr[i];
    
    // memset(dp,-1,sizeof(dp));
    // cout << solve(x) << endl;
    solve(x);

    return 0;
}





/* #include <bits/stdc++.h>
#include <cmath>
using namespace std;
#define int long long
#define endl '\n'
const int mod=1e9+7;
// using ll = long long int;

int n,x;
vector<int> arr;
int dp[1000005];

int solve(int x){
    if(x<0) return 0;
    if(x==0) return 1;

    if(dp[x] != -1) return dp[x];

    int ans = 0;
    for(int i=0; i<n; i++) {
        ans += (solve(x-arr[i]));
        ans%=mod;
    }

    return dp[x] = ans;
}

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n >> x;
    arr.resize(n);
    for(int i =0; i<n; i++) cin >> arr[i];
    
    memset(dp,-1,sizeof(dp));

    cout << solve(x) << endl;
       
    return 0;
} */