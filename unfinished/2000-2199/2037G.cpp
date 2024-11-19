#include <bits/stdc++.h>
using namespace std;

int mod = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> attractiveness(n);
    unordered_map<int, unordered_map<int, int>> memo;
    for (int i = 0; i < n; i++) {
        cin >> attractiveness[i];
    }
    vector<int> dp(n);
    dp[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        int num = 0;
        int att1 = attractiveness[i];
        for (int j = n - 1; j > i; j--) {
            int gcd;
            int att2 = attractiveness[i];
            int att_s = min(att2, att1);
            int att_b = max(att2, att1);
            if (memo.contains(att_s) && memo[att_s].contains(att_b)) {
                gcd = memo[att_s][att_b];
            } else {
                gcd = __gcd(att_s, att_b);
                memo[att_s][att_b] = gcd;
            }
            if (gcd != 1) {
                num += dp[j];
            }
        }
        dp[i] = num % mod;
    }
    std::cout << dp[0] << std::endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}