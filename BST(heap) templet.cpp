#include <bits/stdc++.h>
using namespace std;

class mheap {
    vector<int> heap;

    void heapify_down(int ind) {
        int n = heap.size();
        int left = 2 * ind + 1;
        int right = 2 * ind + 2;
        int value = heap[ind];
        int greater = ind;
        if (left < n && heap[left] > value) {
            value = heap[left];
            greater = left;
        }
        if (right < n && heap[right] > value) {
            value = heap[right];
            greater = right;
        }
        if (greater == ind) return;
        swap(heap[ind], heap[greater]);
        heapify_down(greater);
    }

    void heapify_up(int ind) {
        if (ind == 0) return;
        int parent = (ind - 1) / 2; // FIXED: add parentheses to correct order of operations
        if (heap[ind] > heap[parent]) {
            swap(heap[ind], heap[parent]);
            heapify_up(parent);
        }
    }

public:
    mheap(vector<int> v) {
        heap = v;
    }

    void build_head() {
        int n = heap.size();
        for (int i = (n / 2) - 1; i >= 0; i--) {
            heapify_down(i);
        }
    }

    int max_ele() {
        return heap[0];
    }

    void insert(int val) {
        heap.push_back(val);
        heapify_up(heap.size() - 1);
    }

    void remove() {
        int n = heap.size();
        if (n == 0) return;
        swap(heap[0], heap[n - 1]);
        heap.pop_back();
        if (heap.size() > 0) { 
            heapify_down(0);
        }
    }

    int top() { 
        return heap.size() > 0 ? heap[0] : -1;
    }
};

void solve() {
    int t;
    cin >> t;
    vector<int> v(t);
    for (int i = 0; i < t; i++) {
        cin >> v[i];
    }
    mheap hp(v);
    hp.build_head();
    hp.remove();
    hp.insert(13);
    hp.remove();
    cout << hp.max_ele() << endl; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
