//
// Created by zicot on 11/17/2024.
//
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, dmg, to_defeat;
    cin >> n >> dmg >> to_defeat;
    vector<int> hp(n);
    for (int i = 0; i < n; i++) {
        cin >> hp[i];
    }
    vector<int> position(n);
    for (int i = 0; i < n; i++) {
        cin >> position[i];
    }
    vector<pair<int, int>> enemies(n);
    for (int i = 0; i < n; i++) {
        enemies[i] = {position[i], hp[i]};
    }
    vector<int> valid_position;
    int att_range = ((dmg - 1) * 2 )+ 1;
    int left = 0;
    int right = to_defeat;
    while (right < n) {
        if (enemies[left].first + att_range - 1 >= enemies[right].first) {
            valid_position.push_back(enemies[left].first + dmg - 1);
        }
        left++;
        right++;
    }
    for (int pos: valid_position) {
        std::cout << pos << " ";
    }
    cout << endl;
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