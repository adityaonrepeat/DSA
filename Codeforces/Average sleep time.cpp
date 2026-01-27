#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const ll lif = 1e9 + 7;        // long infinity
const int iif = 998244353;    // int infinity

// <--------------------------------------Fast IO----------------------------------------->
struct FastIO {
    static void fast() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
    }
};

// <--------------------------------------Pairs------------------------------------------->
struct Pair {
    int v1, v2;
    Pair(int _v1 = 0, int _v2 = 0) : v1(_v1), v2(_v2) {}
};

struct Pair2 {
    ll v1, v2;
    Pair2(ll _v1 = 0, ll _v2 = 0) : v1(_v1), v2(_v2) {}
};

// <--------------------------------------Helpers----------------------------------------->
ll mod(ll x) {
    return (x % lif + lif) % lif;
}

ll add(ll a, ll b) {
    return mod(mod(a) + mod(b));
}

ll fastPow(ll b, ll e) {
    ll res = 1;
    while (e > 0) {
        if (e & 1) res = (res * b) % lif;
        b = (b * b) % lif;
        e >>= 1;
    }
    return res;
}

bool odd(ll x) {
    return x & 1;
}

ll gcd(ll a, ll b) {
    if (b) return gcd(b, a % b);
    return a;
}

int gcd(int a, int b) {
    if (b) return gcd(b, a % b);
    return a;
}

ll kadane(int l, int r, vector<int>& nums) {
    ll sum = 0, mx = 0;
    for (int i = l; i < r; i++) {
        if (sum < 0) sum = nums[i];
        else sum += nums[i];
        mx = max(mx, sum);
    }
    return mx;
}

vector<int> sieve(int upto) {
    vector<int> primes(upto + 1, 1);
    for (int i = 2; i * i <= upto; i++) {
        if (primes[i]) {
            for (int j = i * i; j <= upto; j += i)
                primes[j] = 0;
        }
    }
    return primes;
}

vector<int> primeFactors(int n) {
    vector<int> res;
    auto p = sieve(n);
    for (int i = 2; i <= n; i++) {
        while (n % i == 0 && p[i]) {
            res.push_back(i);
            n /= i;
        }
    }
    return res;
}

ll getSum(int startNum, int diff, ll range) {
    ll lastNum = startNum + (range - 1) * diff;
    return range * (startNum + lastNum) / 2;
}

void print(bool cond) {
    cout << (cond ? "Yes\n" : "No\n");
}

// <--------------------------------------Main-------------------------------------------->
int main() {
    FastIO::fast();

    int testcases = 1;
    // cin >> testcases;

    while (testcases--) {
        /*
            Sliding window with running sum
        */
        int siz, k;
        cin >> siz >> k;

        vector<int> nums(siz);
        for (int i = 0; i < siz; i++) cin >> nums[i];

        ll sum = 0, res = 0;

        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }
        res += sum;

        for (int i = k; i < siz; i++) {
            sum -= nums[i - k];
            sum += nums[i];
            res += sum;
        }

        cout << fixed << setprecision(10)
             << (double)res / (siz - k + 1) << "\n";
    }

    return 0;
}
