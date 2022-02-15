class Solution {
public:
    int minDeletions(string s) {
        int freq[26];
        memset(freq,0,sizeof(freq));
        for(int i=0;i<s.length();i++){
            freq[s[i]-'a']++;
        }
        sort(freq, freq+26,greater<int>());
        int deletions=0;
        for(int i=1;i<26;i++){
            if(freq[i]==0){
                break;
            }
            while(freq[i]!=0 && freq[i]>=freq[i-1]){
                deletions++;
                freq[i]--;
            }
        }
        return deletions;
    }
};