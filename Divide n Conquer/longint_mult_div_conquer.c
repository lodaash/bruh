#include <stdio.h>
// #include <conio.h>
#include <math.h>

long prod(long, long);
long noOfDigit(long, long);

void main()
{
    long m, n;
    printf("\n-----------------------------------------------");
    printf("\nMULTIPLICATION USING DIVIDE & CONQUER");
    printf("\n-----------------------------------------------");
    printf("\n Enter number1:");
    scanf("%ld", &m);
    printf("\n Enter number2:");
    scanf("%ld", &n);
    printf("\n-----------------------------------------------");
    printf("\n multiplication of %ld and %ld is:%ld", m, n, prod(m, n));
    printf("\n-----------------------------------------------");
}

long prod(long u, long v)
{
    long x, y, w, z;
    long n, m, p, q, r;

    n = noOfDigit(u, v);
    // The code then checks if either u or v is zero. If so, it means one of the numbers is zero, and the function returns 0 as the result.

    if (u == 0 || v == 0)
    {
        return 0;
    }
    // no. of digits < 2, hence normal multiplication
    else if (n <= 2)
    {
        return (u * v);
    }
    else
    {
        m = floor(n / 2);  //determines the split point

        w = u / pow(10, m);
        x = u % (int)pow(10, m);
        y = v / pow(10, m);
        z = v % (int)pow(10, m);

        p = prod(w, y);
        q = prod(x, z);
        r = prod(w + x, y + z);

        return p * pow(10, 2 * m) + (r - p - q) * pow(10, m) + q;
    }
}

//to count the number of digits
long noOfDigit(long m, long n)
{
    long max;
    int b = 0;
    if (m >= n)
        max = m;
    else
        max = n;
    //to count the number of digits
    while (max > 0)
    {
        max = max / 10;
        b++;
    }
    return b;
}
