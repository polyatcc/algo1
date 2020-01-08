#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;


int w, h, k;
vector<vector<int>> mas;
vector<int> kol;
/*void step(int i, int j, int k) {
    k = k + mas[i][j];
    if ((i == 0) && (j == 0)) {
        kol.push_back(k);
    }
    if ((i != 0) && (j != 0)) {
        step(i - 1, j, k);
        step(i, j - 1, k);
    } else {
        if ((i == 0) && (j != 0)) {
            step(i, j - 1, k);
        }
        if ((i != 0) && (j == 0)) {
            step(i - 1, j, k);
        }
    }
}
*/

int main() {
    freopen("turtle.in", "r", stdin);
    freopen("turtle.out", "w", stdout);

    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> h >> w;
    mas.resize(h);
    for (int i = 0; i < h; i++) {
        mas[h - i - 1].resize(w);
        for (int j = 0; j < w; j++) {
            cin >> mas[h - i - 1][j];
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++){
            if ((j ==0) && (i == 0)) {
                mas[i][j] = mas[i][j];
            }
            else if (i == 0) {
                mas[i][j] += mas[i][j - 1];
            }
            else if (j == 0) {
                mas[i][j] += mas[i - 1][j];
            } else {
                k = max(mas[i - 1][j], mas[i][j - 1]);
                mas[i][j] += k;
            }

        }
    }

    cout << mas[h - 1][w - 1];


    return 0;
}