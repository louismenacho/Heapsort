#include "HeapSort.h"
#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

HeapSort::HeapSort(int size, char* arguments[]) {
    heapArray = new int[size+1];
    lastItem = &heapArray[0];
    arrayLength = size+1;
    argv = arguments;
}

void HeapSort::buildHeap() {
    outfile.open(argv[2]);
    outfile << "Build Heap :\n";

    int number;
    ifstream infile;

    infile.open(argv[1]);
    while(infile >> number){
        outfile << "insert " << insertOneDataItem(number) << "\t";
        printHeap();
    }
    infile.close();
    outfile << "\nFinal Heap :\n";
    printHeap();
}

void HeapSort::deleteHeap() {
    outfile << "\nDelete Heap :\n";
    while(deleteRoot()) {
        printHeap();
    }
    outfile << "\nFinal Heap :\n";
    printHeap();
    outfile.close();
}

int HeapSort::insertOneDataItem(int data) {
    if(!isHeapFull()){
        heapArray[0]++;
        heapArray[*lastItem] = data;
        bubbleUp();
    }
    return data;
}

bool HeapSort::deleteRoot() {
    if(!isHeapEmpty()){
        outfile << "delete " << heapArray[1] << "\t";
        heapArray[1] = heapArray[*lastItem];
        heapArray[*lastItem] = 0;
        heapArray[0]--;
        bubbleDown();
        return true;
    }
    else return false;
}

void HeapSort::bubbleUp() {
    int parent = *lastItem/2;
    int newItem = *lastItem;
    while(heapArray[parent] > heapArray[newItem] && parent > 0){
        int temp = heapArray[parent];
        heapArray[parent] = heapArray[newItem];
        heapArray[newItem] = temp;
        newItem = parent;
        parent = newItem/2;
    }
}

void HeapSort::bubbleDown() {
    int parent = 1;
    int left = 2;
    int right = 3;
    while(true){
        if (right > *lastItem || left > *lastItem) {
            break;
        }
        if (heapArray[left] <= heapArray[right]) {
            if (heapArray[parent] >= heapArray[left]) {
                int temp = heapArray[parent];
                heapArray[parent] = heapArray[left];
                heapArray[left] = temp;
                parent = left;
                left = 2 * parent;
                right = 2 * parent + 1;
                continue;
            }
        }
        else if(heapArray[parent] >= heapArray[right]) {
            int temp = heapArray[parent];
            heapArray[parent] = heapArray[right];
            heapArray[right] = temp;
            parent = right;
            left = 2 * parent;
            right = 2 * parent + 1;
            continue;
        }
        break;
    }
}

bool HeapSort::isHeapEmpty() {
    if(heapArray[*lastItem] == 0) {return true;}
    else {return false;}
}

bool HeapSort::isHeapFull() {
    if(*lastItem == arrayLength) {return true;}
    else {return false;}
}

void HeapSort::printHeap(){
    for(int i = 1; i <= 10; i++){
        if(heapArray[i] != 0)
            outfile << heapArray[i] << " ";
    }
    outfile << endl;
}

void HeapSort::printTree(int root) {
    if (root == 0) return;
    queue<int> currentLevel, nextLevel;
    currentLevel.push(root);
    while (!currentLevel.empty()) {
        int currNode = currentLevel.front();
        currentLevel.pop();
        if (currNode < arrayLength) {
            cout << heapArray[currNode] << " ";
            nextLevel.push(currNode*2);
            nextLevel.push(currNode*2+1);
        }
        if (currentLevel.empty()) {
            cout << endl;
            swap(currentLevel, nextLevel);
        }
    }
}
