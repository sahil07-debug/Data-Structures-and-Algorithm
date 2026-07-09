class Solution {
public:
    int characterReplacement(string s, int m) {
        int n=s.length();
        if(n==0) return 0;
        int ans=0;
        for(char i='A'; i<='Z';i++){
            int left = 0, replacements = 0;
            for (int right = 0; right < n; right++) {
                if (s[right] != i) replacements++;
                while (replacements > m) {
                    if (s[left] != i) replacements--;
                    left++;
                }
                ans = max(ans, right - left + 1);
             }
        }
        return ans;
    }
};