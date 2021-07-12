#include <stdio.h>
int SIZE = 0;

void swap(int *a, int *b){
  int temp = *b;
  *b = *a;
  *a = temp;
}

void heapify(int arr[], int SIZE, int i){
  if (SIZE != 1){
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < SIZE && arr[l] > arr[largest])
      largest = l;
    if (r < SIZE && arr[r] > arr[largest])
      largest = r;
    if (largest != i){
      swap(&arr[i], &arr[largest]);
      heapify(arr, SIZE, largest);
    }
  }
}

void push(int arr[], int newNum){
  if (SIZE == 0){
    arr[0] = newNum;
    SIZE += 1;
  }else{
    arr[SIZE] = newNum;
    SIZE += 1;
    for (int i = SIZE / 2 - 1; i >= 0; i--){
      heapify(arr, SIZE, i);
    }
  }
}

void pop(int arr[], int num){
  int i;
  for (i = 0; i < SIZE; i++){
    if (num == arr[i])
      break;
  }

  swap(&arr[i], &arr[SIZE - 1]);
  SIZE -= 1;
  for (int i = SIZE / 2 - 1; i >= 0; i--){
    heapify(arr, SIZE, i);
  }
}

int getMax(int arr[], int SIZE){
  return arr[0];
}

void view(int arr[]){
	int i;
	for(i=0;i<=SIZE-1;i++){
		printf("%2d ", arr[i]);
	}
	printf("\n");
}

int main(){
	int arr[100];
 	push(arr,21);
	push(arr,30);
	push(arr,18);
	push(arr,10);
	push(arr,20);
	push(arr,35);
	push(arr,5);
	view(arr);
	pop(arr,arr[0]);
	view(arr);
	pop(arr,arr[0]);
	view(arr);	
}
