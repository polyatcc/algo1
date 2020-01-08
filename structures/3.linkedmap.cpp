#include <iostream>
#include <vector>
#include <list>

using namespace std;

const long long p1 = 31;

long long p = 1e6+3;

struct node {
    node* pr;
    node* nex;
    string now;

    node(string now) {
        this->now = now;
        this->nex = nullptr;
        this->pr = nullptr;
    }
};
node*last = nullptr;
string a, b, s;
vector <list<pair<node*, string>>> arr; // list, placed?


long long hashi (string &s) {
    long long hash = 0, p_pow = 1;
    for (char i : s) {
        hash += (i - 'A'  + 1) * p_pow;
        hash %= p;
        p_pow *= p1;
        p_pow %= p;
    }
    return hash;
}


void ins(string &k, string &d) {
    long long now = hashi(k);
    if (!arr[now].empty()) {
        string povt = "";
        for (auto & i : arr[now]) {
            if (i.first->now == k) {
                i.second = d;
                povt = "keklolbye";
                break;
            }
        }
        if (povt == "") {
            node * nex = new node(k);
            nex->pr = last;
            if (last != nullptr) {
                last->nex = nex;
            }
            last = nex;
            arr[now].push_back({nex, d});
        }
    } else {
        node * nex = new node(k);
        nex->pr = last;
        if (last != nullptr) {
            last->nex = nex;
        }
        last = nex;
        arr[now].push_back({nex, d});
    }
}

void del(string &k) {
    long long now = hashi(k);
    if (!arr[now].empty()) {
        long long mu = 0; auto pos = arr[now].begin() ;
        for (auto i = arr[now].begin(); i != arr[now].end(); ++i) {
            if ((*i).first->now == k) {
                mu = 1; pos = i;
                break;
            }
        }
        if (mu == 1) {
            node * to_del = (*pos).first;
            arr[now].erase(pos);
            if (to_del->nex != nullptr) {
                if (to_del->pr != nullptr) {
                    to_del->pr->nex = to_del->nex;
                    to_del->nex->pr = to_del->pr;
                    to_del->pr = nullptr;
                    to_del->nex = nullptr;
                    delete(to_del);
                } else {
                    to_del->nex->pr = nullptr;
                    to_del->nex = nullptr;
                    delete(to_del);
                }
            } else {
                if (to_del->pr != nullptr) {
                    to_del->pr->nex = nullptr;
                    last = to_del->pr;
                    to_del->pr = nullptr;
                    delete(to_del);
                } else {
                    last = nullptr;
                    delete(to_del);
                }
            }
        }
    }
}

void ex(string &e) {
    long long now = hashi(e);
    if (arr[now].empty() ) {
        cout << "none" << '\n';
    }  else {
        string check = "";
        for (auto & i : arr[now]) {
            if (i.first->now == e) {
                check = i.second;
                break;
            }
        }
        if (check != "") {
            cout << check << '\n';
        } else {
            cout << "none" << '\n';
        }
    }
}
void prev (string &l) {
    long long now = hashi(l);
    if (arr[now].empty() ) {
        cout << "none" << '\n';
    }  else {
        node * check = nullptr;
        for (auto & i : arr[now]) {
            if (i.first->now == l) {
                check = i.first->pr;
                break;
            }
        }
        if (check != nullptr) {
            ex(check->now);
        } else {
            cout << "none" << '\n';
        }
    }
}

void next (string &l) {
    long long now = hashi(l);
    if (arr[now].empty() ) {
        cout << "none" << '\n';
    }  else {
        node * check = nullptr;
        for (auto & i : arr[now]) {
            if (i.first->now == l) {
                check = i.first->nex;
                break;
            }
        }
        if (check != nullptr) {
            ex(check->now);
        } else {
            cout << "none" << '\n';
        }
    }
}



 int main() {
    freopen("linkedmap.in", "r", stdin);
    freopen("linkedmap.out", "w", stdout);
    ios_base::sync_with_stdio(0);

    arr.resize(p);
    while (cin >> s) {
        if (s == "put") {
            cin >> a; cin >> b;
            ins(a, b);
        } else if (s == "delete") {
            cin >> a;
            del(a);
        } else if (s == "get") {
            cin >> a;
            ex(a);
        } else if (s == "prev") {
            cin >> a;
            prev(a);
        } else if (s == "next") {
            cin >> a;
            next(a);
        }
    }
    return 0;
}
