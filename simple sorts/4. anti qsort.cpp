#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int n, k;
vector<int> arr;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("antiqs.in", "r", stdin);
    freopen("antiqs.out", "w", stdout);
    cin >> n ;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }

    for (int i = 0; i < n; i++) {
        swap(arr[i / 2], arr[i]);
    }
    for(int i = 0; i < n; i++) {
        cout << arr[i] + 1 << " ";
    }
    return 0;
}