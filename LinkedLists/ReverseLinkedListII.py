# Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.
from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        if not head or left == right:
            return head
        
        dummy = ListNode(0)  # Dummy node before head for easier handling
        dummy.next = head
        prev = dummy

        # Move prev to just before the "left" node
        for _ in range(left - 1):
            prev = prev.next
        
        # Reverse sublist from left to right
        reverse_prev = prev
        curr = prev.next
        next_node = None
        prev = None

        for _ in range(right - left + 1):
            next_node = curr.next
            curr.next = prev
            prev = curr
            curr = next_node
        
        # Reconnect reversed sublist with original list
        reverse_prev.next.next = curr  # Connect end of reversed sublist to remaining list
        reverse_prev.next = prev  # Connect beginning of reversed sublist to previous part

        return dummy.next  # Return original head
    
# Test cases
def main():
    # see what prints for 1 2 3 4 5
    head = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5)))))
    left = 2
    right = 4
    solution = Solution()
    result = solution.reverseBetween(head, left, right)

    while result:
        print(result.val, end=" ")
        result = result.next


if __name__ == "__main__":
    main()
