class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        map<int,int> mapper;
        int n=nums.size();
        int i;
        for(i=0;i<n;i++){
            if(mapper[target-nums[i]] != 0 ){
                ans.push_back(mapper[target-nums[i]]-1);
                ans.push_back(i);
                return ans;
            }
            mapper[nums[i]]=i+1;
        }
        return ans;
        
    }
};