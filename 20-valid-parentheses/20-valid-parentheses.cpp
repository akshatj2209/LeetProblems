class Solution {
public:
    bool isValid(string s) {
        stack<char> stacker;
        int i, len=s.length();
        for(i=0;i<len;i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                stacker.push(s[i]);
            }
            else if(s[i]==')'){
                if(!stacker.empty() && stacker.top()=='('){
                    stacker.pop();
                }
                else{
                    return false;
                }
            }
            else if(s[i]=='}'){
                if(!stacker.empty() && stacker.top()=='{'){
                    stacker.pop();
                }
                else{
                    return false;
                }
            }
            else{ 
                if(!stacker.empty() && stacker.top()=='['){
                    stacker.pop();
                }
                else{
                    return false;
                }
            }
        }
        return stacker.empty(); 
        
    }
};