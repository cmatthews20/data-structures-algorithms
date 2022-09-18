
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class item { // Element in PQ
public:
    T val;
    int priority;
};

template<typename T>
class PriorityQueue{
public:

    item<T> pr[1000]; // Store the element of a priority queue; arbitrary large array for demo purpose

    int size = -1; // Stores last index

    void enqueue(T val, int priority){ // Insert new element into PQ

        size++; // Increase the size

        pr[size].val = val; pr[size].priority = priority; // Insert the element
    }

    int getTop(){ // Gets top element
        int highestPriority = INT_MIN;
        int ind = -1;

        for (int i = 0; i <= size; i++) { // Check for the element with highest priority

            // If priority is same, take element with the highest value
            if (highestPriority == pr[i].priority && ind > -1 && pr[ind].val < pr[i].val){
                highestPriority = pr[i].priority;
                ind = i;

            }else if (highestPriority < pr[i].priority) {
                highestPriority = pr[i].priority;
                ind = i;
            }
        }

        return ind; // Return position
    }

    void dequeue(){ // Removes highest priority
        int ind = getTop(); // Find position of highest priority

        // Shift the element one index before from the position of the element with highest priority is found
        for (int i = ind; i < size; i++) {
            pr[i] = pr[i + 1];
        }
        size--; // Decrease size of PQ
    }
};

template<typename T>
PriorityQueue<T> merge(PriorityQueue<T> pq1, PriorityQueue<T> pq2){ // Merging 2 priority queues
    while(pq2.size > -1){
        pq1.enqueue(pq2.pr[pq2.getTop()].val, pq2.pr[pq2.getTop()].priority);
        pq2.dequeue();
    }
    return pq1;
}

// Can also merge into new array, but less efficient
//template<typename T>
//PriorityQueue<T> merge(PriorityQueue<T> pq1, PriorityQueue<T> pq2){
//    PriorityQueue<int> pqMerged;
//    while(pq1.size > -1){
//        pqMerged.enqueue(pq1.pr[pq1.getTop()].val, pq1.pr[pq1.getTop()].priority);
//        pq1.dequeue();
//    }
//    while(pq2.size > -1){
//        pqMerged.enqueue(pq2.pr[pq2.getTop()].val, pq2.pr[pq2.getTop()].priority);
//        pq2.dequeue();
//    }
//    return pqMerged;
//}

int main(){

    PriorityQueue<int> pq1; // Make a priority queue
    pq1.enqueue(100, 8); // Enqueue some values
    pq1.enqueue(15, 5);
    pq1.enqueue(10, 1);

    cout << "Items from Queue #1: "<< endl;
    cout << "Dequeued Top: " << pq1.pr[pq1.getTop()].val << endl; // Print top
    pq1.dequeue(); // Dequeue the top element
    cout << "Dequeued Top: " << pq1.pr[pq1.getTop()].val << endl; // Print top
    pq1.dequeue(); // Dequeue the top element
    cout << "Dequeued Top: " << pq1.pr[pq1.getTop()].val << endl; // Print top
    
    PriorityQueue<int> pq2; // Make a priority queue
    pq2.enqueue(111, 7); // Enqueue some values
    pq2.enqueue(11, 1);
    pq2.enqueue(12, 3);

    cout << "\nItems from Queue #2: "<< endl;
    cout << "Dequeued Top: " << pq2.pr[pq2.getTop()].val << endl; // Print top
    pq2.dequeue(); // Dequeue the top element
    cout << "Dequeued Top: " << pq2.pr[pq2.getTop()].val << endl; // Print top
    pq2.dequeue(); // Dequeue the top element
    cout << "Dequeued Top: " << pq2.pr[pq2.getTop()].val << endl; // Print top

    // Re-queue values for both queues
    pq1.enqueue(100, 8);
    pq1.enqueue(15, 5);
    pq2.enqueue(111, 7);
    pq2.enqueue(12, 3);

    cout<< "\nMERGED QUEUE: "<<endl;

    PriorityQueue<int> pqMerged = merge(pq1,pq2);
    cout << "Dequeued Top: " << pqMerged.pr[pqMerged.getTop()].val << endl; // Print top
    pqMerged.dequeue(); // Dequeue the top element
    cout << "Dequeued Top: " << pqMerged.pr[pqMerged.getTop()].val << endl; // Print top
    pqMerged.dequeue(); // Dequeue the top element
    cout << "Dequeued Top: " << pqMerged.pr[pqMerged.getTop()].val << endl; // Print top
    pqMerged.dequeue(); // Dequeue the top element
    cout << "Dequeued Top: " << pqMerged.pr[pqMerged.getTop()].val << endl; // Print top
    pqMerged.dequeue(); // Dequeue the top element
    cout << "Dequeued Top: " << pqMerged.pr[pqMerged.getTop()].val << endl; // Print top
    pqMerged.dequeue(); // Dequeue the top element
    cout << "Dequeued Top: " << pqMerged.pr[pqMerged.getTop()].val << endl; // Print top

    return 0;
}
