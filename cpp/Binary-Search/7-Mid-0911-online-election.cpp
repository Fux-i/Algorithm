#include <algorithm>
#include <vector>
using namespace std;

class TopVotedCandidate {
    vector<pair<int, short> > record;

public:
    TopVotedCandidate(vector<int> &persons, vector<int> &times) {
        short n = persons.size();
        record.reserve(n);

        short most = 0, most_one = -1;
        vector<short> votes(n, 0);
        for (int i = 0; i < n; ++i) {
            int person = persons[i];
            if (++votes[person] >= most) {
                most_one = person;
                most = votes[person];
            }
            record.emplace_back(times[i], most_one);
        }
    }

    int q(int t) {
        auto j = std::ranges::upper_bound(record, t, {}, [](pair<int, short>& a){ return a.first; }) - 1;
        return j->second;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
