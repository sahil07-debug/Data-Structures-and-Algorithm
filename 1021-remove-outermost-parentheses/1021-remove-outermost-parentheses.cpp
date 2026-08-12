class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.length()-1;
        string ans="";
        int depth=0;
        for(int i=0;i<n;i++){
              if(s[i]=='('){
                if(depth>0) ans=ans+s[i];
                depth++;
              }
              else if(s[i]==')'){
                depth--;
                if(depth>0) ans+=s[i];
              }
           }
           
        return ans;
      
    }
};