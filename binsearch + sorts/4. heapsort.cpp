#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> arr, heap;

void siftUp(int k){
    while(heap[k] < heap[(k - 1) / 2]) {
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
        swap(heap[k], heap[i]);
        k = i;
    }
    return;
}

void insertheap(int key){
    heap.push_back(key);
    siftUp(heap.size() - 1);
}

int extract_first() {
    int ans = heap[0];
    heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    siftDown(0);
    return ans;
}

int main() {
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        insertheap(arr[i]);
    }
    for (int i = 0; i < n; ++i) {
        cout << extract_first() << " ";
    }
    return 0;
}