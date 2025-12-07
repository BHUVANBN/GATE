#include <stdio.h>
int main()
{
    int arr[5] = {1, 2, 3, 4, 5}; //array initialisation
    // printing array elements
    //int arrr[5]; //declaration of empty array - garbage values are stored 
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }
    // modifying array elements
    arr[2] = 10; // changing 3rd element to 10
    printf("\nAfter modification:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\nUsing for each loop:\n");
    for(int x: arr){ //for each loop
        printf("%d ", x);
    }   
    return 0;
}