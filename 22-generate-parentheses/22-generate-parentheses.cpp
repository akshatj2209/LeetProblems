void recur(string s,int i, int n,vector<string> &simple){
    if(i==0 && n==0){
        simple.push_back(s);
    }
    if(i>0) recur(s+"(",i-1,n,simple);
    if(n>i) recur(s+")",i,n-1,simple);
}

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int i=1;
        vector<string> simple;
        string s="";
        recur(s,n,n,simple);
        return simple;
    }
};