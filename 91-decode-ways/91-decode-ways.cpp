class Solution {
    public:
        int numDecodings(string s) {
            int i;
            int n=s.length();
            int cur;
            int count1=0;
            int count2=0;
            for(i=n;i>0;i--){
                if(s[i-1]=='0'){
                    cur=0;
                }
                else if(i==n){
                    cur=1;
                }
                else if(i==n-1 && stoi(s.substr(i-1, 2)) <= 26){
                    cur=1+count2;
                }
                else if(stoi(s.substr(i-1, 2)) <= 26){
                    cur=count2+count1;
                }
                else{
                    cur=count2;
                }
                count1=count2;
                count2=cur;
            }

            return count2;
        }
        
};