#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> col(n), row(m);
    for (int i=0; i<n; i++) {
        cin >> col[i];
    }    
    for (int i=0; i<m; i++) {
        cin >> row[i];
    }

    vector<int> factors;
    for (int i=1; i*i<=k; i++) {
        if (k%i==0) {
            factors.pb(i);
            if (i!=k/i) factors.pb(k/i);
        }
    }

    int cnt = 0;
    map<int,int> cols, rows;

    for (int i=0; i<n; i++) {
        if (col[i] == 1) cnt++;
        else {
            if(cnt) cols[cnt]++;
            cnt = 0;
        }
    }
    if(cnt) cols[cnt]++;

    cnt = 0;
    for (int i=0; i<m; i++) {
        if (row[i] == 1) cnt++;
        else {
            if(cnt) rows[cnt]++;
            cnt = 0;
        }
    }
    if(cnt) rows[cnt]++;

    int ans = 0;
    int f = factors.size();

    for (int factor = 0; factor < f; factor++) {
        for (auto x : cols) {
            if (x.first < factors[factor]) continue;
            for (auto y : rows) {
                if (y.first < k/factors[factor]) continue;
                int n1 = x.second*(x.first-factors[factor]+1);
                int n2 = y.second*(y.first-(k/factors[factor])+1);
                ans += (n1*n2);
            }
        }
    }

    cout << ans << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    while (t--){
        solve();
    }

    return 0;
}
