#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int M = 1e9 + 7;

ll mod(ll x){
    return (x % M + M) % M;
}

ll add(ll a, ll b){
    return mod(mod(a) + mod(b));
}

ll mul(ll a, ll b){
    return mod(mod(a) * mod(b));
}

ll modPow(ll a, ll b){
    ll res = 1;
    while(b){
        if(b & 1) res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

ll ok(ll n){
    return (n * (n + 1)) / 2;
}

void solve(){
    int n, q;
    cin >> n >> q;

    vector<ll> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    ll total = 0;
    int flip = 0;

    for(int i = 1; i < n; i++){
        if(flip == 0){
            if(a[i] <= a[i - 1]){
                total += a[i - 1];
                flip = 1;
            }
        }
        else{
            if(a[i] >= a[i - 1]){
                total -= a[i - 1];
                flip = 0;
            }
        }
    }

    if(flip == 0)
        total += a[n - 1];

    cout << total << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
