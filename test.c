#include <stdio.h>

int main()
{
    int n = 4;
    int xorNum = 2;
    int res = n ^ xorNum;
    printf("The result of %d XOR %d is: %d\n", n, xorNum, res);

    int x = 15;
    int y = 7;
    res = x & y;
    printf("The result of %d AND %d is: %d\n", x, y, res);
    
    
    int a = 2;
    int b = 3;
    res = b << 2;
    printf("The result of %d left shifted by %d is: %d\n", a, b, res);
    
    a = 2;
    b = 5;
    res = a << b;
    printf("The result of %d left shifted by %d is: %d\n", a, b, res);
    return 0;


}