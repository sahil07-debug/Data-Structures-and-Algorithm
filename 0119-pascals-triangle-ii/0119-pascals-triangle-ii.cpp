class Solution {
public:
    vector<int> getRow(int n) {
        vector<int>ans(n+1);
        ans[0]=1;
        ans[n]=1;
        for(int i=1;i<=n/2;i++){
            int x=(long long)ans[i-1]*(n-i+1)/(i);
            ans[i]=x;
            ans[n-i]=x;
        }
        return ans;
    }
};