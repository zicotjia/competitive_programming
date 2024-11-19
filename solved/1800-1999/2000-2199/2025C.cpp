
#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n, k;
    cin >> n;
    cin >> k;
    vector<int> deck(n);
    for (int i = 0; i < n; i++) cin >> deck[i];
    sort(deck.begin(), deck.end());
    vector<pair<int, int>> freq_table;
    for (int i = 0; i < n; i++) {
        int curr_val = deck[i];
        int freq = 1;
        while (i < n - 1 && deck[i + 1] == curr_val) {
            freq++;
            i++;
        }
        freq_table.emplace_back(freq, curr_val);
    }
    int ans = 0;
    int left = 0;
    int right = 0;
    int acc_sum = 0;
    int num_distinct = 0;
    while (right < freq_table.size()) {
        acc_sum += freq_table[right].first;
        num_distinct++;
        if (right != 0 && freq_table[right].second - freq_table[right - 1].second != 1) {
            acc_sum = freq_table[right].first;
            left = right;
            num_distinct = 1;
        }
        while (num_distinct > k) {
            acc_sum -= freq_table[left].first;
            left++;
            num_distinct--;
        }
        if (num_distinct <= k) {
            ans = max(ans, acc_sum);
        }
        right++;
    }
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