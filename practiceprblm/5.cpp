#include <iostream>
using namespace std;

int isPrime(int n)
{
    if(n < 2 ) return 0;

    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        return 0;
    }
    return 1;   
}

int main() {
    int n;
    printf("양수 입력");
    scanf("%d", &n);

    int *arr = (int*)malloc(sizeof(int)* n);
    
    for (int i = 0; i < n; i++)
    {
        if(isPrime(i+2))
            arr[i] = i+2 ;

        else
            arr[i] = -1 ;

    }
    
    for (int i = 0; i < n-1 ; i++)
    {
        if (arr[i] == -1)
            printf("%3c", 'x');

        else if (arr[i] == i+2)  
            printf("%3d", arr[i]);

        if ((i+1) % 5 == 0)
            printf("\n");


    }
    
    free(arr);

    
    return 0;
}