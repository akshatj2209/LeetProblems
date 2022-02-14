class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n=nums.size();
        int begin=0;
        int front;
        int ending=n-1;
        for(begin=0;begin<n-2;begin++){
            if(begin>0 && nums[begin]==nums[begin-1]){
                continue;
            }
            front = begin+1;
            ending=n-1;
            while(front<ending){
                if(nums[begin]+nums[front]+nums[ending]==0){
                    ans.push_back({nums[begin],nums[front],nums[ending]});
                    ending--;
                    while(ending>front && nums[ending]==nums[ending+1]){
                        ending--;
                    }
                }
                else if(nums[front]+nums[ending]+nums[begin]<0){
                    front++;
                }
                else{
                    ending--;
                    
                }
                
            }
        }
        return ans;
        
    }
};