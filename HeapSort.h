#ifndef HEAPSORT_HEAPSORT_H
#define HEAPSORT_HEAPSORT_H
#include <fstream>
using namespace std;

class HeapSort {
private:
    int* heapArray;
    int* lastItem;
    int  arrayLength;
    char** argv;
    ofstream outfile;
public:
    HeapSort(int size, char** arguments);
    void buildHeap();
    void deleteHeap();
    int insertOneDataItem(int data);
    bool deleteRoot();
    void bubbleUp();
    void bubbleDown();
    bool isHeapEmpty();
    bool isHeapFull();
    void printHeap();
    void printTree(int root);
};


#endif //HEAPSORT_HEAPSORT_H
