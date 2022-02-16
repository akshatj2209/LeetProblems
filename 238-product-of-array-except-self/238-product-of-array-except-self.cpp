class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product=1;
        vector<int> prefix;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            prefix.push_back(product);
            product *= nums[i];
        }
        product=1;
        for(int i=nums.size()-1;i>=0;i--){
            ans.push_back(product*prefix[i]);
            product *= nums[i];
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};