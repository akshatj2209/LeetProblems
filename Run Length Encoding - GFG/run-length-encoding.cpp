// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*You are required to complete this function */

string encode(string src)
{     
  //Your code here
  char c=src[0];
  int n=1;
  string ans;
  for(int i=1;i<src.length();i++){
      if(src[i]==c){
          n++;
      }
      else{
          ans.push_back(c);
          ans+=to_string(n);
          c=src[i];
          n=1;
      }
  }
    ans.push_back(c);
    ans+=to_string(n);
    return ans;
  
}     
 
