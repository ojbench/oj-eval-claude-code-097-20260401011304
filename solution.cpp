#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        vector<int> arr;
        for (int i = 0; i < n; i++) {
            int val;
            cin >> val;
            if (val > 0) {  // Only consider positive values (ignore -1 nulls)
                arr.push_back(val);
            }
        }

        int cnt;
        cin >> cnt;

        // Sort in descending order and get kth largest
        sort(arr.begin(), arr.end(), greater<int>());

        if (cnt > 0 && cnt <= (int)arr.size()) {
            cout << arr[cnt - 1] << endl;
        }
    }

    return 0;
}
