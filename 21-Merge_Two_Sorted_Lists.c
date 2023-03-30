/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    if(list1 == NULL && list2 == NULL)
        return;
    
    if(list1 == NULL && list2 != NULL)
        return list2;
    if(list1 != NULL && list2 == NULL)
        return list1;


    struct ListNode* h1 = list1;
    struct ListNode* h2 = list2;

    struct ListNode* head;
    struct ListNode* first;

    if(h1->val <= h2->val)
    {
        head = h1;
        h1 = h1->next;
    }
    else
    {
        head = h2;
        h2 = h2->next;
    }
    
    first = head;

    while( h1 != NULL && h2 != NULL)
    {
        if(h1->val <= h2->val)
        {
            head->next = h1;
            h1 = h1->next;
        }
        else
        {
            head->next = h2;
            h2 = h2->next;
        }
        // printf("[loop] head->val = %d\n", head->val);
        head = head->next;
    }

    while( h1 != NULL)
    {
        head->next = h1;
        h1 = h1->next;
        head = head->next;
    }
    while( h2 != NULL)
    {
        head->next = h2;
        h2 = h2->next;
        head = head->next;
    }

    return first;
}
