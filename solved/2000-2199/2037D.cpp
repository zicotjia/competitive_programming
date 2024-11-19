#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n_hurdle, n_power, end;
    cin >> n_hurdle >> n_power >> end;
    vector<pair<int, int>> hurdles(n_hurdle);
    for (int i = 0; i < n_hurdle; i++) {
        int a, b;
        cin >> a >> b;
        hurdles[i] = {a, b};
    }
    // {position, power_up};
    queue<pair<int, int>> power_ups;
    for (int i = 0; i < n_power; i++) {
        int a, b;
        cin >> a >> b;
        power_ups.emplace(a, b);
    }
    int curr_strenght = 1;
    priority_queue<int> available_power_up;
    int ans = 0;
    for (pair<int, int> hurdle: hurdles) {
        int max_reachable = hurdle.first - 1;
        int required_strenght = hurdle.second - hurdle.first + 2;
        if (curr_strenght >= required_strenght) continue;
        while (!power_ups.empty() && power_ups.front().first <= max_reachable) {
            pair<int, int> p = power_ups.front();
            power_ups.pop();
            available_power_up.push(p.second);
        }
        while (required_strenght > curr_strenght) {
            if (available_power_up.empty()) {
                cout << -1 << endl;
                return;
            }
            int add = available_power_up.top();
            available_power_up.pop();
            curr_strenght += add;
            ans++;
        }
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