class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mapper;
        int n=nums.size();
        int i;
        for(i=0;i<n;i++){
            if(mapper[target-nums[i]] != 0 ){
                return {mapper[target-nums[i]]-1,i};
            }
            mapper[nums[i]]=i+1;
        }
        return {};
        
    }
};