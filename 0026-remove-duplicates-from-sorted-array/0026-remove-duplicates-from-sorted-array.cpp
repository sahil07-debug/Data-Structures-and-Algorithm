class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int num=nums[0];
        int index=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=num && nums[i] <= 100 && nums[i]>=-100 ){
                num=nums[i];
                nums[index]=nums[i];
                index++;
            }
        }
        return index;     
    }
};