class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int i, n = colors.length();
        int minTime = 0;
        int sum, maxi;
        for(i = 0; i < n - 1; i ++){
            if(colors[i] == colors[i + 1]){
                sum = 0;
                maxi = 0;
                while(i < n && colors[i] == colors[i + 1]){
                    maxi = max(maxi, neededTime[i]);
                    sum += neededTime[i];
                    i ++;
                }
                if(i < n){
                    maxi = max(maxi,neededTime[i]);
                    sum += neededTime[i];
                }
                minTime += (sum-maxi);
            }
        }
        return minTime;
    }
};