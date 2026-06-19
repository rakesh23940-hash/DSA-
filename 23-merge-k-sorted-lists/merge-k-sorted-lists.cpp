class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& listarray) {

        priority_queue<
            pair<int, ListNode*>,
            vector<pair<int, ListNode*>>,
            greater<pair<int, ListNode*>>
        > pq;

        for(int i = 0; i < listarray.size(); i++) {

            if(listarray[i]) {
                pq.push({listarray[i]->val, listarray[i]});
            }
        }

        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        while(!pq.empty()) {

            auto it = pq.top();
            pq.pop();

            temp->next = it.second;
            temp = temp->next;

            if(it.second->next) {
                pq.push({it.second->next->val, it.second->next});
            }
        }

        return dummyNode->next;
    }
};