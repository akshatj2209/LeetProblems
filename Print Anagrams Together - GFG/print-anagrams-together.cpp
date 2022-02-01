// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    bool checkAnagram(string a, string b){
        map<char,int> mapper;
        int c=0;
        if(a.length()!=b.length()){
            return false;
        }
        for(int i=0;i<a.length();i++){
            mapper[a[i]]++;
            if(mapper[a[i]]==1){
                c++;
            }
        }
        for(int i=0;i<b.length();i++){
            mapper[b[i]]--;
            if(mapper[b[i]]<0){
                return false;
            }
        }
        return true;
    }
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        vector<vector<string>> ans;
        int i, j;
        int n=string_list.size();
        bool truth[n+1];
        memset(truth,false,sizeof(truth));
        for(i=0;i<n;i++){
            vector<string> temp;
            if(!truth[i]){
                temp.push_back(string_list[i]);
                for(j=i+1;j<n;j++){
                    if(!truth[j] && checkAnagram(string_list[i],string_list[j])){
                        temp.push_back(string_list[j]);
                        truth[j]=true;
                    }
                }
                ans.push_back(temp);
            }
            
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}
  // } Driver Code Ends