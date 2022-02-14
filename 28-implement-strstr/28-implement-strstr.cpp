class Solution {
public:
    int strStr(string haystack, string needle) {
        int len=haystack.length();
        int i, j=0;
        if(needle==""){
            return 0;
        }
        for(i=0;i<len;i++){
            if(haystack[i]==needle[j]){
                int c=i;
                while(c<len && j<len && haystack[c]==needle[j]){
                    c++;
                    j++;
                }
                if(j==needle.length()){
                    return i;
                }
                j=0;
            }
        }
        return -1;
        
        
        
    }
};