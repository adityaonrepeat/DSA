#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    set < int > final;
    int count = 0;

    for (auto ch: s) {
        final.insert(ch);
        count += final.size();
    }

    cout << count << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
