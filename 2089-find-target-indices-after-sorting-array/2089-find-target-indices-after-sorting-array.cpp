class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n=nums.size();
        int count=0;
        int ind=0;
        for(int i=0;i<n;i++){
            if(nums[i]<target) ind++;
            else if(nums[i]==target)count++;
        }
        vector<int>ans;
        for(int i=0;i<count;i++){
            ans.push_back(ind);
            ind++;
        }
        return ans;
    }
};