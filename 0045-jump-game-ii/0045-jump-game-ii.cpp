class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        int maxi=0;
        int next=0;
        int ans=0;
        for(int i=0;i<n;i++){
            next=max(next,i+nums[i]);
            if(i==maxi){
                maxi=next;
                ans++;
            }
            if(maxi>=n-1){
                break;
            }
        }
        return ans;
    }
};