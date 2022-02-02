class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1+str2!=str2+str1) return "";
        if(str1.size()<str2.size()) return gcdOfStrings(str2, str1);
        
        // get GCD
        int pos = gcd(str1.size(), str2.size());
        
        return str1.substr(0, pos);
    }
    
    int gcd(int a, int b){
        if(b==0) return a;
        else return gcd(b, a%b);
    }
};