// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int i;
        long long int found=0;
        unsigned long long int sum=0;
        for(i=0;i<n;i++){
            if(arr[abs(arr[i])-1]<0){
                found=abs(arr[i]);
            }
            arr[abs(arr[i])-1]=((-1)*arr[abs(arr[i])-1]);
            sum+=abs(arr[i]);
        }
        
        sum-=found;
        int* ptr = (int*) malloc(2 * sizeof(int));
        *(ptr+0)=found;
        *(ptr+1)=(n*(n+1ull))/2-sum;
        return ptr;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends