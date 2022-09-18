
#include<iostream>
using namespace std;

class BTreeNode{
    int *keys;
    int t;
    BTreeNode **C;
    int n;
    bool leaf;
public:
    BTreeNode(int _t, bool _leaf){ // Constructor
        t = _t;
        leaf = _leaf;
        keys = new int[2*t-1];
        C = new BTreeNode *[2*t];
        n = 0;
    }

    // ==============================================================================================================
    // Helper function to insert new key in the subtree rooted with this node. It is assumed that the node will not be full when this function is called
    template<typename T>
    void insertNonFull(T key){

        int index = n-1; // Initialize index as index of rightmost element

        if (leaf){ // If this node is a leaf
            while (index >= 0 && keys[index] > key){ // Figure out where new key is supposed to go and move keys ahead of it ahead by 1 to make space
                keys[index+1] = keys[index];
                index--;
            }

            // Insert the new key at found location
            keys[index+1] = key;
            n = n+1;

        }else{ // If this node is not leaf, find the child which is going to have the new key
            while (index >= 0 && keys[index] > key)
                index--;

            if (C[index+1]->n == 2*t-1){ // Check if found child is full

                splitChild(index+1, C[index+1]); // If the child is full, then split it

                // After split, the middle key of C[i] (child array) goes up and C[i] is split in half. Check which of the halves is going to have the new key
                if (keys[index+1] < key)
                    index++;
            }
            C[index+1]->insertNonFull(key); // recursively insert keys
        }
    }

    // =============================================================================================================
    // Helper function to split the toBeSplit child of this node. The index parameter refers to the index of y in child array C[]. toBeSplit must be full when this function is called
    void splitChild(int index, BTreeNode *toBeSplit){
        BTreeNode *newNode = new BTreeNode(toBeSplit->t, toBeSplit->leaf); // Create a new node which is going to store (t-1) keys of toBeSplit
        newNode->n = t - 1;

        for (int j = 0; j < t-1; j++){ // Copy the last (t-1) keys of toBeSplit to newNode
            newNode->keys[j] = toBeSplit->keys[j+t];
        }

        if (!toBeSplit->leaf){ // Copy the last t (degree) children of toBeSplit to newNode
            for (int j = 0; j < t; j++)
                newNode->C[j] = toBeSplit->C[j+t];
        }

        toBeSplit->n = t - 1; // Reduce the number of keys in toBeSplit

        for (int j = n; j >= index + 1; j--){ // create space for new child
            C[j+1] = C[j];
        }

        C[index+1] = newNode; // Link the new child to this node

        for (int j = n-1; j >= index; j--){ // Move a key of toBeSplit to the given node. Find the location of the new key and shift all greater keys ahead by 1
            keys[j+1] = keys[j];
        }

        keys[index] = toBeSplit->keys[t-1]; // Copy the middle key of toBeSplit to this node

        n = n + 1; // Increment # of keys in this node
    }

    void traverse(){ // Traverses all nodes in a subtree rooted with this node
        int i;
        for (i = 0; i < n; i++){
            if (!leaf){
                C[i]->traverse();
            }
            cout << " " << keys[i];
        }
        if (!leaf){
            C[i]->traverse();
        }
    }

    BTreeNode *search(int k){ // Searches for key in subtree rooted with this node, returns NULL if not present
        int i = 0;
        while (i < n && k > keys[i]){
            i++;
        }
        if (keys[i] == k){
            return this;
        }
        if (leaf){
            return NULL;
        }
        return C[i]->search(k);
    }
    friend class BTree; // Make BTree friend so it can access private members of this class in BTree funcs
};

class BTree{
private:
    BTreeNode *root;
    int t; // min degree
public:

    BTree(int _t){ // Constructor
        root = NULL; t = _t;
    }

    void traverse(){ // function to traverse the tree
        if (root != NULL){
            root->traverse();
        }
    }

    BTreeNode* search(int k){ // Searches for a key in the tree
        return (root == NULL)? NULL : root->search(k);
    }

    void insert(int k){ // Inserts new key in tree
        if (root == NULL){
            root = new BTreeNode(t, true);
            root->keys[0] = k;
            root->n = 1;

        }else{
            if (root->n == 2*t-1){
                BTreeNode *s = new BTreeNode(t, false);
                s->C[0] = root;
                s->splitChild(0, root);
                int i = 0;
                if (s->keys[0] < k){
                    i++;
                }
                s->C[i]->insertNonFull(k);
                root = s;
            }else{
                root->insertNonFull(k);
            }
        }
    }
};

int main(){ // Test program to show that the code works

    BTree t(3); // BTree with min degree 3
    t.insert(1); // insert some elements
    t.insert(8);
    t.insert(3);
    t.insert(4);
    t.insert(5);
    t.insert(2);

    cout << "Traverse: ";
    t.traverse();

    int key = 5;
    if(t.search(key) != NULL){
        cout << "\nKey Found";
    }else{
        cout << "\nKey not Found";
    }

    key = 11;
    if(t.search(key) != NULL){
        cout << "\nKey Found";
    }else{
        cout << "\nKey not Found";
    }

    return 0;
}