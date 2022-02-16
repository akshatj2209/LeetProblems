class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product=1;
        vector<int> prefix;
        vector<int> suffix(nums.size());
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            prefix.push_back(product);
            product *= nums[i];
        }
        
        product=1;
        for(int i=nums.size()-1;i>=0;i--){
            suffix[i]=product;
            product *= nums[i];
        }
        for(int i=0;i<nums.size();i++){
            ans.push_back(suffix[i]*prefix[i]);
        }
        return ans;
        
    }
};