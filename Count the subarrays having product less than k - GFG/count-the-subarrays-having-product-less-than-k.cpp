// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution{
  public:
    
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        int i;
        int ans=0;
        long long p=1;
        int j=0;
        for(i=0;i<a.size();i++){
            p*=a[i];
            while(j<i && p>=k){
                p/=a[j];
                j++;
            }
            if(p<k){
                ans+=i-j+1;
            }
            
            
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends