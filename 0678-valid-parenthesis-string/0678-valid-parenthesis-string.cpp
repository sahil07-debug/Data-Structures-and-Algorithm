class Solution {
public:
    bool checkValidString(string s) {
        int n=s.length();
        int x=0;
        int y=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                x++;
                y++;
            }
            else if(s[i]==')'){
                x--;
                y--;
            }
            else{
                x++;
                y--;
            }
            if(x<0) return false;
            if(y<0) y=0;
        }
        return y==0;
    }
};