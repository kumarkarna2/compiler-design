#include <bits/stdc++.h>
using namespace std;


int main()
{
    int a = 0, b = 1, c;
    int n = 10;

    c = a + b;
    printf("%d %d %d", a, b, c);
    int temp;
    for (int i = 0; i < n-3; i++)
    {
        temp = b + c;
        printf("%d ", temp);
        b = c;
        c = temp;
    }
    

    return 0;
}