#include <iostream>
using std::cout;
using std::endl;

//Node of a doubly linked list
template<typename T>
struct Node{
    T data;
    Node* next;
    Node* prev;

    Node(){
        next = nullptr;
        prev = nullptr;
    }
};


// Print contents of DLL from given node
template<typename T>
void printList(Node<T>* node){
    Node<T>* last;
    cout<<"\nPrinting DLL:\n";
    while (node != nullptr){
        cout<< node->data <<", ";
        last = node;
        node = node->next;
    }
    cout<<endl;
}

// Pass reference to head node and data to append at end of list
template<typename T>
void append(Node<T>** head_ref, T new_data){

    Node<T>* new_node = new Node<T>(); // Allocate new node

    Node<T>* last = *head_ref; // Used later

    new_node->data = new_data; // Place data in node

    new_node->next = nullptr; // New node is going to be the last node, so make next of it a nullptr

    if (*head_ref == nullptr){ // If list is empty, then make new node the head node
        new_node->prev = nullptr;
        *head_ref = new_node;
        return;
    }

    while (last->next != nullptr){ // Find last node otherwise
        last = last->next;
    }

    last->next = new_node; // Change the next of last node to the new node

    new_node->prev = last; // Make the former last node the prev of new node

}

template<typename T>
void deleteNode(Node<T>** head_ref, Node<T>* del){

    // If list is empty, do nothing
    if (*head_ref == nullptr || del == nullptr)
        return;

    // If node to be deleted is head node
    if (*head_ref == del)
        *head_ref = del->next;

    // Change next if node to be deleted is not last node
    if (del->next != nullptr)
        del->next->prev = del->prev;

    // Change prev if node to be deleted is not first node
    if (del->prev != nullptr)
        del->prev->next = del->next;

    free(del); // Prevent memory leak
}


int main() {

// Make head node, append to list to test the delete function
    Node<int> *head;
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    append(&head, 5);

    printList(head); // Print list

    deleteNode(&head, head->next); // Delete the second node
    cout<< "\nDelete Node!\n";

    printList(head); // Print list again to show result

    return 0;
}
