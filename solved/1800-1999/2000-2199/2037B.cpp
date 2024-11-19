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
    vector<int> input(n);
    for (int i = 0; i < n ; i++) {
        cin >> input[i];
    }
    int target = n - 2;
    unordered_map<int, int> partner;
    for (int val : input) {
        if (val == 0) continue;
        if (partner.contains(val)) {
            cout << partner[val] << " " << val << endl;
            return;
        } else {
            if (target % val != 0) {
                continue;
            }
            int part = target / val;
            partner[part] = val;
        }
    }
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