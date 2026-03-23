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
    int n, q;
    cin >> n >> q;
    vector<int> array(n);
    for (int i=0; i<n; i++) {
        cin >> array[i];
    }   
    sort(all(array), greater<>());
    int l, r; 
    vector<int> pref(n+1, 0);
    for (int i=0; i<q; i++) {
        cin >> l >> r;
        l--; r--;
        pref[l] += 1;
        pref[r+1] -= 1;
    }
    for (int i=1; i<=n; i++) {
        pref[i] += pref[i-1];
    }
    sort(pref.begin(), pref.begin()+n, greater<>());
  
    int sum = 0;
    for (int i=0; i<n; i++) {
        sum += (pref[i]*array[i]);
    }
    cout << sum << endl;
    
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
