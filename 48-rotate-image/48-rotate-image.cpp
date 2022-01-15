class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int i, j;
        for(i=0;i<m;i++){
            for(j=0;j<i;j++){
                int t=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=t;
            }
        }
        
        for(i=0;i<m;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
        
    }
};