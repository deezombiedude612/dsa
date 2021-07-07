# Node structure to be used in SLL
class Node:
    def __init__(self, item=None):
        self.item = item
        self.next = None


class SLL:
    def __init__(self):
        self.head = None

    # Check if SLL is empty
    def is_empty(self):
        return self.head is None

    # Retrieve size of SLL (number of Nodes currently in SLL)
    def get_size(self):
        if self.is_empty():
            return 0

        cur = self.head
        num_nodes = 0
        while cur is not None:
            num_nodes += 1
            cur = cur.next

        return num_nodes

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

    # Add a new Node to SLL at given index
    def add_node_at(self, newItem, index):
        if index == 0:
            self.add_head(newItem)
            return

        currentIndex = 0
        cur = self.head
        while currentIndex < index and cur:
            currentIndex += 1
            cur = cur.next

        if cur is None:
            print("Illegal array index!\n")
        else:
            new_node = Node(newItem)
            new_node.next = cur.next
            cur.next = new_node

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
    print("Size of SLL: ", l.get_size())

    print("\nAdding 15 at position 2..")
    l.add_node_at(15, 2)
    l.display_list()
    print("Size of SLL: ", l.get_size())
