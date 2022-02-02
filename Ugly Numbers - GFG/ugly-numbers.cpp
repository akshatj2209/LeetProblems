// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	ull getNthUglyNo(int n) {
	    ull dp[n+1];
	    int i=0;
	    int j=0;
	    int k=0;
	    dp[0]=1;
	    int c=1;
	    while(c<n){
	        ull mul2=dp[i]*2;
	        ull mul3=dp[j]*3;
	        ull mul5=dp[k]*5;
	        if(mul2<=mul3 && mul2<=mul5){
	            dp[c]=mul2;
	            i++;
	        }
	        if(mul3<=mul2 && mul3<=mul5){
	            dp[c]=mul3;
	            j++;
	        }
	        if(mul5<=mul2 && mul5<=mul3){
	            dp[c]=mul5;
	            k++;
	        }
	        c++;
	        
	    }
	    return dp[n-1];
	    // code here
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.getNthUglyNo(n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends