class Solution {
public:
    int myAtoi(string s) {
        int n=s.length();
        int i=0;
        int ans=0;
        int sign=1;
        while(i<n && s[i]==' '){
            i++;
        }
        if(i<n && (s[i]=='-'||s[i]=='+')){
            if(s[i]=='+')sign=1;
            else sign=-1;
            i++;
        }
        while(i<n && isdigit(s[i])){
            int k=s[i]-'0';
            if(ans>INT_MAX/10 || (ans==INT_MAX/10 && k>7)){
                if(sign==1) return INT_MAX;
                else return INT_MIN;
            }
            ans=ans*10+k;
            i++;
        }
        return sign*ans;
    }
};