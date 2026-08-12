class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.length();
        vector<int> v(3,0);
        int ans=0;
        int j=0;
        for(int i=0;i<n;i++){
            v[s[i]-'a']++;
            while(v[0]>0 && v[1]>0 && v[2]>0 && j<n){
                v[s[j]-'a']--;
                j++;
            }
            ans+=j;
        }
        return ans;
    }
};