#include <iostream>
#include <vector>
#include <list>

using namespace std;

int x;
int p = 1e6+3;
string s;
vector <list <int>> arr; // list, placed?


void ins(int d) {
    int now = (d % p + p) % p;
    if (arr[now].size() != 0) {
        int povt = 0;
        for (auto i = arr[now].begin(); i != arr[now].end(); ++i) {
            if (*i == d) {
                povt = 1;
                break;
            }
        }
        if (povt == 0) {
            arr[now].push_back(d);
        }
    } else {
        arr[now].push_back(d);
    }
}

void del(int k) {
    int now = (k % p + p) % p;
    if (arr[now].size() != 0) {
        int mu = 0; auto pos = arr[now].begin() ;
        for (auto i = arr[now].begin(); i != arr[now].end(); ++i) {
            if (*i == k) {
                mu = 1; pos = i;
                break;
            }
        }
        if (mu == 1) {
            arr[now].erase(pos);
        }
    }
}

void ex(int e) {
    int now = (e % p + p) % p;
    if (arr[now].size()== 0 ) {
        cout << "false" << '\n';
    }  else {
        int check = 0;
        for (auto i = arr[now].begin(); i != arr[now].end(); ++i) {
            if (*i == e) {
                check = 1;
                break;
            }
        }
        if (check == 1) {
            cout << "true" << '\n';
        } else {
            cout << "false" << '\n';
        }
    }

}


int main() {
    freopen("set.in", "r", stdin);
    freopen("set.out", "w", stdout);
    ios_base::sync_with_stdio(0);

    arr.resize(p);
    while (cin >> s) {
        if (s == "insert") {
            cin >> x;
            ins(x);
        } else if (s == "delete") {
            cin >> x;
            del(x);
        } else if (s == "exists") {
            cin >> x;
            ex(x);
        }
    }
    return 0;
}