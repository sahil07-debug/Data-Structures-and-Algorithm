class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        if(n==0) return 0;
        int ans=1; 
        vector<int>arr(256,0);
        int i=0;
        int j=1;
        arr[s[i]]++;
        int curr=1;
        while(i<n&&j<n){
            if(arr[s[j]]){
                arr[s[i]]--;
                i++;
                curr--;
            }
            else{
                arr[s[j]]++;
                j++;
                curr++;
                ans=max(ans,curr);
            }
        }
        return ans;
    }
};