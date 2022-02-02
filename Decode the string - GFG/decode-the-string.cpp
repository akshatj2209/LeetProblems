// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string decodedString(string s){
        // code here
        stack<string> strings;
        stack<int> nums;
        int i, n= s.length();
        for(i=0;i<n;i++){
            if(s[i]>='0' && s[i]<='9'){
                int ans=0;
                while(s[i]>='0' && s[i]<='9'){
                    ans=ans*10+s[i]-'0';
                    i++;
                }
                nums.push(ans);
                i--;
            }
            else{
                if(s[i]==']'){
                    string s="";
                    while(strings.top()!="["){
                        s=strings.top()+s;
                        strings.pop();
                    }
                    int p=nums.top();
                    string temp="";
                    for(int j=1;j<=p;j++){
                        temp+=s;
                    }
                    strings.pop();
                    nums.pop();
                    strings.push(temp);
                }
                else{
                    strings.push(string(1,s[i]));
                }
            }
        }
        return strings.top();
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}  // } Driver Code Ends