class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        if(n==1) return strs[0];
        int m=strs[0].length();
        for(int i=0;i<m;i++){
            for(int j=0;j<n-1;j++){
                if(strs[j][i]!=strs[j+1][i]) return strs[0].substr(0,i);
            }
            if(i==m-1) return strs[0];
        }
        return "";
    }
};