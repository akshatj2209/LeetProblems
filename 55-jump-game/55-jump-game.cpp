class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int i;
        int max_reach=0;
        for(i=0;i<n;i++){
            if(i>max_reach){
                return false;
            }
            else if(max_reach>=n-1){
                return true;
            }
            max_reach=max(max_reach,nums[i]+i);
        }
        return true;
        
        
    }
};