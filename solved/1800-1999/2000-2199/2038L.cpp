#include <bits/stdc++.h>
using namespace std;

/*
 *  Can be reduced to another problem where we want to get 3 items of different quantity
 *  but for each step we can only get a preset number of items combinations
 *  Our target is to get (n, n, n). Call the Plank 18, 21, 25 as plank A, B, C.
 *
 *  7 possible combis. (3, 0, 0), (2, 1, 0), (1, 2, 0) (0, 1, 1), (1, 0, 1), (0, 1, 1), (0, 2, 0), (0, 0, 2)
 *
 *  Keep in mind two 2-cost step (3, 3, 0)
 *
 *  Try to pick combis with 3 plank as much as possible.
 *
 *  Split 3 case. n % 3 == 0, n % 3 == 1, n % 3 == 2.
 *  Case 1:
 *      Reduce Plank A, B to 0 by taking (3, 3, 0) as much as possible
 *      Reduce Plank C to 9 by taking (0, 0, 2) as much as possible
 *  Case 2:
 *      Reduce Plank A, B to 0 by taking (3, 3, 0) as much as possible
 *      At one point we are left with (1, 1, n)
 *      Take (1, 0, 1) and (0, 0, 1). so that we are left with (0, 0, n - 2)
 *      Reduce Plank C to 9 by taking (0, 0, 2) as much as possible
 *  Case 3:
 *      Reduce Plank A, B to 0 by taking (3, 3, 0) as much as possible
 *      At one point we are left with (2, 2, n)
 *      Take (1, 2, 0). so that we are left with (1, 0, n)
 *      Then take (1, 0, 1). so that we are left with (0, 0, n - 1)
 *      Reduce Plank C to 9 by taking (0, 0, 2) as much as possible
 *
 *  Can actually be reduce into the math equation. n + ceil(n / 6);
*/

void solve() {
    int n;
    cin >> n;
    int ans = 0;
    if (n == 1) {
        cout << 2 << endl;
        return;
    };
    if (n == 2) {
        cout << 3 << endl;
        return;
    }
    int leftover = n % 3;
    if (leftover == 0) {
        ans += 2 * (n / 3);
        ans += (n + 1) / 2;
    } else if (leftover == 1) {
        ans += 2 * (n / 3);
        ans += 2;
        n -= 2;
        ans += (n + 1) / 2;
    } else {
        ans += 2 * (n / 3);
        ans += 2;
        n -= 1;
        ans += (n + 1) / 2;
    }
    cout << ans << endl;
}

void solve2() {
    int n;
    cin >> n;
    cout << n + (n + 5) / 6 << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}