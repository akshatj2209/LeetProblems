class Solution {
public:
    int rob(vector<int>& arr) {

    long long int n=arr.size();
        if(n==1){
            return arr[0];
        }
    long long int prev = arr[0];
    long long int prev2 =0;
    
    for(int i=1; i<n-1; i++){
        long long int pick = arr[i];
        if(i>1)
            pick += prev2;
        long long int nonPick = 0 + prev;
        
        long long int cur_i = max(pick, nonPick);
        prev2 = prev;
        prev= cur_i;
        
    }
    long long int ans=prev;
    prev = arr[1];
    prev2 =0;
    
    for(int i=2; i<n; i++){
        long long int pick = arr[i];
        if(i>1)
            pick += prev2;
        long long int nonPick = 0 + prev;
        
        long long int cur_i = max(pick, nonPick);
        prev2 = prev;
        prev= cur_i;
        
    }
    return max(prev,ans);
    }
};