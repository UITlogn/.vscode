#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long

const int MOD = 1e9+7;
string n;
int l, r, k;

namespace sub1 {
    bool check(int x) {
        if (x % k != 0) return 0;
        int sum = 0;
        while (x) sum += x % 10, x /= 10;
        return sum % k == 0;
    }
    void solve() {
        int ans = 0;
        for (int i = l; i <= r; ++i)
            if (check(i))
                ++ans;
        cout << ans;
        exit(0);
    }
}

namespace sub2 {
    int dp[12][12*9][10005];
    int x;
    int calc(int i, int low, int sum, int num) {
        if (i < 0) {
            return sum % k == 0 && num == 0;
        }
        if (low == 1 && dp[i][sum][num] != -1) {
            return dp[i][sum][num];
        }

        int lim = (low ? 9 : n[i] - '0');
        int res = 0;
        for (int c = 0; c <= lim; ++c) {
            res += calc(i - 1, low | (c < lim), sum + c, (num * 10 + c) % k);
            res %= MOD;
        }
        if (low == 1) dp[i][sum][num] = res;
        return res;
    }

    void solve() {   
        memset(dp, -1, sizeof dp);
        n = to_string(l - 1);
        reverse(n.begin(), n.end());
        int ans1 = calc(n.size() - 1, 0, 0, 0);
        int flag = 0;

        n = to_string(r);
        reverse(n.begin(), n.end());
        int ans2 = calc(n.size() - 1, 0, 0, 0);

        int ans = ans2 - ans1 + flag;
        
        cout << ans;
        exit(0);
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("dpdigit.inp", "r", stdin);
    freopen("dpdigit.out", "w", stdout);

    cin >> l >> r >> k;

    // if (r <= 1e6) sub1::solve();

    sub2::solve();

    return 0;
}