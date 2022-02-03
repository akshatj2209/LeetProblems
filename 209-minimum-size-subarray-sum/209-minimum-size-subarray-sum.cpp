class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int i, j;
        for(i=0;i<n;i++){
            int sum=0;
            for(j=0;j<=i;j++){
                sum+=nums[j];
            }
            if(sum>=target){
                return i+1;
            }
            for(j=i+1;j<n;j++){
                sum+=nums[j];
                sum-=nums[j-i-1];
                if(sum>=target){
                    return i+1;
                }
            }
        }
        return 0;
    }
};