#include<stdio.h>
void quicksort(int arr[], int low, int high) {
	int i, j, pivot, temp;
	  
     if(low < high) {
     	pivot = arr[low];
     	i= low;
     	j = high;
     	
     	while(i < j) {
     		while(arr[i] <= pivot && i < high)
     		i++;
     		while(arr[j] > pivot)
     		j--;
     		if(i<j) {
     			temp=arr[i];
     			arr[i]=arr[j];
     			arr[j]=temp;
     			
			 }
		 }
		 arr[low] = arr[j];
		 arr[j] = pivot;
		 quicksort(arr, low, j - 1);
		 quicksort(arr, j+1, high);
		 
	 }
}
int main()
{
	int arr[100], n;
	printf("Enter number of elements:");
	scanf("%d",&n);
	printf("Enter elements:\n");
	for(int i = 0; i<n;i++) {
		scanf("%d",&arr[i]);
	}
	
	quicksort(arr, 0, n - 1);
	printf("sorted array:\n");
	for(int i=0;i<n;i++) {
		printf("%d",arr[i]);
	}
	return 0;
}
