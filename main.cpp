#include <iostream>
#include <fstream>
#include "HeapSort.h"

using namespace std;

int main(int argc, char* argv[]) {
    ifstream infile;
    int iterate;
    int count;

    infile.open(argv[1]);
    while(infile >> iterate) {count++;}
    infile.close();

    HeapSort heap(count, argv);
    heap.buildHeap();
    heap.deleteHeap();
    //heap.printTree(1);
    return 0;
}