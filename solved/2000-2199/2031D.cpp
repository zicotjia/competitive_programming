#include <bits/stdc++.h>
using namespace std;



void findMaxHeights(const vector<int>& heights) {
    int n = heights.size();
    vector<int> prefix_max(n), suffix_min(n), ans(n);

    prefix_max[0] = heights[0];
    for (int i = 1; i < n; ++i) prefix_max[i] = max(prefix_max[i - 1], heights[i]);

    suffix_min[n - 1] = heights[n - 1];
    for (int i = n - 2; i >= 0; --i) suffix_min[i] = min(suffix_min[i + 1], heights[i]);


    // using the hint
    ans[n - 1] = prefix_max[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        // Can climb to a higher tree to the left which can go to tree i + 1
        if (prefix_max[i] > suffix_min[i + 1]) ans[i] = ans[i + 1];
        else  ans[i] = prefix_max[i];
    }

    for (int height: ans) {
        std::cout << height << " ";
    }
    std::cout << std::endl;
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
        findMaxHeights(arr);
    }

    return 0;
}
