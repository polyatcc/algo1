#include <iostream>
#include <vector>
#include <list>
#include <set>
using namespace std;

int value, c1, c2, n, minn, maxx;

vector<pair<int, pair <int, int>>> tree;

void height(int k, int l, int r) {
    if ((tree[k].first <= l) || (tree[k].first >= r)) {
        cout << "NO";
        exit(0);
    }
    if (tree[k].second.first != -1) {
        if (tree[k].second.second != - 1) {
            height(tree[k].second.first, l, tree[k].first);
            height(tree[k].second.second, tree[k].first, r);
        } else {
            height(tree[k].second.first, l, tree[k].first);
        }
    } else {
        if (tree[k].second.second != -1) {
            height(tree[k].second.second, tree[k].first, r);
        }
    }
}

int main() {
    freopen("check.in", "r", stdin);
    freopen("check.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n;
    if (n == 0) {
        cout << "YES";
        exit(0);
    } else {
        for (int i = 0; i < n; ++i) {
            cin >> value;
            cin >> c1;
            cin >> c2;
            tree.push_back({value, {c1 - 1, c2 - 1}});
        }
        minn = -1e9 - 1; maxx = 1e9 + 1;
        height(0, minn, maxx);
    }
    cout << "YES";
    return 0;
}
