#include <stdio.h>


void mergeSort(int *array, int l, int r);
void merge(int *array, int l, int m, int r);
void printArray(int A[], int size);

int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Given array is \n");
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}

void mergeSort(int *array,int l, int r){
    if(l < r){
        int median = l+(r-l)/2;
        mergeSort(array, l, median);
        mergeSort(array, median+1, r);
        merge(array, l, median, r);
    }

}

void merge(int *array, int l, int m, int r){
    int size1 = m - l + 1;
    int size2 = r - m;
    int leftPart[size1];	int rightPart[size2];
    int i,j,k;

    //copy data from main array to 2 halfes
    for(i = 0; i < size1; i++ )
        leftPart[i] = array[l+i];
    for(j = 0; j < size2; j++)
        rightPart[j] = array[m+1+j];

    //sort the 2 halfes and set them to main array
    k = l;	i = 0; j = 0;
    while(i < size1 && j < size2){
        if(leftPart[i] < rightPart[j]){
            array[k] = leftPart[i];
            i++;
        }
        else{
            array[k] = rightPart[j];
            j++;
        }
        k++;
    }

    //copy the remain values in left if found
    while(i < size1){
        array[k] = leftPart[i];
        i++;
        k++;
    }
    while(j < size2){
        array[k] = rightPart[j];
        j++;
        k++;
    }
}

void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
