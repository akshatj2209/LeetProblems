class Solution {
public:
    bool recur(string s1, string s2, string s3, int i, int j, vector<vector<int>> &memo){
        if(memo[i][j]!=2){
            return memo[i][j];
        }
        if(i==s1.length() && j==s2.length() && i+j==s3.length()){
            return memo[i][j]=true;
        }
        if(i+j==s3.length()){
            return memo[i][j]=false;
        }
        if(i<s1.length() && s1[i]==s3[i+j] && j<s2.length() && s2[j]==s3[i+j]){
            return memo[i][j]=recur(s1,s2,s3,i+1,j,memo) || recur(s1,s2,s3,i,j+1,memo);
        }
        if(i<s1.length() && s1[i]==s3[i+j]){
            return memo[i][j]=recur(s1,s2,s3,i+1,j,memo);
        }
        if(j<s2.length() && s2[j]==s3[i+j]){
            return memo[i][j]=recur(s1,s2,s3,i,j+1,memo);
        }
        return memo[i][j]=false;
        
    }
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<int>> memo(s1.length()+1,vector<int>(s2.length()+1,2));
        return recur(s1,s2,s3,0,0,memo);   
    }
};