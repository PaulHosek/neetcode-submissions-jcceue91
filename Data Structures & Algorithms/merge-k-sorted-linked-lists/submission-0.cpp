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

        std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;

        for (ListNode* l : lists){
            while (l != nullptr){
                min_heap.push(l->val);
                l = l->next;
            }
        }

        ListNode* node = new ListNode(min_heap.top());
        ListNode* root = node;
        min_heap.pop();
        while (!min_heap.empty()) {
            node->next = new ListNode();
            node = node->next;
            int v = min_heap.top();
            node->val = v;
            min_heap.pop();
        }

        return root;
        
    }
};
