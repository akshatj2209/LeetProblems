// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        // your code here
        vector<int> ans;
        int i=0,maxi=INT_MIN;
        int index=0;
        for(i=0;i<k;i++){
            if(maxi<=arr[i]){
                maxi=arr[i];
                index=i;
            }
        }
        ans.push_back(maxi);
        for(;i<n;i++){
            if(index<=i-k){
                maxi=INT_MIN;
                i-=k;
                i++;
                for(int j=0;j<k;j++,i++){
                    if(maxi<=arr[i]){
                        maxi=arr[i];
                        index=i;
                    }
                }
                i--;
                ans.push_back(maxi);
                continue;
            }
            if(maxi<=arr[i]){
                maxi=arr[i];
                index=i;
            }
            ans.push_back(maxi);
        }
        return ans;
        
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}  // } Driver Code Ends