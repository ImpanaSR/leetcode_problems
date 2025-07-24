#include <iostream>
#include<vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Solution class with isPalindrome method
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return true;

        // Step 1: Find the middle of the linked list
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half
        ListNode* prev = nullptr;
        while (slow != nullptr) {
            ListNode* nextNode = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nextNode;
        }

        // Step 3: Compare both halves
        ListNode* first = head;
        ListNode* second = prev;
        while (second != nullptr) {
            if (first->val != second->val)
                return false;
            first = first->next;
            second = second->next;
        }

        return true;
    }
};

// Helper function to create a linked list from array
ListNode* createList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* current = head;
    for (size_t i = 1; i < vals.size(); ++i) {
        current->next = new ListNode(vals[i]);
        current = current->next;
    }
    return head;
}

int main() {
    // Test input: change this to try other cases
    vector<int> vals = {1, 2, 2, 1}; // Palindrome
    // vector<int> vals = {1, 2}; // Not a palindrome

    ListNode* head = createList(vals);

    Solution sol;
    bool result = sol.isPalindrome(head);

    cout << (result ? "The list is a palindrome." : "The list is not a palindrome.") << endl;

    return 0;
}
