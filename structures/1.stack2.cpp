#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

vector<int> h;
int u, m, k;
char s;


int main() {
    freopen("stack.in", "r", stdin);
    freopen("stack.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin >> m;
    h.resize(m);
    u = 0;
    for (int i = 0; i < m; i++) {
        cin >> s;
        if (s == '+') {
            cin >> k;
            h[u] = k;
            ++u;
        }
        if (s == '-') {
            cout << h[u - 1] << '\n';
            --u;
        }
    }
    return 0;
}