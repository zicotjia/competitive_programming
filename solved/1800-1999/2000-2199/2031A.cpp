#include <bits/stdc++.h>
using namespace std;

void tower(vector<int>& arr) {
    int n = arr.size();
    unordered_map<int, int> mp;
    int ans = n;
    for (int val: arr) {
        mp[val]++;
        ans = min(ans, n - mp[val]);
    }
    std::cout << ans << std::endl;
}


int main() {
    int tc;
    std::cin >> tc;
    for (int i = 0; i < tc; i++) {
        int len;
        std::cin >> len;
        std::vector<int> arr(len);
        for (int j = 0; j < len; j++) {
            std::cin >> arr[j];
        }
        tower(arr);
    }

    return 0;
}
