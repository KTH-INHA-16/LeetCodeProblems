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
        priority_queue<int, vector<int>, greater<int>> pq;

        for(auto a:lists) {
            for(ListNode* b=a;b!=nullptr;b=b->next) {
                pq.push(b->val);
            }
        }

        if(pq.empty())
            return nullptr;

        ListNode *head = new ListNode(pq.top());
        ListNode *result = head;

        pq.pop();

        while(!pq.empty()) {
            ListNode *tmp = new ListNode(pq.top());
            head->next = tmp;
            head = tmp;

            pq.pop();
        }

        return result;
    }
};
