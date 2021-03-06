class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans (1, 1);
        int i, j;
        for(i = 1; i <= rowIndex; i ++){
            int temp[i + 1];
            temp[0] = 1;
            temp[i] = 1;
            for(j = 1; j < i; j ++){
                temp[j] = ans[j - 1] + ans[j];
            }
            ans.assign(temp, temp + i + 1);
        }
        return ans;
        
    }
};