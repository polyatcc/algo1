#include <iostream>
#include <vector>
#include <string>


using namespace std;

int n, m, k;
vector<string> arr;
vector<string>  diff;
vector<vector<string>>add;


void sort(int l){

    add.resize(26);
    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < 26; ++j) {
            add[j].resize(0);
        }
        for (int j = 0; j < n; ++j) {
            char h = arr[j][arr[j].size() - i - 1];
            int d = (int)h - (int)'a';
            add[d].push_back(arr[j]);
        }
        int v = 0;
        for (int j = 0; j < 26; ++j){
            int d = (int)'a' + j;
            for (int f = 0; f < add[j].size(); ++f){
                arr[v] = add[j][f];
                ++v;
            }
        }

    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    //freopen("radixsort.in", "r", stdin);
    //freopen("radixsort.out", "w", stdout);
    cin >> n; cin >> m; cin >> k;
    arr.resize(n);
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(k);
    for(int i = 0; i < n; ++i) {
        cout << arr[i] << endl;

    }
    return 0;
}