#include <stdio.h>
#include <stdlib.h>
int N;
void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void quickSort(int quick[],int i, int j)
{
    printf("i:%d j=%d\n",i,j);
	if(i>=j) return;
	int pivot = quick[(i+j)/2];
	int left = i;
	int right = j;
    printf("pivot:[%d] %d\n",(i+j)/2,pivot);
	while(left<=right)
	{
		while(quick[left]<pivot) left++;
		while(quick[right]>pivot) right--;
		if(left<=right)
		{
			printf("swaped left =[%d] %d right = [%d] %d\n",left,quick[left],right,quick[right]);
            swap(&quick[left],&quick[right]);
			left++; right--;
		}
	}
    printf("end sub routine\n");
    for(int i =0; i<N; i++) printf("%d ",quick[i]);
    printf("\n");
	quickSort(quick,i,right);
	quickSort(quick,left,j);
}
int main(){
    const int MAX_SIZE = 1e6;

    int *arr = NULL;
    
    scanf("%d",&N);
    arr = (int*)malloc(sizeof(int)*(N));

    for(int i=0; i<N; i++) scanf("%d",&arr[i]);

    quickSort(arr,0,N-1);
    
    for(int i =0; i<N; i++) printf("%d\n",arr[i]);
    
    free(arr);


    return 0;
}

 