#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
// A heap has current size and array of elements
struct MaxHeap
{
    int size;
    int* array;
};
 
// A utility function to swap to integers
void swap(int* a, int* b) { int t = *a; *a = *b;  *b = t; }
 
// The main function to heapify a Max Heap. The function assumes that 
// everything under given root (element at index idx) is already heapified
void maxHeapify(struct MaxHeap* maxHeap, int idx)
{
    int largest = idx;  // Initialize largest as root
    int left = (idx << 1) + 1;  // left = 2*idx + 1
    int right = (idx + 1) << 1; // right = 2*idx + 2
 
    // See if left child of root exists and is greater than root
    if (left < maxHeap->size && maxHeap->array[left] > maxHeap->array[largest])
        largest = left;
 
    // See if right child of root exists and is greater than the largest so far
    if (right < maxHeap->size && maxHeap->array[right] > maxHeap->array[largest])
        largest = right;
 
    // Change root, if needed
    if (largest != idx)
    {
        swap(&maxHeap->array[largest], &maxHeap->array[idx]);
        maxHeapify(maxHeap, largest);
    }
}
 
// A utility function to create a max heap of given capacity
struct MaxHeap* createAndBuildHeap(int *array, int size)
{
    int i;
    struct MaxHeap* maxHeap = (struct MaxHeap*) malloc(sizeof(struct MaxHeap));
    maxHeap->size = size;   // initialize size of heap
    maxHeap->array = array; // Assign address of first element of array
 
    // Start from bottommost and rightmost internal mode and heapify all
    // internal modes in bottom up way
    for (i = (maxHeap->size - 2) / 2; i >= 0; --i)
        maxHeapify(maxHeap, i);
    return maxHeap;
}
 
// The main function to sort an array of given size
void heap_sort(int* array, int size)
{
    // Build a heap from the input data.
    struct MaxHeap* maxHeap = createAndBuildHeap(array, size);
 
    // Repeat following steps while heap size is greater than 1. The last
    // element in max heap will be the minimum element
    while (maxHeap->size > 1)
    {
       // The largest item in Heap is stored at the root. Replace it with the 
       // last item of the heap followed by reducing the size of heap by 1.
        swap(&maxHeap->array[0], &maxHeap->array[maxHeap->size - 1]);
        --maxHeap->size;  // Reduce heap size
 
        // Finally, heapify the root of tree.
        maxHeapify(maxHeap, 0);
    }
}
 
// A utility function to print a given array of given size
void printArray(int* arr, int size)
{
    int i;
    for (i = 0; i < size; ++i)
        printf("%d ", arr[i]);
}
   

int main(int argc, char *argv[]){

   FILE *log_average = fopen("log_heap_average.txt", "a");
   FILE *log_best = fopen("log_heap_best.txt", "a");
   FILE *log_worst = fopen("log_heap_worst.txt", "a");

   //used for calculating time within the function used for searching the element
   clock_t begin, end;
   double time_spent;

   int input_size;

   if(log_average==NULL || log_best==NULL || log_worst==NULL){

      printf("Error in opening of the log text files\n");
      return 0;
   }

   if(argc < 2){
      //missing number of arguments
      printf("Error : enter the value of n as an argument\n");
      return 0;
   }

   if(argv[1] != NULL){
            
      input_size = atoi(argv[1]);//now we have the input size for the array
      
   }


   //allocating dyanamic memory for the array in question
   //this step will be the same for all the three cases to be taken care of
   //memory equal to the size of the input size is assigned

  int array[input_size];

   //Reporting error if any
   if(!array){
      fputs("Memory allocation failed.\n", stderr);
      exit(EXIT_FAILURE);
   }

   //need to generate numbers in an random order, ascending order and in the descending order

   //generating numbers in an random order and storing them in the array
   int j, temp, i;
   int list[input_size];

   for (j = 0; j < input_size; j++){
      
      list[j] = j;
   }
   
   for (i = 0; i < input_size; i++){
   //will store in the array numbers in a random order equal to the input size
      j = i + rand() % (input_size - i);
      temp = list[i];
      list[i] = list[j];
      list[j] = temp;

      array[i] = list[i]; //this array will be having elements in the random distinct order

   }


   //beginning with the internal time heaper
   begin = clock();

   heap_sort(array, input_size);//calling the heap sort function for sorting the array
   //ending with the internal time heaper
   end = clock();

   time_spent = (double)(end - begin) / CLOCKS_PER_SEC;


   fprintf(log_average, "%d %lf\n", input_size, time_spent);

   //generating numbers in an ascending order and storing them in the array
   for (j = 0; j < input_size; j++){
      //will store in the array numbers in a random order equal to the input size
      array[j] = j;
   
   }
   
   begin = clock();

   heap_sort(array, input_size);

   end = clock();

   time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
   fprintf(log_best, "%d %lf\n", input_size, time_spent);

   
    //The best case input is an array that is already sorted. In this case heap sort has a linear running time (i.e., Θ(n)). 
   //generating numbers in an descending order and storing them in the array
   i = 0;
    
    for (j = input_size-1; j >= 0; j--){
      //will store in the array numbers in a random order equal to the input size
      array[i++] = j;
   
   }
   

   begin = clock();
   
   heap_sort(array, input_size);
   
   //ending with the internal time heaper
   end = clock();

   time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

   fprintf(log_worst, "%d %lf\n", input_size, time_spent);

    //The simplest worst case input is an array sorted in reverse order.
    //This gives heap sort a quadratic running time (i.e., O(n2)).
}


