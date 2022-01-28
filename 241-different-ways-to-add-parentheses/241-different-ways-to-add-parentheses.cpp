class Solution {
public:
    void crossproduct(vector< int>& l, vector< int>& r, char op, vector< int>& p){
        for(int i:l){
            for(int j:r){
                if(op == '+') p.push_back(i+j);
                else if(op == '*') p.push_back(i*j);
                else p.push_back(i-j);
            }
        }
    }
    vector< int> findpossibleSol(vector <int> &operands, vector <char>&operators){
        int n = operands.size();
        vector< vector< vector< int>>> dp(n,vector< vector< int>>(n,vector< int>()));
        for(int i = 0; i < operands.size(); i++){
            dp[i][i].push_back(operands[i]);
        }
        for(int l = 1; l < n; l++){
            for(int i = 0, j = l; i < n-l; i++,j++){
                
                for(int k = i; k < j; k++){
                    crossproduct(dp[i][k], dp[k+1][j], operators[k], dp[i][j]);
                }
            }
        }
        return dp[0][n-1];
    }
    
    vector< int> diffWaysToCompute(string expression) {
        int n = expression.length();
        vector <int>operands;
        vector <char>operators;
        int num = 0;
        for(int i = 0; i < n; i++){
            if(expression[i] >= '0' && expression[i] <= '9'){
                num = 10*num + (expression[i]-'0');
            }
            else{
                operands.push_back(num);
                num = 0;
                operators.push_back(expression[i]);
            }
        }
        operands.push_back(num);
        return findpossibleSol(operands, operators);
    }
};