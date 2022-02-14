class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int i, j, k;
        
        for(i=0;i<9;i++){
            map<char,bool> mapper;
            for(j=0;j<9;j++){
                if(board[i][j]=='.'){
                    continue;
                }
                if(mapper[board[i][j]]){
                    return false;
                }
                mapper[board[i][j]]=true;
                
            }
        }
        cout<<"passed"<<" ";
        for(i=0;i<9;i++){
            map<char,bool> mapper;
            for(j=0;j<9;j++){
                if(board[j][i]=='.'){
                    continue;
                }
                if(mapper[board[j][i]]){
                    return false;
                }
                mapper[board[j][i]]=true;
                
            }
        }
        cout<<"passed"<<" ";
        int ki=0, kj=0;
        for(ki=0;ki<9;ki+=3){
            for(kj=0;kj<9;kj+=3){
                map<char,bool> mapper;
                for(i=ki;i<ki+3;i++){
                    for(j=kj;j<kj+3;j++){
                        if(board[i][j]=='.'){
                            continue;
                        }
                        if(mapper[board[i][j]]){
                            return false;
                        }
                        mapper[board[i][j]]=true;
                    }
                }
                
            }
        }
        return true;
        
        
    }
};