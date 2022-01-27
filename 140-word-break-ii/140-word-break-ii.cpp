class Solution {
public:
    void recur(string s, vector<string>& wordDict, vector<string>& ans, int i, string comp){
        if(i==s.length()){
            comp.pop_back();
            ans.push_back(comp);
        }
        for(int j=0;j<wordDict.size();j++){
            if(s.substr(i,wordDict[j].length()) == wordDict[j]){
                recur(s,wordDict,ans,i+wordDict[j].length(),comp+wordDict[j]+ " ");
            }
        }
        return;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        recur(s,wordDict,ans,0,"");
        return ans;
    }
};