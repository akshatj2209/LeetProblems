class Solution {
public:
    unordered_map<string,bool>mp;
    bool isScramble(string a, string b) {
        
        string key=a+b;
        if(mp.find(key)!=mp.end())
            return mp[key];
        if(a.compare(b)==0)
            return mp[key]=true;
        if(a.length()<=1)
            return mp[key]=false;
        int i,n;
        n=a.length();
        for(i=1;i<n;i++)
        {
            if(isScramble(a.substr(0,i),b.substr(0,i)) && isScramble(a.substr(i,n-i),b.substr(i,n-i)))
            return mp[key]=true;
            if(isScramble(a.substr(0,i),b.substr(n-i,i)) && isScramble(a.substr(i,n-i),b.substr(0,n-i)))
            return mp[key]=true;
        }
        return mp[key]=false;
    }
};