class Solution {
public:
 
    int check(string s,int left,int right){
        while(left>=0 && right<s.length()&& s[left]==s[right]){
            left--;
            right++;
        }
        return right-left-1;
    }
    string longestPalindrome(string s) {
        int n=s.length();
        if(n<=1) return s;
        int start=0;
        int maxlen=0;
        for(int i=0;i<n;i++){
             int l1=check(s,i,i);
             int l2=check(s,i,i+1);
             
             int curr=max(l1,l2);
             if(curr>maxlen){
                maxlen=curr;
                start=i-(curr-1)/2;
             }
        }
        return s.substr(start,maxlen);
    }
};