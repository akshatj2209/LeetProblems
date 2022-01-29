class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        while(i<s.length() && s[i]==' '){
            i++;
        }
        bool neg=false;
        if(s[i]=='-'){
            i++;
            neg=true;
        }
        else if(s[i]=='+'){
            i++;
        }
        long long int ans=0;
        while(s[i]>='0' && s[i]<='9'){
            ans = ans * 10 + s[i]-'0';
            if(ans>INT_MAX && neg){
                return INT_MIN;
            }
            else if(ans>INT_MAX){
                return INT_MAX;
            }
            i++;
        }
        
        if(neg){
            ans*=(-1);
        }
        if(ans>=INT_MAX){
            return INT_MAX;
        }
        if(ans<=INT_MIN){
            return INT_MIN;
        }
        return ans;
        
    }
};