#include <vector>
#include <algorithm>
using namespace std;

class SnapshotArray {
    vector<vector<pair<int, int>>> store{}; // {snap_id, value}
    int snap_count = 0;
public:
    SnapshotArray(int length) {
        store.assign(length, {{-1, 0}});
    }

    void set(int index, int val) {
        store[index].push_back({snap_count, val});
    }

    int snap() {
        return snap_count++;
    }

    int get(int index, int snap_id) {
        vector<pair<int, int>>& pairs = store[index];
        auto latest = ranges::upper_bound(pairs, snap_id, {},
            [](pair<int, int> &p) { return p.first; }) - 1;
        return latest->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */