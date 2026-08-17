class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=0;
        int prev=nums[0][1];
        for(int i=1;i<n;i++){
            if(nums[i][0]<prev){
                ans++;
                prev=min(nums[i][1],prev);
            }
            else prev=nums[i][1];
        }
        return ans;
    }
};