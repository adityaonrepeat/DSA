#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

template<typename T>
void print(const vector<T> &v) {
    for (const auto &el : v) {
        cout << el << " ";
    }
    cout << endl;
}

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> array(n+1, 0);
    for (int i=1; i<=n; i++) {
        cin >> array[i];
    }   
    vector<int> suffix(n+1, 0);
    suffix[n] = array[n];
    for (int i=n-1; i>=0; i--) {
        suffix[i] = suffix[i+1] + array[i];
    }
    int ans = 0, curIdx = 0;
    for (int i=1; i<=n; i++) {
        
        ans += (b*(array[i]-array[curIdx]));
        
        if (i<n) {
            if ((suffix[i+1]-(n-i)*array[curIdx])*b > a*(array[i]-array[curIdx]) + (suffix[i+1]-(n-i)*array[i])*b) {
                ans += (a*(array[i]-array[curIdx]));
                curIdx = i;
            }
        }
    }
    cout << ans << endl;
    
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
