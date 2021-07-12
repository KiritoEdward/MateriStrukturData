#include<stdio.h>

int heap[100]; //max 99 element, root starts with index 1
int count = 0;

int getParentIdx(int index){
	return index/2;
}

int getLeftChildIdx(int index){
	return index*2;
}

int getRightChildIdx(int index){
	return index*2+1;
}

void upheapmin(int index){
	if(index <=1) return;
	int parentIdx = getParentIdx(index);
	if(heap[index] < heap[parentIdx]){
		int temp = heap[index];
		heap[index] = heap[parentIdx];
		heap[parentIdx] = temp;
		upheapmin(parentIdx);
	}
}

void push(int value){
	count++;
	heap[count] = value;
	upheapmin(count);
}

void view(){
	int i;
	for(i=1;i<=count;i++){
		printf("%2d ", heap[i]);
	}
	printf("\n");
}

//    1
//  2   3
// 4 5  
// count = 5
void downheapmin(int index){
	if(index*2 > count) return;
	int left = getLeftChildIdx(index);
	int right = getRightChildIdx(index);
	
	int smallest = index;
	if(left <=count && heap[left] < heap[smallest]){
		smallest = left;
	}
	if(right <= count && heap[right] < heap[smallest]){
		smallest = right;
	}
	
	if(smallest == index) return;
	
	int temp = heap[index];
	heap[index] = heap[smallest];
	heap[smallest] = temp;
	
	downheapmin(smallest);
}

void pop(){
	if(count == 0){
		return;
	}
	heap[1] = heap[count];
	count--;
	downheapmin(1);
}

int main(){
	push(21);
	push(30);
	push(18);
	push(10);
	push(20);
	push(35);
	push(5);
	printf("Jumlah Data : %d\n",count);
	view(); // 1 8 10 20
	pop();
	printf("Jumlah Data : %d\n",count);
	view();
	return 0;
}
