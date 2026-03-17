
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

int dfs (int vertex, int par, vector<vector<int>>& g, int& ans) {
    int subtree_cnt = 0;
    for (int child : g[vertex]) {
        if (child == par) continue;
        subtree_cnt += dfs(child, vertex, g, ans);
    }
    if (subtree_cnt && (subtree_cnt+1)%2==0) {
        subtree_cnt = -1;
        ans++;
    }
    return subtree_cnt+1;
}

void solve() {
    int n, u, v;
    cin >> n;
    vector<vector<int>> g(n+1);
    for (int i=1; i<n; i++) {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }   
    if (n&1) {
        cout << -1 << endl;
        return;
    }
    int ans = 0;
    dfs(1, -1, g, ans);
    cout << ans-1 << endl; // -1 for vertex itself returning even
    
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--){
        solve();
    }
    
    return 0;
}
