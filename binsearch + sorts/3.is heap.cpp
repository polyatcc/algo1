#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

vector<int> elem, srch;
int n, m, ans;
float a;


int main() {
    freopen("isheap.in", "r", stdin);
    freopen("isheap.out", "w", stdout);
    ios_base::sync_with_stdio();
    cin >> n;
    elem.resize(n + 1);
    for(int i = 1; i < n + 1; ++i) {
        cin >> elem[i];
    }
    ans = 0;
    for(int i = 1; i < ((n - 1) / 2); ++i) {
        if ((elem[i] >= elem[2 * i]) || (elem[i] >= elem[2 * i + 1])) {
            ans = -1;
        }
    }
    if ((elem[n / 2] >= elem[n])) {
         ans = -1;
    }
    if (ans == -1) {
        cout << "NO";
    } else {
        cout << "YES";
    }
    return 0;
}