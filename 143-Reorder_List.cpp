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
    void reorderList(ListNode* head) {
        vector<ListNode*> half_list_1; // half1 : 1,2,3,4,5
        vector<ListNode*> half_list_2; // half2 : 5,4,3,2,1
        vector<ListNode*> reorder_list;

        ListNode* half = head;
        ListNode* tmp = head;

        while(half != NULL)
        {
            half_list_1.push_back(half);
            half = half->next;
        }

        for(int i = half_list_1.size() - 1; i >=0; i--)
            half_list_2.push_back(half_list_1[i]);
        
        int index = 0;
        while(reorder_list.size() < half_list_1.size())
        {
            reorder_list.push_back(half_list_1[index]);
            reorder_list.push_back(half_list_2[index]);
            index++;
            
        }
        //debug
        // for(int i = 0; i < reorder_list.size(); i++)
        // {
        //     cout << reorder_list[i]->val << " ";
        // }
        // cout << endl;

        head = reorder_list[0];
        for(int i = 1; i < reorder_list.size(); i++)
        {
            head->next = reorder_list[i];
            head = head->next;
        }
        head->next = NULL;
        head = tmp;
    }
};
