class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==0) return 0;
        int i=0;
        int s=k;
        int j=0;
        int ans=0;
        int curr=0;
        while(i<n&&j<n){
            if(i>j) j=i;
            if(curr<0)curr=0;
            if(nums[j]==1){
                j++;
                curr++;
                ans=max(ans,curr);
            }
            else{
                if(s>0){
                    curr++;
                    j++;
                    ans=max(ans,curr);
                    s--;
                }
                else if(s==0 && s<k){
                    if(nums[i]==0) {
                        s++;
                        i++;
                        curr--;
                    }
                    else{
                        i++;
                        curr--;
                    }
                }
                else{
                    i++;
                    curr--;
                }
            }
        }
        return ans;
    }
};