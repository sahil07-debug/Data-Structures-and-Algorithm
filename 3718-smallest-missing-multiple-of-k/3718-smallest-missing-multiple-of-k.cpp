class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>p(101,0);
        for(int i=0;i<n;i++){
           p[nums[i]]++;
        }
        int i=1;
        while(i*k<=100){
            if(p[i*k]==0)return i*k;
            i++;
        }
        return i*k;
    }
};