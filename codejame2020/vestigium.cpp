// Copyright (c) 2020 Sirn Nguyen Truong <sonnt174@gmail.com>
//
// Problem: https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/000000000020993c

#include <iostream>
#include <vector>

using namespace std;

void vestigium() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        int N;
        cin >> N;
        vector<vector<int>> M(N, vector<int>(N));
        for (int r = 0; r < N; ++r) {
            for (int c = 0; c < N; ++c) {
                cin >> M[r][c];
            }
        }

        int trace = 0;
        int rep_r = 0;
        int rep_c = 0; 
        
        for (int d = 0; d < N; ++d) {
            trace += M[d][d];
            vector<bool> exist_r(101, false);
            vector<bool> exist_c(101, false);
            bool row_ok = true;
            bool col_ok = true;
            for (int x = 0; x < N; x++) {
                // row checking
                int mr = M[d][x];
                if (exist_r[mr] == true && row_ok == true) {
                    rep_r++;
                    row_ok = false;
                }
                else {
                    exist_r[mr] = true;
                }

                // column checking
                int mc = M[x][d];
                if (exist_c[mc] == true && col_ok == true) {
                    rep_c++;
                    col_ok = false;
                }
                else {
                    exist_c[mc] = true;
                }
            }
        }
        std::cout << "Case #" << i << ": " << trace << " " << rep_r << " " << rep_c << endl;
    }
}

int main() {
    vestigium();
    return 0;
}
