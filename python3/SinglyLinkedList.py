# Node structure to be used in SLL
class Node:
    def __init__(self, item=None):
        self.item = item
        self.next = None


class SLL:
    def __init__(self):
        self.head = None

    # Add a new head Node in SLL
    def add_head(self, newItem):
        new_node = Node(newItem)
        new_node.next = self.head
        self.head = new_node

    # Add a new tail Node in SLL
    def add_tail(self, newItem):
        new_node = Node(newItem)

        if self.head is None:
            self.head = new_node
            return

        cur = self.head
        while cur.next:
            cur = cur.next

        cur.next = new_node

    # def add_node_at(self, newItem):
    #     new_node = Node(newItem)

    #     if self.head is None:
    #         self.head = new_node
    #         return

    #     # insert check to see if

    # Display full list
    def display_list(self):
        cur = self.head
        while cur is not None:
            print(cur.item)
            cur = cur.next


if __name__ == "__main__":
    l = SLL()
    l.head = Node(10)
    l.add_head(5)
    l.add_tail(20)
    l.display_list()
