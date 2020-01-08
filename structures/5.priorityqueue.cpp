#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> arr, pushind;
vector<pair<int, int>> heap;

void siftUp(int k){
    while(heap[k] < heap[(k - 1) / 2]) {
        swap(arr[heap[k].second], arr[heap[(k - 1) / 2].second]);
        swap(heap[k], heap[(k - 1) / 2]);

        k = (k - 1) / 2;
    }
    return;
}

void siftDown(int k){
    while (2 * k + 1 < heap.size()) {
        int left = 2 * k + 1;
        int right = 2 * k + 2;
        int i = left;
        if ((right < heap.size()) && (heap[right] < heap[left])) {
            i = right;
        }
        if (heap[k] <= heap[i]) {
            break;
        }
        swap(arr[heap[k].second], arr[heap[i].second]);
        swap(heap[k], heap[i]);

        k = i;
    }
    return;
}

void insertheap(int key){
    arr.push_back(heap.size());
    heap.push_back({key, arr.size() - 1});
    siftUp(heap.size() - 1);
}

void extractmin() {
    if (heap.size() == 0) {
        cout << '*' << '\n';
    } else {
        cout << heap[0].first << '\n';
        swap(arr[heap[0].second], arr[heap[heap.size() - 1].second]);
        heap[0] = heap[heap.size() - 1];
        heap.pop_back();
        siftDown(0);
    }
}

void decreasekey(int m, int k) {
    heap[arr[m - 1]].first = k;
    siftUp(arr[m - 1]);
    siftDown(arr[m - 1]);
}

int main() {
    freopen("priorityqueue.in", "r", stdin);
    freopen("priorityqueue.out", "w", stdout);
    ios_base::sync_with_stdio(0);


    string s;
    int a; int x; int y;
    a = 0;
    x = 0; y = 0; int add = 0;
    while (cin >> s) {
        add++;
        if (s == "push") {
            cin >> a;
            insertheap(a);
            pushind.push_back(add);
        } else if (s == "extract-min") {
            extractmin();
        } else {
            cin >> x >> y;
            x = upper_bound(pushind.begin(), pushind.end(), x) - pushind.begin();
            decreasekey(x , y);
        }
    }
    return 0;
}