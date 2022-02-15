class comp
{
  public:
    bool operator()(int &d1,int &d2){
        return d2<d1;
    }
};
class Solution {
public:
    static bool comparator(vector<int> &d1,vector<int> &d2){
        return d1[0]<d2[0];
    }
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end(),comparator);
        priority_queue<int,vector<int>,comp>q;
        
        int n=events.size();
        int start=1,end=100000;
        int c=0;int i=0;
        for(int d=start;d<=end;d++)
        {
            while(i<n&&events[i][0]==d)
                q.push(events[i++][1]);
            
            while(q.size()!=0&&q.top()<d)
                   q.pop();
        
            if(q.size()!=0){
                c++;
                q.pop();
            }
            if(i==n&&q.size()==0){
                break;
            }
        }
        return c; 
    }
};