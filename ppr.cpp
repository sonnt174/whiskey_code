#include <iostream>
#include <vector>
#include <utility>
#include <string>

using namespace std;

using segment_t = pair<int, int>;

bool is_overlap(const segment_t &s1, const segment_t &s2) {
    return (s1.second - s2.first > 0 && s2.second - s1.first > 0);
}

bool is_valid_comb(const vector<segment_t> &segments) {
    if (segments.size() < 2) return true;

    for (size_t i = 0; i < segments.size() - 1; ++i) {
        for (size_t j = i + 1; j < segments.size(); ++j) {
            if (is_overlap(segments[i], segments[j])) {
                return false;
            }
        }
    }

    return true;
}

void genpermut(int i, int size, vector<vector<int>> &all_permut) {
    static vector<int> perm;
    if (i == size) {
        all_permut.push_back(perm);
        return;
    }
    
    for (int m = 0; m < 2; ++m) {
        perm.push_back(m);
        genpermut(i + 1, size, all_permut);
        perm.pop_back();
    }
}

string do_recursive(const vector<segment_t> &segments) {
    vector<vector<int>> all_permut;
    genpermut(0, segments.size(), all_permut);
    for (auto perm : all_permut) {
        vector<segment_t> j;
        vector<segment_t> c;
        string ans("");
        for (size_t i = 0; i < perm.size(); ++i) {
            if (perm[i] == 0) {
                j.push_back(segments[i]);
                ans += "J";
            }
            else {
                c.push_back(segments[i]);
                ans += "C";
            }
        }
        bool done = is_valid_comb(c) && is_valid_comb(j);
        if (done) {
            return ans;
        }
    }

    return "IMPOSSIBLE";
}

void parenting_partnering_return() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        int N;
        cin >> N;
        vector<segment_t> segments(N);
        for (int i = 0; i < N; ++i) {
            cin >> segments[i].first >> segments[i].second;
        }
        auto ret = do_recursive(segments);
        std::cout << "Case #" << i << ": " << ret << endl;
    }
}

int main() {
    parenting_partnering_return();
    return 0;
}