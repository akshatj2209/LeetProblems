bool compare(vector<int> a, vector<int> b){
        if(a[0]<b[0]){
            return true;
        }
        else if(a[0]>b[0]){
            return false;
        }
        else{
            if(a[1]<b[1]){
                return true;
            }
        }
        return false;
    }
class Solution {
public:
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),compare);
        
        int n=intervals.size();
        vector<vector<int>> answer;
        int j=0;
        answer.push_back(intervals[0]);
        for(int i=1;i<n;i++){
            if(intervals[i][0]<=answer[j][1] && intervals[i][1]>answer[j][1]){
                answer[j][1]=intervals[i][1];
            }
            else if(intervals[i][0]>answer[j][1]){
                answer.push_back(intervals[i]);
                j++;
            }
        }
        return answer;
        
        
    }
};