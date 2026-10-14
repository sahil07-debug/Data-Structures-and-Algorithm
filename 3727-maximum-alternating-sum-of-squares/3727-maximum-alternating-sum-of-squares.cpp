class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            nums[i]=nums[i]*nums[i];
        }
        sort(nums.begin(),nums.end());
        int x=n/2;
        long long sum=0;
        for(int i=0;i<x;i++) sum-=nums[i];
        for(int i=x;i<n;i++) sum+=nums[i];
        return sum;
    }
};