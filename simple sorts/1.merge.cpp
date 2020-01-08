#include <vector>
#include <iostream>
#include <cstdio>

using namespace std;


int w, h, k, n;
vector<int> arr;

void sort(int l, int r){
    if (r == l + 1) {
        return;
    } else {
        sort(((l + r) / 2), r);
        sort(l, (l + r) / 2);
        vector<int> num;
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
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);

    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(0, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }


    return 0;
}