#include <iostream>
#include <vector>
#include <list>
#include <set>
using namespace std;

int value, c1, c2, n;

vector<pair<int, pair <int, int>>> tree;
vector<int> ans;
int height(int k, int d) {
    if (tree[k].second.first != -1) {
        if (tree[k].second.second != - 1) {
            int l1 = height(tree[k].second.second, d + 1);
            int r1 = height( tree[k].second.first, d + 1);
            int ans1 = l1- r1;
            ans[k] = ans1;
            return max(r1, l1);
        } else {
            ans[k] = - height( tree[k].second.first, d + 1) + d;
            return -ans[k] + d;
        }
    } else {
        if (tree[k].second.second != -1) {
            ans[k] =  height(tree[k].second.second, d + 1) - d;
            return ans[k] + d;
        } else {
            ans[k] = 0;
            return d;
        }
    }
}

int main() {
    freopen("balance.in", "r", stdin);
    freopen("balance.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n;
    ans.resize(n);
    if (n == 0) {
        cout << 0;
    } else {
        for (int i = 0; i < n; ++i) {
            cin >> value;
            cin >> c1;
            cin >> c2;
            tree.push_back({value, {c1 - 1, c2 - 1}});
        }
        height(0, 0);
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << '\n';
        }
    }
    return 0;
}