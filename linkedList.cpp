#include <iostream>
using std::cout;
using std::endl;

template<typename T>
struct Node{
    T data;
    Node* next;
};

template<typename T>
class linkedList{
private:
    Node<T>* head;

public:

    linkedList(){
        head = NULL;
    }

    void printList()
    {
        Node<T>* temp = head;
        cout << "Printing List: ";
        while(temp != NULL){
            cout<< temp->data << ", ";
            temp = temp->next;
        }
        cout << endl;
    }

    void append(T val) {
        Node<T> *new_node = new Node<T>; // Allocate new node
        new_node->data = val; // Put in the data
        new_node->next = NULL;
        if (head == NULL) {
            head = new_node;
            return;
        } else {
            new_node->next = head;
            head = new_node;
        }
    }

    void reverseLinkedList(){

        Node<T>* current = head;
        Node<T> *prev = NULL, *next = NULL;

        while (current != NULL) {
            next = current->next; // Save next
            current->next = prev; // Reverse current node pointer
            prev = current; // Move pointers one position ahead
            current = next;
        }
        head = prev;
    }
};


int main() {

    // Make list and add sample values
    linkedList<int> sampleList;
    sampleList.append(1);
    sampleList.append(2);
    sampleList.append(3);

    sampleList.printList(); // Print list to check

    sampleList.reverseLinkedList(); // Reverse list and check output
    cout<<"Reverse List! "<< endl;
    sampleList.printList();

    return 0;
}
