class Solution {
public:
    int recur(vector<int>& nums, int i,int l){
        if(i==nums.size() && l==1){
            return INT_MIN;
        }
        if(i==nums.size() && l==0){
            return 1;
        }
        if(l==0){
            return max(nums[i],nums[i]*recur(nums,i+1,0));
        }
        return max(nums[i]*recur(nums,i+1,0),recur(nums,i+1,1));
    }
    int maxProduct(vector<int>& nums) {
        int curr_product = 1, res = INT_MIN;
       
       for (auto i: nums) {
           curr_product = curr_product * i;
           res = max(curr_product, res);
           if(curr_product == 0) {
               curr_product = 1;
           }
       }
       
       curr_product = 1;
       
       for (int i = nums.size()-1; i>=0; i--) {
           curr_product = curr_product * nums[i];
           res = max(curr_product, res);
           if(curr_product == 0) {
               curr_product = 1;
           }      
       }
       return res;
    }
};