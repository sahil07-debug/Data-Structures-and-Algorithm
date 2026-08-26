class Solution {
public:
    bool isIsomorphic(string s, string p) {
        int n=s.length();
        int map_s[256]={0};
        int map_p[256]={0};
        for(int i=0;i<n;i++){
             if(map_s[s[i]]!=map_p[p[i]]) return false;

             map_s[s[i]]=i+1;
             map_p[p[i]]=i+1;
        }
        return true;
    }
};