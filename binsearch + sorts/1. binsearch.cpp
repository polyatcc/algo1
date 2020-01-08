#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

vector<int> elem, srch;
int n, m;
vector<vector<int>> ans; //это будет вектор с векторами из 2х чиселок: первое и последнее вхождение в массив

int binsearchleft(int k) {
    int l = -1; int r = n;
    while (r - l > 1) {
       int m = (l + r) / 2;
       if (k <= elem[m]) {
             r = m;
       } else {
           l = m;
       }
    }
    if ((r != n) && (elem[r] == k)) {
        return r + 1;
    } else {
        return -1;
    }
}

int binsearchright(int k) {
    int l = -1; int r = n;
    while (r -l > 1) {
        int m = (l + r)  / 2;
        if (k >= elem[m]) {
            l = m;
        } else {
            r = m;
        }
    }
    if ((l != -1) && (elem[l] == k)) {
        return l + 1;
    } else {
        return -1;
    }
}

int main() {
    freopen("binsearch.in", "r", stdin);
    freopen("binsearch.out", "w", stdout);
    ios_base::sync_with_stdio();
    cin >> n;
    elem.resize(n);
    for(int i = 0; i < n; ++i) {
        cin >> elem[i];
    }
    cin >> m;
    srch.resize(m);
    for(int i = 0; i < m; ++i) {
        cin >> srch[i];
    }
    for(int i = 0; i < m; ++i) {
         cout << binsearchleft(srch[i]) << " ";
         cout << binsearchright(srch[i]) << endl;
    }


    return 0;
}