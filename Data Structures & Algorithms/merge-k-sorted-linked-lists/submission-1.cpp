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

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()){
            return nullptr;
        }

        auto greater = [](ListNode* a, ListNode* b){return a->val > b->val;};
        std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(greater)> min_heap;

        for (ListNode* cur_root : lists){
            if (cur_root != nullptr){
                min_heap.push(cur_root);
            }
        }


        ListNode* res = new ListNode(0);
        ListNode* root = res;
        while (!min_heap.empty()) {
            ListNode* smallest_parent = min_heap.top();
            min_heap.pop();
            res->next = smallest_parent;
            res = res->next;

            smallest_parent = smallest_parent->next;
            if (smallest_parent != nullptr){
                min_heap.push(smallest_parent);
            }
        }

        return root->next;
        
    }
};
