#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

vector<long double> h;
long double a, ans;
int n;

int main() {
    freopen("garland.in", "r", stdin);
    freopen("garland.out", "w", stdout);
    ios_base::sync_with_stdio();

    cin >> n;
    cin >> a;
    long double l = a; long double r = 0;
    ans = a;

    for (int i = 0; i < 444; i++) {
        long double m = (l + r) / 2;
        int flag = 1;
        h.clear();
        h.push_back(a);
        h.push_back(m);
        for (int i = 2; i < n; ++i) {
            long double height = 2 * h[i - 1] - h[i - 2] + 2;
            if (height >= 0) {
                h.push_back(height);
            } else {
                r = m;
                flag = 0;
                break;
            }
        }
        if (flag) {
            l = m;
        }
    }
    h.clear();
    h.push_back(a);
    h.push_back(l);
    for (int i = 2; i < n; ++i) {
        h.push_back(2 * h[i - 1] - h[i - 2] + 2);
    }
    if (n == 2) {
        cout << "0.00";
    } else {
        //cout.precision(50);
        //cout << h[n - 1];
        cout << fixed << setprecision(2) << h[n - 1];

    }
    return 0;
}