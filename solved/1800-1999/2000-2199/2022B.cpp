//
// Created by zicot on 11/17/2024.
//

#include <bits/stdc++.h>
using namespace std;


void solve() {
    long long n, k;
    cin >> n;
    cin >> k;
    vector<long long> cars(n);
    long long maxi = 0;
    for (int i = 0; i < n; i++) {
        cin >> cars[i];
        maxi = max(maxi, cars[i]);
    }
    long long sum = accumulate(cars.begin(), cars.end(), 0ll);
    long long ans = max((sum + k - 1)/k, maxi);
    std::cout << ans << std::endl;
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