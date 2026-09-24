class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        if (nums.size() == 1) {
            return 1;
        }

        int slow = 1;

        for (int fast = 1; fast < nums.size(); fast++) {

            if (nums[fast] != nums[slow - 1]) {

                nums[slow] = nums[fast];

                slow++;
            }
        }

        return slow;
    }
};