#include <bits/stdc++.h>
#include <cmath>
using namespace std;
// #define int long long
#define endl '\n'
const int mod=1e9+7;
using ll = long long int;

int n,m;
vector<int> piles;

bool check(int jWorm,int m){       //000011111
    return jWorm <= piles[m];
}

void solve(int jWorm,int n){
    int l =0, r =n-1, ans =0;

    while(l<=r) {
        int m = (l+r)/2;

        if(check(jWorm,m)) {
            ans = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    cout << ans+1 << endl; // 1- based
}

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>> arr[i];

    cin >> m;
    vector<int> juicyWorms(m);
    for(int i=0; i<m; i++) cin>> juicyWorms[i];

    // created the piles
    piles.resize(n);
    piles[0] = arr[0];
    for(int i=1; i<n; i++) piles[i] = piles[i-1] + arr[i];


    int t=0 ;
    while(t<m)
        solve(juicyWorms[t++],n);
       
    return 0;
}