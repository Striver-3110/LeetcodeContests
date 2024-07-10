/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

 #include<set>
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> s(nums.begin(),nums.end());
        // lets create a dummy node that will work as the previous for the current node
        // and w'll be checking weather the current node exists in the list or not
        // i.e.
        // dummy(0)->head->head_next->...
        ListNode dummy(0);
        // dummy's next is head for simplicity
        dummy.next = head;
        // now we have to give address of dummy to current
        ListNode* current = &dummy;

        while(current->next){
            if(s.find(current->next->val) != s.end()){
                current->next = current->next->next;
            }else{
                current = current->next;
            }
        }
        return dummy.next;

        
    }
};