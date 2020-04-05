
// Copyright (c) 2020 Sirn Nguyen Truong <sonnt174@gmail.com>
//
// Problem: https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/000000000020bdf9

#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>
#include <tuple>

using namespace std;

using segment_t = tuple<int, int, int>;

bool is_overlap(const segment_t &s1, const segment_t &s2) {
    return (get<1>(s1) - get<0>(s2) > 0 && get<1>(s2) - get<0>(s1) > 0);
}

string do_optismic(vector<segment_t> &segments) {
    string ans;
    std::sort(begin(segments), end(segments), [](const segment_t &s1, const segment_t &s2) -> bool {
        return get<0>(s1) < get<0>(s2);
    });

    vector<segment_t> j;
    vector<segment_t> c;
    j.push_back(segments[0]);
    size_t t = 0;
    for (size_t i = 1; i < segments.size(); ++i) {
        if (false == is_overlap(segments[i], segments[t])) {
            j.push_back(segments[i]);
            t = i;
        } else {
            c.push_back(segments[i]);
        }
    }

    for (size_t i = 1; i < c.size(); ++i) {
        if (is_overlap(c[i], c[i - 1])) {
            return "IMPOSSIBLE";
        }
    }

    sort(begin(j), end(j), [](const segment_t &s1, const segment_t &s2) -> bool {
        return get<2>(s1) < get<2>(s2);
    });
    size_t ij = 0;
    for (size_t i = 0; i < segments.size(); ++i) {
        if (ij < j.size() && i == get<2>(j[ij])) {
            ans += "J";
            ij++;
        } else {
            ans += "C";
        }
    }
    return ans;
}

void parenting_partnering_return() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        int N;
        cin >> N;
        vector<segment_t> segments(N);
        for (int i = 0; i < N; ++i) {
            int s, e;
            cin >> s >> e;
            segments[i] = make_tuple(s, e, i);
        }
        auto ret = do_optismic(segments);
        std::cout << "Case #" << i << ": " << ret << endl;
    }
}

int main() {
    parenting_partnering_return();
    return 0;
}
