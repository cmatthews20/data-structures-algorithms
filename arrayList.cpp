
#include <iostream>
using std::cout;
using std::endl;

template<typename T>
class arrayList{
private:
    T* arr;
    int arraySize;
    int count = 0;

public:
    arrayList(int size){ // Constructor / Create array list
        arr = new T[size];
        arraySize = size;
    }

    void printArray(){ // Print contents of list
        for(int i = 0; i < count; i++){
            cout<< arr[i] << endl;
        }
    }


    void Insert(T element){ // Insert a value at the end of the array list
        if(count == arraySize){
            int newArraySize = arraySize * 2;
            T* tempArr = new T[newArraySize];

            for(int i = 0; i < arraySize; i++){
                tempArr[i] = arr[i];
            }

            arraySize = newArraySize;
            delete[] arr;
            arr = tempArr;
            //delete[] tempArr; // Can't double more than once if new array is deleted
            arr[count] = element;
            count++;

        } else{
            arr[count] = element;
            count++;
        }
    }

    void deleteVal(T value){ // Deletes a single value (the first occurrence in the array list)
        for(int i = 0; i < count; i++){
            if(arr[i] == value){
                for(int j = i; j < count; j++){
                    arr[j] = arr[j + 1];
                }
                arr[count] = -1; // Not entirely necessary since count is being decreased
                count--;
                break;
            }
        }
    }

    void deleteAllVals(T element){ // Deletes all instances of a value in the array list
        for(int i = 0; i < count; i++){
            if(arr[i] == element){
                for(int j = i; j < count; j++){
                    arr[j] = arr[j + 1];
                }
                arr[count] = -1; // Not entirely necessary since count is being decreased
                count--;
                i--; // Need to re-check current index after shifting
            }
        }
    }

    void deleteIndex(int index){ // Deletes an element of the array list by its index
        for(index; index < count; index++){
            arr[index] = arr[index + 1];
        }
        arr[count] = -1; // Not entirely necessary since count is being decreased
        count--;
    }

    int binarySearch(T value){ // Assume sorted array. Returns index of wanted value
        int lower = 0;
        int higher = count;
        int middle;
        while(lower <= higher){
            middle = lower + (higher - 1) / 2; // Need to recalculate middle value every loop with new bounds

            if(arr[middle] == value){
                return middle;
            }

            if(arr[middle] < value){ // If value is greater than mid, ignore lower half
                lower = middle + 1;
            }else{ // if value is less than mid, ignore upper half
                higher = middle - 1;
            }
        }
        return -1; // Element not found
    }

    void test(){ // Helps with testing. Outputs array list values, indices, size, and count in organized fashion
        cout<< "BEGIN TEST-----"<< endl;
        cout<< "Array size is currently: " << arraySize<< endl;
        cout<< "Count is currently: " << count<< endl;
        for(int i = 0; i < count; i++){
            cout<< "Index: "<< i << ", Value: " << arr[i] << endl;
        }
        cout<< "END TEST-----"<< endl<<endl;
    }
};


int main() { // Comment/Uncomment each section and view output to conduct each test

    // SECTION 1: TESTING INSERTION
    // Array should double in size when trying to insert into filled array
    arrayList<char> array(2);
    array.test();
    array.Insert('a');
    array.test();
    array.Insert('b');
    array.test();
    array.Insert('c');
    array.test();
    array.Insert('d');
    array.test();
    array.Insert('e');
    array.test();

    // SECTION 2: TESTING DELETE
//    arrayList<float> arrayTwo(5);
//    arrayTwo.Insert(1.1);
//    arrayTwo.Insert(2.2);
//    arrayTwo.Insert(5.5);
//    arrayTwo.Insert(1.1);
//    arrayTwo.Insert(5.5);
//    arrayTwo.test();
//    arrayTwo.deleteVal(1.1); // Should delete single instance of 1.1
//    arrayTwo.test();
//    arrayTwo.deleteAllVals(5.5); // Should delete all instances of 5.5
//    arrayTwo.test();
//    arrayTwo.deleteIndex(1); // Should delete value at index 1
//    arrayTwo.test();

    // SECTION 3: TESTING BINARY SEARCH (assume sorted)
    // Should output indices in order, followed by -1
//    arrayList<int> arrayThree(4);
//    arrayThree.Insert(3);
//    arrayThree.Insert(6);
//    arrayThree.Insert(8);
//    arrayThree.Insert(9);
//    cout<< arrayThree.binarySearch(3)<< endl;
//    cout<< arrayThree.binarySearch(6)<< endl;
//    cout<< arrayThree.binarySearch(8)<< endl;
//    cout<< arrayThree.binarySearch(9)<< endl;
//    cout<< arrayThree.binarySearch(10)<< endl; // Test for non-existent element

    return 0;
}
