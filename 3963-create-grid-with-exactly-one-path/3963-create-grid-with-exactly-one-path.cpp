class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string>ans;
        string x=".";
        string s="";
        for(int i=1;i<n;i++){
            x+='.';
            s+='#';
        }
        s+='.';
        ans.push_back(x);
        for (int i=1;i<m;i++){
            ans.push_back(s);
        }
        return ans;
    }
};