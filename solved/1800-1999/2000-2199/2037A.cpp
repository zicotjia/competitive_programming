//
// Created by zicot on 11/17/2024.
//
//
// Created by zicot on 11/17/2024.
//

#include <bits/stdc++.h>
using namespace std;

long long sum_h(long long start, long long end) {
    return ((start + end) * (end - start + 1)) / 2;
}

void solve() {
    int n;
    cin >> n;
    unordered_map<int, int> mp;
    int ans = 0;
    for (int i = 0; i < n ; i++) {
        int val;
        cin >> val;
        mp[val]++;
    }
    for (auto [key, val] : mp) ans += (val / 2);
    cout << ans << endl;
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