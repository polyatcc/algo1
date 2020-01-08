#include <iostream>
#include <vector>
#include <list>
#include <set>
using namespace std;

int value, c1, c2, n;

vector<pair<int, pair <int, int>>> tree;

int height(int k, int d) {
    if (tree[k].second.first != -1) {
        if (tree[k].second.second != - 1) {
            int ans1 = max(height( tree[k].second.first, d + 1), height(tree[k].second.second, d + 1));
            return ans1;
        } else {
            return height( tree[k].second.first, d + 1);
        }
    } else {
        if (tree[k].second.second != -1) {
            return height(tree[k].second.second, d + 1);
        } else {
            return d;
        }
    }
}

int main() {
    freopen("height.in", "r", stdin);
    freopen("height.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n;
    if (n == 0) {
        cout << 0;
    } else {
        for (int i = 0; i < n; ++i) {
            cin >> value;
            cin >> c1;
            cin >> c2;
            tree.push_back({value, {c1 - 1, c2 - 1}});
        }
        int ans = height(0, 1);
        cout << ans;
    }
    return 0;
}
