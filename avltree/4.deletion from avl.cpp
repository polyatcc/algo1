#include <bits/stdc++.h>

using namespace std;

class AVL_tree {
public:
    struct Node {
        int key;
        Node* left;
        Node* right;
        Node* parent;
        int height;
        Node() {
            key = -1;
            left = nullptr;
            right = nullptr;
            parent = nullptr;
            height = 1;
        };
    };
    Node* root;
    vector <Node> a;
    map <int, int> key_balance;
    Node* el = new Node;
    AVL_tree(int n) {
        root = nullptr;
        a.resize(n, *el);
    };

    void insert(int i, int x, int l, int r) {
        a[i].key = x;
        if (l != -1) {
            a[i].left = &a[l];
            a[l].parent = &a[i];
        }
        if (r != -1) {
            a[i].right = &a[r];
            a[r].parent = &a[i];
        }
        return;
    }

    void root_def() {
        for (int i = 0; i < a.size(); ++i) {
            if (a[i].parent == nullptr) {
                root = &a[i];
                break;
            }
        }
        return;
    }

    unsigned int heighttt(Node* v) {
        return v?v->height:0;
    }

    void depth(Node* v) {
        v->height = ((heighttt(v->left) > heighttt(v->right))?heighttt(v->left):heighttt(v->right)) + 1;
        return;
    }

    int get_balance(Node* v) {
        return heighttt(v->right) - heighttt(v->left);
    }

    void build_h() {
        queue <Node*> q;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i].left == nullptr && a[i].right == nullptr) {
                q.push(&a[i]);
            }
        }
        Node* v;
        int l_height, r_height;
        while (!q.empty()) {
            v = q.front();
            q.pop();
            l_height = heighttt(v->left);
            r_height = heighttt(v->right);
            key_balance[v->key] = r_height - l_height;
            if (v->parent != nullptr) {
                v->parent->height = max(v->height + 1, v->parent->height);
                q.push(v->parent);
            }
        }
        return;
    }

    Node* left_turn(Node* v) {
        Node* u = v->right;
        v->right = u->left;
        u->left = v;
        u->parent = v->parent;
        v->parent = u;
        if (v->right != nullptr) {
            v->right->parent = v;
        }
        depth(v);
        depth(u);
        return u;
    }

    Node* right_turn(Node* v) {
        Node* u = v->left;
        v->left = u->right;
        u->right = v;
        u->parent = v->parent;
        v->parent = u;
        if (v->left != nullptr) {
            v->left->parent = v;
        }
        depth(v);
        depth(u);
        return u;
    }

    Node* big_l_turn(Node* v) {
        v->right = right_turn(v->right);
        v->right->parent = v;
        v = left_turn(v);
        return v;
    }

    Node* big_r_turn(Node* v) {
        v->left = left_turn(v->left);
        v->left->parent = v;
        v = right_turn(v);
        return v;
    }

    void rec_upp(Node* temp) {
        while (temp != nullptr) {
            depth(temp);
            if (get_balance(temp) == 2) {
                if (get_balance(temp->right) == -1) {
                    temp = big_l_turn(temp);
                } else {
                    temp = left_turn(temp);
                }
            }

            if (get_balance(temp) == -2) {
                if (get_balance(temp->left) == 1) {
                    temp = big_r_turn(temp);
                } else{
                    temp = right_turn(temp);
                }
            }
            if (temp->parent != nullptr) {
                if (temp->parent->key > temp->key) {
                    temp->parent->left = temp;
                } else { temp->parent->right = temp; }
            } else { root = temp; }
            temp = temp->parent;
        }
        return;
    }
    
    void delete_el(int x) {
        if (heighttt(root) == 1) {
            root = nullptr;
            return;
        }
        Node* temp = root;
        while (temp->key != x) {
            if (x > temp->key) {
                temp = temp->right;
            } else { temp = temp->left; }
        }
        if (temp->left == nullptr && temp->right == nullptr) {
            if (temp->key < temp->parent->key) {
                temp->parent->left = nullptr;
            } else { temp->parent->right = nullptr; }
            rec_upp(temp->parent);
        } else if (temp->left == nullptr) {
            temp->key = temp->right->key;
            temp->right = nullptr;
            rec_upp(temp);
        } else {
            Node* max_left = temp->left;
            while (max_left->right != nullptr) {
                max_left = max_left->right;
            }
            temp->key = max_left->key;
            if (max_left->left == nullptr) {
                if (max_left->key <= max_left->parent->key) {
                    max_left->parent->left = nullptr;
                } else{max_left->parent->right = nullptr; }
                rec_upp(max_left->parent);
                delete max_left;
            } else {
                if (max_left->key <= max_left->parent->key) {
                    max_left->parent->left = max_left->left;
                    max_left->left->parent = max_left->parent;
                } else {
                    max_left->parent->right = max_left->left;
                    max_left->left->parent = max_left->parent;
                }
                rec_upp(max_left->parent);
                delete max_left;
            }
        }
        return;
    }

    void print_tree(int n) {
        cout << n;
        queue <Node*> q2;
        if (root != nullptr) {
            q2.push(root);
        }
        int q_size = 1;
        int i = 0;
        Node* v;
        while(!q2.empty()) {
            ++i;
            v = q2.front();
            q2.pop();
            --q_size;
            cout << endl << v->key << ' ';
            if (v->left != nullptr){
                q2.push(v->left);
                cout << i + q_size + 1 << ' ';
                ++q_size;
            } else{
                cout << 0 << ' ';
            }
            if (v->right != nullptr) {
                cout << i + q_size + 1;
                ++q_size;
                q2.push(v->right);
            }
            else{
                cout << 0;
            }
        }
    }
};
int main() {
    freopen("deletion.in", "r", stdin);
    freopen("deletion.out", "w", stdout);
    int n, x, l, r, y;
    cin >> n;
    AVL_tree tree(n);
    vector <int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> x >> l >> r;
        b[i] = x;
        tree.insert(i, x, l - 1, r - 1);
    }
    cin >> y;
    tree.root_def();
    tree.build_h();
    tree.delete_el(y);
    tree.print_tree(n - 1);
    return 0;
}
