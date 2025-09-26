#include <bits/stdc++.h>
#include <cmath>
using namespace std;
// #define int long long
#define endl '\n'
const int mod=1e9+7;
const int INF = 1e9;
using ll = long long int;

int n,x;
vector<int> prices;
vector<int> pages;

void solve(){

    vector<vector<int>> dp(n+1,vector<int>(x+1,0));
    // B.C. = dp[0][anything] = 0;
    
    for (int i=1; i<=n; i++) {
        for (int j=0; j<=x; j++) {

            
            int take = -INF, notTake = -INF;

            if(i>=1) notTake = dp[i-1][j];
            if(i>=1 && j>=prices[i-1]) take = dp[i-1][j-prices[i-1]] + pages[i-1];
                
            dp[i][j] = max( take , notTake );
            
        }
    }

    cout << dp[n][x] << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n >> x;

    prices.resize(n);
    pages.resize(n);

    for (int i=0; i<n; i++) cin >> prices[i];
    for (int i=0; i<n; i++) cin >> pages[i];

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

int n,x;
vector<int> prices;
vector<int> pages;

void solve(){

    vector<vector<int>> dp(n+1,vector<int>(x+1,-INF));
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<=x; j++) {

            if(j==0) dp[i][j] = 0;
            else {
                int take = 0, notTake = 0;

                if(i>=1) notTake = dp[i-1][j];
                if(i>=1 && j>=prices[i-1]) take = dp[i-1][j-prices[i-1]] + pages[i-1];
                
                dp[i][j] = max( take , notTake );
            }
        }
    }

    cout << dp[n-1][x] << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n >> x;

    prices.resize(n);
    pages.resize(n);

    for (int i=0; i<n; i++) cin >> prices[i];
    for (int i=0; i<n; i++) cin >> pages[i];

    solve();

    return 0;
} */

/* #include <bits/stdc++.h>
#include <cmath>
using namespace std;
// #define int long long
#define endl '\n'
const int mod=1e9+7;
const int INF = 1e9;
using ll = long long int;

int n,x;
vector<int> prices;
vector<int> pages;

void solve(){

    vector<vector<int>> dp(n+1,vector<int>(x+1,-INF));
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<=x; j++) {

            if(j==0) dp[i][j] = 0;
            else {
                int take = 0, notTake = 0;

                if(i>=1) notTake = dp[i-1][j];
                if(i>=1 && j>=prices[i-1]) take = dp[i-1][j-prices[i-1]] + pages[i-1];
                
                dp[i][j] = max( take , notTake );
            }
        }
    }

    cout << dp[n-1][x] << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n >> x;

    prices.resize(n);
    pages.resize(n);

    for (int i=0; i<n; i++) cin >> prices[i];
    for (int i=0; i<n; i++) cin >> pages[i];

    solve();

    return 0;
} */



// AI LORE : ->

/* 
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

int n, x;
vector<int> prices;
vector<int> pages;

void solve() {
    vector<vector<int>> dp(n, vector<int>(x+1, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= x; j++) {
            // Base case: if budget = 0 -> no pages
            if (j == 0) {
                dp[i][j] = 0;
                continue;
            }

            // Case 1: skip current book
            if (i > 0) dp[i][j] = dp[i-1][j];

            // Case 2: take current book (if possible)
            if (j >= prices[i]) {
                if (i > 0)
                    dp[i][j] = max(dp[i][j], dp[i-1][j - prices[i]] + pages[i]);
                else
                    dp[i][j] = max(dp[i][j], pages[i]); // only book 0
            }
        }
    }

    cout << dp[n-1][x] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> x;
    prices.resize(n);
    pages.resize(n);
    for (int i = 0; i < n; i++) cin >> prices[i];
    for (int i = 0; i < n; i++) cin >> pages[i];

    solve();
    return 0;
}

*/