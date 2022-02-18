class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=0;
        for(int i=1;i<nums.size();i++){
            sum+=nums[i];
        }
        int sumr=0;
        if(sum==0){
            return 0;
        }
        for(int i=1;i<nums.size();i++){
            sumr+=nums[i-1];
            sum-=nums[i];
            if(sumr==sum){
                return i;
            }
        }
        return -1;
        
    }
};