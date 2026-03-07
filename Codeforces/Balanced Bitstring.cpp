#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

void solve() {
    int n, k;
    cin >> n >> k;
    string input;
    cin >> input;  
    for (int i=0; i<n; i++) {
        if (input[i]!='?' && input[i%k]=='?') input[i%k] = input[i];
    }
    for (int i=0; i<n; i++) {
        if (input[i]!='?' && input[i%k]!='?' && input[i]!=input[i%k]) {
            cout << "NO" << endl;
            return;
        }
    }
    int cnt0 = 0, cnt1 = 0;
    for (int i=0; i<k; i++) {
        if (input[i] == '0') cnt0++;
        else if (input[i] == '1') cnt1++;
    }
    if (cnt0>k/2 || cnt1>k/2) cout << "NO" << endl;
    else cout << "YES" << endl;
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
