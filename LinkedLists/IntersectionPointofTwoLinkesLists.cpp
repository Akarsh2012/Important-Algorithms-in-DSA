/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // If either list is empty, there's no intersection.
        if (!headA || !headB) return nullptr;

        // Initialize two pointers, starting at the heads of both lists.
        ListNode* ptrA = headA;
        ListNode* ptrB = headB;

        // Traverse both lists. Continue until the two pointers meet.
        while (ptrA != ptrB) {
            // If ptrA reaches the end of List A, switch it to the head of List B.
            // Otherwise, move ptrA to the next node in List A.
            ptrA = ptrA ? ptrA->next : headB;

            // If ptrB reaches the end of List B, switch it to the head of List A.
            // Otherwise, move ptrB to the next node in List B.
            ptrB = ptrB ? ptrB->next : headA;

            // The key idea here is that by switching the lists, both pointers
            // traverse the same combined length (length of A + length of B).
            // This ensures that they meet at the intersection node if it exists.
        }

        // If the lists intersect, ptrA == ptrB at the intersection node.
        // If they don't intersect, both will reach nullptr at the same time.
        return ptrA;  // This will either be the intersection node or nullptr.
    }
};

/**
 * Time Complexity Analysis:
 * 
 * - In the worst case, each pointer traverses both lists fully once.
 * - Let `n` be the length of List A, and `m` be the length of List B.
 * 
 * - Each pointer travels:
 *   - First, the full length of its own list (`n` or `m`).
 *   - Then, it travels the full length of the other list (`m` or `n`).
 * 
 * - Therefore, in the worst case, each pointer traverses `n + m` nodes.
 * 
 * - Thus, the overall time complexity is **O(n + m)**, where:
 *   - `n` is the length of List A.
 *   - `m` is the length of List B.
 */
