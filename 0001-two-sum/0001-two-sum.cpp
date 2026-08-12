class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> list;

        for(int i = 0; i < nums.size(); i++){
            int complement = target - nums[i];
            if(list.find(complement) != list.end()){
                return {list[complement], i};
            }
            list[nums[i]] = i;
        }
        return {};
    }
};