//create on 20210220
//快慢指针
//LeetCode寻找重复的数
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while (slow != fast);
        int prt = 0;
        while (prt != slow) {
            prt = nums[prt];
            slow = nums[slow];
        }
        return prt;
    }
};