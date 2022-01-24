class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int i,j;
        for(i=n-1;i>0;i--){
            for(j=0;j<i;j++){
                triangle[i-1][j]+=min(triangle[i][j],triangle[i][j+1]);
                
            }
        }
        return triangle[0][0];
        
        
    }
};