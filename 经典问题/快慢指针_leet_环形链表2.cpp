/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //create on 20210220
 //快慢指针，要求找到链表入口
 //LeetCode环形链表
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast){
            if(fast->next == NULL) return NULL; //到头了，没有环
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){ //快慢指针遇到了，说明存在环，下面找到环的入口
                ListNode* prt = head;
                while(prt != slow){
                    prt = prt->next;
                    slow = slow->next;
                }
                return prt;
            }
        }
        return NULL;
    }
};