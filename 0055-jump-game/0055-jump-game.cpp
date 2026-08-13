class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int maxi=nums[0];
        for(int i=1;i<n;i++){
            if(maxi < i) return false;
            if(maxi>=n-1) return true;
            if(maxi<i+nums[i]){
                maxi =i+nums[i];
            }
        }
        return true;
    }
};