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
#include <vector>
#include <queue>

class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
      
        auto compare = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };
        
        std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(compare)> minHeap(compare);
        
        for (ListNode* listHead : lists) {
            if (listHead != nullptr) {
                minHeap.push(listHead);
            }
        }
        
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        while (!minHeap.empty()) {
            ListNode* minNode = minHeap.top();
            minHeap.pop();
            
            tail->next = minNode;
            tail = tail->next;
            
            if (minNode->next != nullptr) {
                minHeap.push(minNode->next);
            }
        }
        return dummy.next;
    }
};