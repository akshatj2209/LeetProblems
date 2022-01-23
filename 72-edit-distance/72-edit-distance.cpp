int recur(string word1, string word2, int i, int j,vector<vector<int>> &memo){
    if(memo[i][j]!=-1){
        return memo[i][j];
    }
    
    if(i==word1.length()){
        memo[i][j]=word2.length()-j;
        return memo[i][j];
    }
    if(j==word2.length()){
        memo[i][j]=word1.length()-i;
        return memo[i][j];
    }
    
    if(word1[i]==word2[j]){
        return recur(word1,word2,i+1,j+1,memo);
    }
    memo[i][j]=1+min(recur(word1,word2,i,j+1,memo),min(recur(word1,word2,i+1,j,memo),recur(word1,word2,i+1,j+1,memo)));
    return memo[i][j];
}



class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> memo(word1.length()+1, vector<int>(word2.length()+1,-1));
        return recur(word1,word2,0,0,memo);
    }
};