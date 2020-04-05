// Copyright (c) 2020 Sirn Nguyen Truong <sonnt174@gmail.com>
//
// Problem: https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/0000000000209a9f

#include <iostream>
#include <string>

using namespace std;

void nesting_depth() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        string s;
        cin >> s;
        string ans(s[0] - '0', '(');
        for (int i = 0; i < static_cast<int>(s.length()) - 1; ++i) {
            int t = i + 1;
            string c = s[i] < s[t] ? ")" : s[i] > s[t] ? "(" : "";
            ans += s[i];
            for (int k = 0; k < abs(s[i] - s[t]); ++k) {
                ans += s[i] < s[t] ? "(" : ")";
            }
        }
        ans += s.back() + string(s.back() - '0', ')');

        std::cout << "Case #" << i << ": " << ans << endl;
    }
}

int main() {
    nesting_depth();
    return 0;
}
