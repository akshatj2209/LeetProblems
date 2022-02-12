class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0,j=0, n=nums.size();
        int k=n;
        for(i=1;i<n;i++){
            if(nums[i] != nums[i-1]){
                j++;
                nums[j]=nums[i];
            }
            
        }
        return j+1;
        
    }
};