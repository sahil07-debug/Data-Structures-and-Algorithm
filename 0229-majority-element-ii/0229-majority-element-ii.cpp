class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        map<int,int> mpp;
        int n=nums.size();
        if(n==1) return nums;
        for(int i=0;i<n;i++){
         mpp[nums[i]]+=1;
        }
        for(auto const& pair: mpp){
            if(pair.second>n/3){
                ans.push_back(pair.first);
            }
        }
        return ans;
    }
};