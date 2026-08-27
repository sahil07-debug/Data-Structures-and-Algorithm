class Solution {
public:
    bool isAnagram(string s, string t) {
        int n=s.length();
        if(n!=t.length()) return false;
        vector<int>arr(26,0);
        for(int i=0;i<n;i++){
            arr[s[i]-'a']+=1;
            arr[t[i]-'a']-=1;
        }
        for(int i=0;i<26;i++){
            if(arr[i]!=0) return false;
        }
        return true;
    }
};