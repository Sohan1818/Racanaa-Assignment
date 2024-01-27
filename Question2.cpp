#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

void deleteNode(Node* n) {
    if (n == nullptr || n->next == nullptr) {
        // Cannot delete the last node or null node.
        return;
    }

    Node* nextNode = n->next;
    n->data = nextNode->data;
    n->next = nextNode->next;
    delete nextNode; 
// Free up the memory occupied by the next node.
}

void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    cout << "Enter the number of nodes in the linked list: ";
    int n;
    cin >> n;

    cout << "Enter the values of the nodes: ";
    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    cout << "Original List:" << endl;
    printList(head);

    cout << "Enter the node value to delete: ";
    int valueToDelete;
    cin >> valueToDelete;

    Node* current = head;
    Node* nodeToDelete = nullptr;

    // Find the node to delete
    while (current != nullptr && current->data != valueToDelete) {
        current = current->next;
    }

    if (current != nullptr) {
        nodeToDelete = current;
    } else {
        cout << "Node not found in the list." << endl;
        return 0;
    }

    // Delete the node
    deleteNode(nodeToDelete);

    cout << "List after deleting the node:" << endl;
    printList(head);

    // Free memory occupied by the remaining nodes
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

/*
Corner cases:

1) Deleting the last node in the list.
2) Deleting a null node or a node with null next pointer.
3) Deleting the only node in the list.


Time Complexity: O(1)
Space Complexity: O(1)
*/