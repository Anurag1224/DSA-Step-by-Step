#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int peakIndex = -1;
    for (int i = 1; i + 1 < n; i++) {
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
            peakIndex = i;
            break;
        }
    }

    cout << peakIndex << '\n';
    return 0;
}
