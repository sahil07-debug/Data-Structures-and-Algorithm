class Solution {
public:
    int beautySum(string s) {
        int ans=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            int arr[26]={0};
            for(int j=i;j<n;j++){
               arr[s[j]-'a']++;
               int minf=INT_MAX;
               int maxf=0;
               for(int k=0;k<26;k++){
                if(arr[k]>0){
                     maxf=max(maxf,arr[k]);
                     minf=min(minf,arr[k]);}
               }
               ans+=(maxf-minf);
            }   
        }
        return ans;
    }
};