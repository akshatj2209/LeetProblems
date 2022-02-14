class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        map<char, int> count;
        int size=tasks.size();
        int i;
        for(i=0;i<size;i++){
            count[tasks[i]]++;
        }
        int maxOccur=0;
        int counting=0;
        for(auto greed : count){
            if(greed.second>maxOccur){
                maxOccur=greed.second;
                counting=1;
            }
            else if(greed.second==maxOccur){
                counting++;
            }
        }
        int dots=(maxOccur-1)*n;
        
        return max(dots+maxOccur+(counting-1),size);
        
        
        
        
    }
};