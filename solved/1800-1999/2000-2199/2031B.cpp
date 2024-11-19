#include <bits/stdc++.h>
using namespace std;

void satay(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        if (abs(arr[i] - (i + 1)) > 1) {
            std::cout << "no" << std::endl;
            return;
        }
    }
    std::cout << "yes" << std::endl;
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
        satay(arr);
    }

    return 0;
}
