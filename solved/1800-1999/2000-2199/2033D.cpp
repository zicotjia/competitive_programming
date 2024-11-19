#include <bits/stdc++.h>
using namespace std;

static const int MAXN = 100005;
static int dp[MAXN], arr[MAXN], last_seen[MAXN];
static long long prefix_sum[MAXN];

void solve() {
    int n;
    cin >> n;

    for(int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }

    fill(dp, dp + n + 1, 0);
    fill(last_seen, last_seen + n + 1, -1);

    // Use unordered_map with reserve to prevent rehashing
    unordered_map<long long, int> prefix_map;
    prefix_map.reserve(n + 1);
    prefix_map[0] = 0;

    prefix_sum[0] = 0;
    int max_subsequences = 0;

    for(int i = 1; i <= n; ++i) {
        prefix_sum[i] = prefix_sum[i-1] + arr[i];

        dp[i] = dp[i-1];

        auto it = prefix_map.find(prefix_sum[i]);
        if(it != prefix_map.end()) {
            dp[i] = max(dp[i], dp[it->second] + 1);
            max_subsequences = max(max_subsequences, dp[i]);
        }

        prefix_map[prefix_sum[i]] = i;
    }

    cout << max_subsequences << '\n';  // '\n' is faster than endl
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}