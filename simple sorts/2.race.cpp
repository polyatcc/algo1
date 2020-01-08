#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <set>

using namespace std;

int w, h, k, n, x;
string s1, s2;
set<string> country;
vector<vector<string>> lns;
vector<pair<string, pair<int, string>>> arr;


void sort(int l, int r) {
    if (r == l + 1) {
        return;
    } else {
        sort(((l + r) / 2), r);
        sort(l, (l + r) / 2);
        vector<pair<string, pair<int, string>>> num;
        int a = l; int b = (l + r) / 2;
        while (a < b) {
            if (arr[a] <= arr[b]) {
                num.push_back(arr[a]);
                a++;
            } else {
                num.push_back(arr[b]);
                b++;
            }
            if (a >= (l + r) / 2) {
                for ( int i = b; i < r; i++) {
                    num.push_back(arr[i]);
                }
                break;
            }
            if (b >= r) {
                for ( int i = a; i < (l + r) / 2; i++) {
                    num.push_back(arr[i]);
                }
                break;
            }
        }
        for (int i = l; i < r; i++) {
            arr[i] = num[i - l];
        }
    }
}



int main() {
    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> s1;
        cin >> s2;
        /*
        if (country[s1] == 0) {
            vector<string> empty;
            empty.push_back(s2);
            lns.push_back(empty);
            country[s1] = lns.size();
        } else {
            lns[country[s1] - 1].push_back(s2);
        }
    }
    for(auto i = country.begin(); i != country.end(); i++) {
        cout << "=== " << (*i).first << " ===" << endl;
        for(int j = 0; j < lns[(*i).second - 1].size(); j++) {
            cout << lns[(*i).second - 1][j] << endl;
        }
    }
*/
        arr[i] = {s1, {i, s2}};
    }
    sort(0, n);
    for (int i = 0; i < n; i++) {
        if ((i > 0) && (arr[i - 1].first != arr[i].first)) {
            cout <<"=== " << arr[i].first << " ===" << endl;
            cout << arr[i].second.second << endl;
        } else if (i == 0){
            cout << "=== " << arr[i].first << " ===" << endl;
            cout << arr[i].second.second<< endl;
        } else {
            cout << arr[i].second.second << endl;
        }
    }
    return 0;
}