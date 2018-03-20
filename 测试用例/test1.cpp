#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

#define SIZE_OF_BUFFER 10

unsigned short ProductID = 0;
unsigned short ConsumeID = 0;
unsigned short rand_1 = 0;
unsigned short rand_2 = 0;
unsigned short in = 0;   
unsigned short out = 0;               
int buffer[SIZE_OF_BUFFER];          
int flag = 1;               
						    
HANDLE FullSemaphore;   
HANDLE EmptySemaphore;  
CRITICAL_SECTION cs;    