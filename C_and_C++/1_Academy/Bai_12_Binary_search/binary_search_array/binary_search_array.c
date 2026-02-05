#include <stdio.h>

void sort_tangdan(int arr[], int size )
{
    int temp;
    for (int i = 0; i < size; i++)
    {
        for (int j = i+1; j <= size; j++)
        {
            if(arr[i] > arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        
    }
    
}

void search_binary(int arr[], int max, int min , int number)
{
    int mid = (max + min) / 2;
    if(number == arr[mid])
    {
         printf("\nfound number %d at arr[%d]\n",number, mid);
    }
    if(number > arr[mid]){
        min = mid;
        search_binary(arr,max,min,number);
    }
    if(number < arr[mid]){
        max = mid;
        search_binary(arr,max,min,number);
    }
}

void print_sort(int arr[], int size){
    printf("\narr = ");
    for (int i = 0; i < size; i++)
    {
        printf("%d\t",arr[i]);
    }
    
}

int main()
{
    int arr[15] = {5 ,6 ,1 ,2 ,10 ,30 ,7 ,3 ,50 ,40 ,29 ,25, 48,23,85};
    print_sort(arr,15);
    sort_tangdan(arr,15);
    print_sort(arr,15);
    search_binary(arr,15,0,6);
}