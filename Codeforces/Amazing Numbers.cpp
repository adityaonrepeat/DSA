// Problem link - https://codeforces.com/problemset/problem/1416/A

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

void solve() {
    int n, input;
    cin >> n;
    map<int, vector<int>> mp;
    for (int i=0; i<n; i++) {
        cin >> input;
        mp[input].pb(i+1);
    }   
    vector<int> ans(n+1, -1);
    for (auto elem : mp) {
        int num = elem.first;
        auto vec = elem.second;
        int cur = 0; int maxi = 0;
        vec.pb(n+1);
        for (int i=0; i<vec.size(); i++) {
            maxi = max(maxi, vec[i]-cur);
            cur = vec[i];
        }
        for (int i=maxi; i<=n; i++) {
            if (ans[i] != -1) break;
            else ans[i] = num;
        }
    }
    for (int i=1; i<=n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

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
