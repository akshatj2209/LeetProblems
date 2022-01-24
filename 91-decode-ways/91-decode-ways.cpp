class Solution {
    public:
        unordered_map < string, int > memo;
    int numDecodings(string s) {

        return recur(s);
    }
    int recur(string s) {
        if (memo.find(s) != memo.end()) {
            return memo[s];
        }
        if (s == "" || s[0] == '0') {
            return memo[s] = 0;
        }
        if (s.length() == 1) {
            return memo[s] = 1;
        }
        if (s.length() == 2 && stoi(s.substr(0, 2)) <= 26) {
            memo[s] = 1 + recur(s.substr(1));
            return memo[s];
        }
        if (s.length() > 2 && stoi(s.substr(0, 2)) <= 26) {
            memo[s] = recur(s.substr(2)) + recur(s.substr(1));
            return memo[s];
        }
        memo[s] = recur(s.substr(1));
        return memo[s];
    }
};