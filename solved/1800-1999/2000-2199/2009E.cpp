//
// Created by zicot on 11/17/2024.
//

#include <bits/stdc++.h>
using namespace std;

long long sum_h(long long start, long long end) {
    return ((start + end) * (end - start + 1)) / 2;
}

void solve() {
    long long n, k;
    cin >> n >> k;
    long long left = k;
    long long right = n + k - 1;
    long long first = left;
    long long last = right;
    long long curr = 0;
    while (left < right) {
        long long mid = left + (right - left) / 2;
        long long l_sum = sum_h(first, mid);
        long long r_sum = sum_h(mid + 1, last);
        if (l_sum == r_sum) {
            cout << 0 << endl;
            return;;
        } else if (l_sum < r_sum) {
            curr = mid;
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    long long l_sum = sum_h(first, curr);
    long long r_sum = sum_h(curr + 1, last);
    long long l_sum_2 = sum_h(first,  left);
    long long r_sum_2 = sum_h(left + 1, last);
    cout << min(abs(l_sum - r_sum), abs(l_sum_2 - r_sum_2)) << endl;
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