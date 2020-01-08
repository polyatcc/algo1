#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;


int w, h, k, n;
vector<pair <long double, int>> mas, mas1;

void sort(int l, int r){
    if (r == l + 1) {
        return;
    } else {
        sort(((l + r) / 2), r);
        sort(l, (l + r) / 2);
        vector<pair <long double, int>> num;
        int a = l; int b = (l + r) / 2;
        while (a < b) {
            if (mas[a] <= mas[b]) {
                num.push_back(mas[a]);
                a++;
            } else {
                num.push_back(mas[b]);
                b++;
            }
            if (a >= (l + r) / 2) {
                for ( int i = b; i < r; i++) {
                    num.push_back(mas[i]);
                }
                break;
            }
            if (b >= r) {
                for ( int i = a; i < (l + r) / 2; i++) {
                    num.push_back(mas[i]);
                }
                break;
            }
        }
        for (int i = l; i < r; i++) {
            mas[i] = num[i - l];
        }
    }
}


int main() {
    freopen("sortland.in", "r", stdin);
    freopen("sortland.out", "w", stdout);

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    mas.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> mas[i].first;
        mas[i].second = i + 1;
    }
    sort(0, n);
    cout << mas[0].second << " " << mas[ n / 2].second << " " << mas[n - 1].second;


    return 0;
}