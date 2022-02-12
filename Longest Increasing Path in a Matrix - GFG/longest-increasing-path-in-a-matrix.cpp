// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int recur(int i, int j, vector<vector<int>>& matrix,  int memo[1001][1001]){
        if(i<0 || i==matrix.size() || j<0 || j==matrix[0].size()){
            return 0;
        }
        if(memo[i][j]!=-1){
            return memo[i][j];
        }
        int left=0,right=0,up=0,down=0;
        if(i>0 && matrix[i-1][j]>matrix[i][j] ){
            left=1+recur(i-1,j,matrix,memo);
        }
        if(i<matrix.size()-1 && matrix[i+1][j]>matrix[i][j]){
            right=1+recur(i+1,j,matrix,memo);
        }
        if(j>0 && matrix[i][j-1]>matrix[i][j] ){
            up=1+recur(i,j-1,matrix,memo);
        }
        if(j<matrix[0].size()-1 && matrix[i][j+1]>matrix[i][j]){
            down=1+recur(i,j+1,matrix,memo);
        }
        return  memo[i][j]=max(left,max(right,max(up,down)));
    }
    int longestIncreasingPath(vector<vector<int>>& matrix, int m, int n) {
        int i, j;
        int ans=0;
        int memo[1001][1001];
        memset(memo,-1,sizeof(memo));
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                ans=max(ans,recur(i,j, matrix,memo));
            }
        }
        return ans+1;    
        
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        cout << obj.longestIncreasingPath(matrix, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends