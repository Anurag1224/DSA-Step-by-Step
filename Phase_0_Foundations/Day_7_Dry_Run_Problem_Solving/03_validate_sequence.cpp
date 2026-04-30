#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    bool valid = true;
    for (int i = 1; i < n; i++) {
        if (arr[i] <= arr[i - 1]) {
            valid = false;
            break;
        }
    }

    cout << (valid ? "VALID" : "INVALID") << '\n';
    return 0;
}
