Heap Sort

Input: a text file contains a list of numbers (positive integers). 
       **** The name of the input file should be given in argv[1]

Output: a text file contains sorted  input numbers.
        **** The name of the output file should be given in argv[2]

Data structure:
  	A HeapSort class, including 
		- an 1-D integer array (dynamically allocated within the program)
		- methods include: buildHeap, DeleteHeap, insertOneDataItem
		  DeleteRoot, bubbleUp, bubbleDown, isHeapEmpty, isHeapFull, printHeap, etc..
		
Algorihtm steps:

Step 1: - open the input file; 
	- read and count the number of date item in the  input file
	- close the file

step 2: dynamically allocate the 1-D array of the size count+1


step 3: call buildHeap (see algorithm below) 

step 4: call deleteHeap (see algorithm below)


buildHeap algorithm:

    step 1: open the input file for the second time
 
    step 2: data <-- get a data item from the input file

    step 3: call insertOneDataItem 
	     (inside of the insertOneDataItem, make sure the heap is not full, and call bubbleUp )
   
    step 4: call printHeap (prnit only the first 10 items of the heap to the output file)
            // in the real life, this is only for your debugging purpose

    step 5: repeat step 1 - 4 until the input file is empty

    ste[ 6: close the input file


deleteRoot algorithm:

    step 1: open the output file
    
    step 2: call deleteRoot 
              (inside of deleteRoot, make sure the heap is not empty, 
			     print the root to the output file and call bubbleDown)

    step 3: call printHeap (prnit only the first 10 items of the heap to the output file)
           // in the real life, this is only for your debugging purpose
 
    ste[ 4: repeat step 1 and 3 untile the heap is empty

    step 5: close the output file

