#include <stdio.h>
int linearSearch(int array[], int n, int key){
 for (int i = 0; i < n; i++){
 if (array[i] == key){
 return i;
 }
 }
 return -1;
}
int binarySearch(int array[], int key, int low, int high){
 while (low <= high){
 int mid = low + (high - low) / 2;
 if (array[mid] == key)
 return mid;
 if (array[mid] < key)
 low = mid + 1;
 else
 high = mid - 1;
 }
 return -1;
}
int main(){
 int key, size, choice = 0, result;
 printf("enter the array size");
 scanf("%d",&size);
 int arr[size];
 printf("Enter the array elements : ");
 for (int i = 0; i < size; i++){
 scanf("%d", &arr[i]);
 }
 printf("Enter the search key : ");
 scanf("%d", &key);
 while (choice != 3){
 printf("\nEnter the choice 1 - Linear search, 2 - Binary search, 3 - Exit \n");
 scanf("%d", &choice);
 switch (choice){
 case 1:
 result = linearSearch(arr, size, key);
 if (result == -1){
 printf("key is not found\n");
 }
 else{
 printf("the key is found at %d\n", result+1);
 }
 break;
 case 2:
 result = binarySearch(arr, key, 0, size - 1);
 if (result == -1)
 printf("Not found\n");
 else
 printf("Element is found at index %d\n", result+1);
 break;
 case 3:
 printf("Exiting...");
 break;
 }
 }
}