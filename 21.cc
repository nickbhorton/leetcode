
#include <iostream>
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

void printv(ListNode* ptr)
{
    ListNode* p = ptr;
    while (p != nullptr) {
        std::cout << p->val << " ";
        p = p->next;
    }
    std::cout << "\n";
}

class Solution
{
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        if (list2 == nullptr) {
            return list1;
        }
        if (list1 == nullptr) {
            return list2;
        }
        // Ensure that list1 has the smallest val
        if (list2->val < list1->val) {
            ListNode* temp = list1;
            list1 = list2;
            list2 = temp;
        }
        ListNode* ptr = list1;
        while (list2 != nullptr && ptr->next != nullptr) {
            if (ptr->next->val > list2->val) {
                ListNode* temp = ptr->next;
                ptr->next = list2;
                ptr->next = temp;
                list2 = list2->next;
                ptr = ptr->next;
            } else {
                ptr = ptr->next;
            }
        }
        if (ptr->next == nullptr && list2 != nullptr) {
            ptr->next = list2;
        }
        return list1;
    }
};
