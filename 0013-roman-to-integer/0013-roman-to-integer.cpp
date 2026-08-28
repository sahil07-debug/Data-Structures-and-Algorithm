class Solution {
public:
     int getValue(char romanChar) {
    switch(romanChar) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}
    int romanToInt(string s) {
        int n=s.length()-1;
        int ans=0;
        for(int i=n;i>=0;i--){
            if(i==n) ans+=getValue(s[i]);
            else if(i<n){
                if(getValue(s[i])<getValue(s[i+1])) ans-=getValue(s[i]);
                else ans+=getValue(s[i]);
            }
        }
        return ans;
    }
};