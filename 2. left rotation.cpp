#include <iostream>
#include <vector>
#include <list>
using namespace std;

int value, c1, c2, n, r_ch, a, b, x, y, z, w, c;

vector<pair<int, pair <int, int>>> tree;
vector<pair<int, pair <int, int>>> couttree;
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
int print_tree(int s, int numbcout) {
    if (tree[s].second.first != -1) {
        couttree.push_back({tree[s].first, {numbcout + 1, -1}});
        int next_line = print_tree(tree[s].second.first, numbcout + 1);
        if (tree[s].second.second != -1) {
            couttree[numbcout].second.second = next_line + 1;
            return print_tree(tree[s].second.second, next_line + 1);
        } else {
            return next_line;
        }
    } else {
        if (tree[s].second.second != -1) {
            couttree.push_back({tree[s].first, {-1, numbcout + 1}});
            return print_tree(tree[s].second.second, numbcout + 1);
        } else {
            couttree.push_back({tree[s].first, {-1, -1}});
            return numbcout;
        }
    }

}

void big_l_turn(int root) {
    a = root;
    b = tree[root].second.second;
    w = tree[root].second.first;
    c = tree[b].second.first;
    z = tree[b].second.second;
    x = tree[c].second.first;
    y = tree[c].second.second;
    pair<int, pair<int, int>> new_a = {tree[a].first, {w, x}};
    pair<int, pair<int, int>> new_b = {tree[b].first, {y, z}};
    pair<int, pair<int, int>> new_c = {tree[c].first, {a, b}};
    tree[a] = new_a;
    tree[b] = new_b;
    tree[c] = new_c;
    print_tree(c, 0);
    for (int i = 0; i < couttree.size(); ++i) {
        cout << couttree[i].first << " " << couttree[i].second.first + 1 << " "<< couttree[i].second.second + 1 << '\n';
    }
}

void l_turn(int root) {
    a = root;
    b = tree[root].second.second;
    x = tree[root].second.first;
    y = tree[b].second.first;
    z = tree[b].second.second;
    pair<int, pair<int, int>> new_a = {tree[a].first, {x, y}};
    pair<int, pair<int, int>> new_b = {tree[b].first, {root, z}};
    tree[a] = new_a;
    tree[b] = new_b;
    print_tree(b, 0);
    for (int i = 0; i < couttree.size(); ++i) {
        cout << couttree[i].first << " " << couttree[i].second.first + 1 << " "<< couttree[i].second.second + 1 << '\n';
    }
}



int main() {
   freopen("rotation.in", "r", stdin);
   freopen("rotation.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n;
    ans.resize(n);
    cout << n << '\n';
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
        //for (int i = 0; i < n; ++i) {
          //  cout << ans[i] << '\n';
        //}
        r_ch = tree[0].second.second;
        if (ans[r_ch] == - 1) {
            big_l_turn(0);
        } else {
            l_turn(0);
        }
    }
    return 0;
}