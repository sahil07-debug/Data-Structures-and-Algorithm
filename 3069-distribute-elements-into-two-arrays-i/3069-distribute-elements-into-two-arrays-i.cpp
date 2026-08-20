class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>a;
        vector<int>b;
        a.push_back(nums[0]);
        b.push_back(nums[1]);
        int i=2;
        int j=0;
        int k=0;
        while(i<n){
            if(a[j]>b[k]){
                a.push_back(nums[i]);
                j++;
            }
            else{
                b.push_back(nums[i]);
                k++;
            }
            i++;
        }
        for(int j=0;j<b.size();j++){
            a.push_back(b[j]);
        }
        return a;
    }
};