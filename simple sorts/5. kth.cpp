#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <deque>

using namespace std;


int a, b, c, f, s, n, k;
vector <int> arr;


int main() {
    freopen("kth.in", "r", stdin);
    freopen("kth.out", "w", stdout);
    ios_base::sync_with_stdio();
    cin >> n >> k;
    cin >> a >> b >> c >> f >> s;
    arr.resize(n);

    arr[0] = f;
    arr[1] = s;
    for (int i = 2; i < n; i++) {
        arr[i] = a * arr[i - 2] + b * arr[i - 1] + c;
    }

    int l = 0; int r = n; k--;

    while(true) {
        vector<int> comp;
        int mid = arr[(l + r) / 2];
        comp.resize(r - l);
        int a = 0; int b = r - l - 1;
        for (int i = l; i < r; ++i) {
            if (arr[i] == mid) {
                continue;
            }
            if (arr[i] < mid) {
                comp[a] = arr[i];
                a++;
            } else {
                comp[b] = arr[i];
                b--;
            }
        }
        for(int i = l; i < r; ++i) {
            arr[i] = comp[i - l];
        }
       if (k < a)  {
           r = a + l;
       } else if (k < (b + 1)) {
           cout << mid;
           break;
       } else {
           l = b + l + 1;
           k -= b + 1;
       }
    }


    return 0;
}

