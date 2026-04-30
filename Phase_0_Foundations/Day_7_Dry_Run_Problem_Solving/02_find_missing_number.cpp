#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<int> arr(n - 1);
    long long sum = 0;
    for (int i = 0; i < n - 1; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    long long expected = 1LL * n * (n + 1) / 2;
    cout << (expected - sum) << '\n';
    return 0;
}
