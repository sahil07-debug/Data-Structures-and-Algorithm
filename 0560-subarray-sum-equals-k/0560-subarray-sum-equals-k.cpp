class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> mpp;
        int count=0;
        int sum;
        mpp[0]=1;
        for(int i=0;i<nums.size();i++){
           sum=sum+nums[i];
           int need=sum-k;
           count+=mpp[need];
           mpp[sum]+=1;
        }
        return count;
    }
};