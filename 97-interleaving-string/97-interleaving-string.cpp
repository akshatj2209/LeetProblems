class Solution {
public:
    bool recur(string s1, string s2, string s3, int i, int j, int k,vector<vector<vector<int>>> &memo){
        if(memo[i][j][k]!=2){
            return memo[i][j][k];
        }
        if(i==s1.length() && j==s2.length() && k==s3.length()){
            return memo[i][j][k]=true;
        }
        if(k==s3.length()){
            return memo[i][j][k]=false;
        }
        if(i<s1.length() && s1[i]==s3[k] && j<s2.length() && s2[j]==s3[k]){
            return memo[i][j][k]=recur(s1,s2,s3,i+1,j,k+1,memo) || recur(s1,s2,s3,i,j+1,k+1,memo);
        }
        if(i<s1.length() && s1[i]==s3[k]){
            return memo[i][j][k]=recur(s1,s2,s3,i+1,j,k+1,memo);
        }
        if(j<s2.length() && s2[j]==s3[k]){
            return memo[i][j][k]=recur(s1,s2,s3,i,j+1,k+1,memo);
        }
        return memo[i][j][k]=false;
        
    }
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<vector<int>>> memo(s1.length()+1,vector<vector<int>>(s2.length()+1,vector<int>(s3.length()+1,2)));
        return recur(s1,s2,s3,0,0,0,memo);   
    }
};