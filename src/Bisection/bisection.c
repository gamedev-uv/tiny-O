#include <math.h>
#include <stdio.h> 

float f(float x)
{
    return pow(x, 3) - x - 1;
}

void main()
{
    float a = 0, b = 2;
    
    float precision;
    printf("--- INPUT ---");
    
    printf("\n - A: ");
    scanf("%f", &a);

    printf(" - B: ");
    scanf("%f", &b);

    printf(" - Precision: ");
    scanf("%f", &precision);

    float mul = f(a) * f(b);
    if(mul > 0)
    {
        printf("Invalid Range! Can't find root using bisection they yield same sign results");
        return;
    }

    if(mul == 0)
    {
        if(f(a) == 0)
            printf("A[%f] is the root", a);
        else
            printf("B[%f] is the root", b);

        return;
    }

    float m;
    do
    {
        m = (a + b) / 2;
        float fm = f(m);
        float fa = f(a);
        float fb = f(b);

        if(fabs(fm) <= precision) break;
        if(fm * f(a) < 0)
            b = m;
        else
            a = m; 

    } while (1);

    printf("\n--- OUTPUT ---");
    printf("\nApproximate root: %f", m);
}