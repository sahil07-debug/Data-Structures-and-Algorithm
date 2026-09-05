class Solution {
public:
    string reverseWords(string s) {
        int n=s.length();
        int start=0;
        int end=0;
        while(start<n){
            while(start<n && s[start]==' ') start++;
            if(start==n) break;
            if(end!=0){
                s[end]=' ';
                end++;
            }
            int d=end;
            while(s[start]!=' ' && start<n){
                s[end]=s[start];
                end++;
                start++;
            }
            reverse(s.begin()+d,s.begin()+end);
        }
        s.resize(end);
        reverse(s.begin(),s.end());
        return s;
    }
};