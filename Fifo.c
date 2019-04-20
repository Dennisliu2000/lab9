// Fifo.c
// Runs on LM4F120/TM4C123
// Provide functions that implement the Software FiFo Buffer
// Last Modified: November 14, 2018
// Student names: change this to your names or look very silly
// Last modification date: change this to the last modification date or look very silly

#include <stdint.h>
// --UUU-- Declare state variables for Fifo
//        buffer, put and get indexes
int count;
int getIndex;
int putIndex;
char fifo[6]={0};
// *********** Fifo_Init**********
// Initializes a software FIFO of a
// fixed size and sets up indexes for
// put and get operations
void Fifo_Init(){
	count = getIndex = putIndex = 0;
}

// *********** Fifo_Put**********
// Adds an element to the FIFO
// Input: Character to be inserted
// Output: 1 for success and 0 for failure
//         failure is when the buffer is full
uint32_t Fifo_Put(char data){
if(count == 6)	//6 bits should be sent and kept in the FIFO structure "0.0000"
	return 0; 
fifo[putIndex] = data;
putIndex = (putIndex+1)%5;
count++; 				//DISABLE AND RE-ENABLE INTERRUPTS BEFORE AND AFTER THIS
  return(1);
}

// *********** FiFo_Get**********
// Gets an element from the FIFO
// Input: Pointer to a character that will get the character read from the buffer
// Output: 1 for success and 0 for failure
//         failure is when the buffer is empty
uint32_t Fifo_Get(char *datapt){ 
if(count == 0)
	return 0;
*datapt = fifo[getIndex];
getIndex = (getIndex+1)%5;
count--;			//DISABLE AND RE-ENEABLE INTERRUPTS BEFORE AND AFTER THIS
  return(1);
}



