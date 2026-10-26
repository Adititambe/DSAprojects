#include <iostream>
using namespace std;

// Define the structure of a single node
class node {
public:
    int data;
    node* next;

    // Constructor to initialize data and next pointer
    node(int val) {
        data = val;
        next = NULL;
    }
};

class linkedlist {
private:
    node* head;

public:
    // Constructor to initialize an empty list
    linkedlist() {
        head = NULL;
    }

    // Insert a node at the end of the list
    void insert(int x) {
        node* p = new node(x);
        if (head == NULL) {
            head = p;
            return;
        } else {
            node* q = head;
            while (q->next != NULL) {
                q = q->next;
            }
            q->next = p;
        }
    }

    // Delete a node by value
    void remove(int x) {
        if (head == NULL) {
            return; // List is empty
        }

        // Case 1: The node to delete is the head node
        if (head->data == x) {
            node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        // Case 2: The node to delete is somewhere else in the list
        node* current = head;
        node* prev = NULL;

        while (current != NULL && current->data != x) {
            prev = current;
            current = current->next;
        }

        // If the value was found, un-link and delete the node
        if (current != NULL) {
            prev->next = current->next;
            delete current;
        }
    }

    // Display the list elements
    void display() {
        node* q = head;
        while (q != NULL) {
            cout << q->data << " -> ";
            q = q->next;
        }
        cout << "NULL" << endl;
    }
    
    // Destructor to clean up memory when the object goes out of scope
    ~linkedlist() {
        node* current = head;
        while (current != NULL) {
            node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = NULL;
    }
};

int main() {
    linkedlist list;
    
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.display(); // Expected: 10 -> 20 -> 30 -> NULL

    list.insert(40);
    list.insert(50);
    list.insert(60);
    list.display(); // Expected: 10 -> 20 -> 30 -> 40 -> 50 -> 60 -> NULL

    list.remove(40);
    list.display(); // Expected: 10 -> 20 -> 30 -> 50 -> 60 -> NULL

    list.remove(60);
    list.display(); // Expected: 10 -> 20 -> 30 -> 50 -> NULL

    list.remove(100); // Value not found, nothing changes
    list.display(); // Expected: 10 -> 20 -> 30 -> 50 -> NULL

    return 0;
}


