#include <stdio.h>
int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    // printing array elements
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", arr[i]);
    }
    // modifying array elements
    arr[2] = 10; // changing 3rd element to 10
    printf("After modification:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", arr[i]);
    }

    for(int x: arr){ //for each loop
        printf("%d\n", x);
    }   
    return 0;
}