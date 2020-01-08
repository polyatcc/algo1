#include <iostream>
#include <vector>
#include <list>
using namespace std;

int value, c1, c2, n, r_ch, a, b, x, y, z, w, c, addnom, retadd;

vector<pair<int, pair <int, int>>> tree;
vector<pair<int, pair <int, int>>> couttree;
vector<int> ans, deeep;
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
int depth(int s) {
    if (tree[s].second.second != -1) {
        if (tree[s].second.first != -1) {
            int k1 = depth(tree[s].second.first);
            int k2 = depth(tree[s].second.second);
            deeep[s] = max(k1, k2) + 1;
            return max(k1, k2) + 1;
        } else {
            int k1 = depth(tree[s].second.second);
            deeep[s] = k1 + 1;
            return k1 + 1;
        }
    } else {
        if (tree[s].second.first != -1) {
            int k1 = depth(tree[s].second.first);
            deeep[s] = k1 + 1;
            return k1 + 1;
        }
    }
    deeep[s] = 1;
    return 1;
}

int real_depth(int v) {
    if (v == -1) {
        return 0;
    } else {
        return deeep[v];
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

int big_l_turn(int root) {
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
    deeep[a] = max(real_depth(w), real_depth(x)) + 1;
    deeep[b] = max(real_depth(y), real_depth(z)) + 1;
    deeep[c] = max(real_depth(a), real_depth(b)) + 1;
    return c;
}
int big_r_turn(int root) {
    a = root;
    b = tree[root].second.first;
    w = tree[root].second.second;
    c = tree[b].second.second;
    z = tree[b].second.first;
    x = tree[c].second.first;
    y = tree[c].second.second;
    pair<int, pair<int, int>> new_a = {tree[a].first, {y, w}};
    pair<int, pair<int, int>> new_b = {tree[b].first, {z, x}};
    pair<int, pair<int, int>> new_c = {tree[c].first, {b, a}};
    tree[a] = new_a;
    tree[b] = new_b;
    tree[c] = new_c;
    deeep[b] = max(real_depth(z), real_depth(x)) + 1;
    deeep[a] = max(real_depth(y), real_depth(w)) + 1;
    deeep[c] = max(real_depth(a), real_depth(b)) + 1;
    return c;
}

int l_turn(int root) {
    a = root;
    b = tree[root].second.second;
    x = tree[root].second.first;
    y = tree[b].second.first;
    z = tree[b].second.second;
    pair<int, pair<int, int>> new_a = {tree[a].first, {x, y}};
    pair<int, pair<int, int>> new_b = {tree[b].first, {root, z}};
    tree[a] = new_a;
    tree[b] = new_b;

    deeep[a] = max(real_depth(x), real_depth(y)) + 1;
    deeep[b] = max(real_depth(a), real_depth(z)) + 1;
    return b;
}
int r_turn(int root) {
    b = root;
    a = tree[root].second.first;
    x = tree[a].second.first;
    y = tree[a].second.second;
    z = tree[root].second.second;
    pair<int, pair<int, int>> new_b = {tree[b].first, {y, z}};
    pair<int, pair<int, int>> new_a = {tree[a].first, {x, b}};
    tree[a] = new_a;
    tree[b] = new_b;
    deeep[b] = max(real_depth(y), real_depth(z)) + 1;

    deeep[a] = max(real_depth(x), real_depth(b)) + 1;
    return a;
}

int add(int root, int kek) {
    a = root;
    if (kek < tree[a].first) {
        a = tree[a].second.first;
        if (a != -1) {
            retadd = add(a, kek);
            tree[root].second.first = retadd;
            deeep[root] = max(real_depth(tree[root].second.second), real_depth(tree[root].second.first)) + 1;
            ans[root] = real_depth(tree[root].second.second) - real_depth(tree[root].second.first);
            if (ans[root] == 2) {
                if (ans[tree[root].second.second] == -1) {
                    return big_l_turn(root);
                } else {
                    return l_turn(root);
                }
            }
            if (ans[root] == -2) {
                if (ans[tree[root].second.first] == 1) {
                    return big_r_turn(root);
                } else {
                    return r_turn(root);
                }
            }
            return root;
        } else {
            tree.push_back({addnom, {-1, -1}});
            tree[root].second.first = tree.size() - 1;
            deeep[root] = max(real_depth(tree[root].second.second), real_depth(tree[root].second.first)) + 1;
            ans[root] = real_depth(tree[root].second.second) - real_depth(tree[root].second.first);
            return root;
        }
    } else {
        if (kek > tree[a].first) {
            a = tree[a].second.second;
            if (a != -1) {
                retadd = add(a, kek);
                tree[root].second.second = retadd;
                deeep[root] = max(real_depth(tree[root].second.second), real_depth(tree[root].second.first)) + 1;
                ans[root] = real_depth(tree[root].second.second) - real_depth(tree[root].second.first);
                if (ans[root] == 2) {
                    if (ans[tree[root].second.second] == -1) {
                        return big_l_turn(root);
                    } else {
                        return l_turn(root);
                    }
                }
                if (ans[root] == -2) {
                    if (ans[tree[root].second.second] == 1) {
                        return big_r_turn(root);
                    } else {
                        return r_turn(root);
                    }
                }
                return root;
            } else {
                tree.push_back({addnom, {-1, -1}});
                tree[root].second.second = tree.size() - 1;
                deeep[root] = max(real_depth(tree[root].second.second), real_depth(tree[root].second.first)) + 1;
                ans[root] = real_depth(tree[root].second.second) - real_depth(tree[root].second.first);
                return root;
            }
        }
    }
}
int main() {
    freopen("addition.in", "r", stdin);
    freopen("addition.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n;
    ans.resize(n);
    deeep.resize(n + 1);
    deeep[n] = 1;
    if (n == 0) {
        cout << 1 << '\n';
    } else {
        cout << n + 1 << '\n';
        for (int i = 0; i < n; ++i) {
            cin >> value;
            cin >> c1;
            cin >> c2;
            tree.push_back({value, {c1 - 1, c2 - 1}});
        }
        height(0, 0);
        depth(0);
    }
    cin >> addnom;
    if (n == 0) {
        cout << addnom << " " << 0 << " " << 0;
    } else {
        retadd = add(0, addnom);
        print_tree(retadd, 0);
        for (int i = 0; i < couttree.size(); ++i) {
            cout << couttree[i].first << " " << couttree[i].second.first + 1 << " "<< couttree[i].second.second + 1 << '\n';
        }
    }

    return 0;
}
