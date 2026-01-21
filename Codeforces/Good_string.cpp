// https://codeforces.com/problemset/problem/1165/C
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        if (n == 1) {
            cout << 0 << '\n';
            continue;
        }

        int left = 0, right = n - 1;

        // count '<' from left
        while (left < n && s[left] == '<') {
            left++;
        }

        // count '>' from right
        while (right >= 0 && s[right] == '>') {
            right--;
        }

        int cntLeft = left;
        int cntRight = (n - 1) - right;

        cout << min(cntLeft, cntRight) << '\n';
    }

    return 0;
}
