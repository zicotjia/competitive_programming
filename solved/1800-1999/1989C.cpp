#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;
    vector<int> movie_a(n);
    for (int i = 0; i < n; i++) cin >> movie_a[i];
    vector<int> movie_b(n);
    for (int i = 0; i < n; i++) cin >> movie_b[i];
    int rate_a = 0;
    int rate_b = 0;
    int like_both = 0;
    int dislike_both = 0;
    for (int i = 0; i < n; i++) {
        if (movie_a[i] == movie_b[i]) {
            if (movie_a[i] == 1) like_both++;
            else if (movie_a[i] == -1) dislike_both++;
        } else {
            if (movie_a[i] > movie_b[i]) rate_a += movie_a[i];
            else if (movie_a[i] < movie_b[i]) rate_b += movie_b[i];
        }
    }
    int ans = -1e9;
    // Distribute the likes and dislikes
    for (int i = -dislike_both; i <= like_both; ++i) {
        ans = max(ans, min(rate_a + i, rate_b + (like_both - dislike_both - i)));
    }
    cout << ans << '\n';
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