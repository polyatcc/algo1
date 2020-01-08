#include <iostream>
#include <vector>
#include <list>

using namespace std;

const long long p1 = 31;

long long p = 1e6+3;

string a, b, s;
vector <list<pair<string, string>>> arr; // list, placed?

long long hashi (string &s) {
    long long hash = 0, p_pow = 1;
    for (long long i = 0; i < s.size(); ++i) {
        hash += (s[i] - 'A'  + 1) * p_pow;
        hash %= p;
        p_pow *= p1;
        p_pow %= p;
    }
    return hash;
}


void ins(string &k, string &d) {
    long long now = hashi(k);
    if (arr[now].size() != 0) {
        string povt = "";
        for (auto i = arr[now].begin(); i != arr[now].end(); ++i) {
            if ((*i).first == k) {
                (*i).second = d;
                povt = "keklolbye";
                break;
            }
        }
        if (povt == "") {
            arr[now].push_back({k, d});
        }
    } else {
        arr[now].push_back({k, d});
    }
}

void del(string &k) {
    long long now = hashi(k);
    if (arr[now].size() != 0) {
        long long mu = 0; auto pos = arr[now].begin() ;
        for (auto i = arr[now].begin(); i != arr[now].end(); ++i) {
            if ((*i).first == k) {
                mu = 1; pos = i;
                break;
            }
        }
        if (mu == 1) {
            arr[now].erase(pos);
        }
    }
}

void ex(string &e) {
    long long now = hashi(e);
    if (arr[now].size()== 0 ) {
        cout << "none" << '\n';
    }  else {
        string check = "";
        for (auto i = arr[now].begin(); i != arr[now].end(); ++i) {
            if ((*i).first == e) {
                check = (*i).second;
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

 int main() {
    freopen("map.in", "r", stdin);
    freopen("map.out", "w", stdout);
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
        }
    }
    return 0;
}
