#include <math.h>
#include <stdio.h> 

float f(float x)
{
    return pow(x, 3) - x - 1;
}

void displayTableElement(float value)
{
    char sign[3] = "  ";
    if(value < 0)
    {
        value = -value;
        sign[0] = ' ';
        sign[1] = '-';
    } 

    printf("%s%f  |", sign, value);
}

void main()
{
    float a, b;
    float precision;

    printf("--- [INPUT] ---");
    printf("\n - A: ");
    scanf("%f", &a);

    printf(" - B: ");
    scanf("%f", &b);

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

    printf(" - Iterations/precision: ");
    scanf("%f", &precision);

    int steps;
    if(roundf(precision) == precision)
        steps = (int) precision;
    else
        steps = (int) ceil(log2f(fabsf(b - a) / precision));

    printf("\n--- [OUTPUT] ---\n");
    int width = printf("| i  |     a      |      b     |    f(a)    |    f(b)    |     m      |    f(m)    |\n");
    for(int i = 0; i < width - 1; i++) 
        printf("-");

    float m;
    for(int i = 1; i <= steps; i++)
    {
        m = (a + b) / 2;
        float fm = f(m);
        float fa = f(a);
        float fb = f(b);

        printf("\n| %02d |", i);
        displayTableElement(a);
        displayTableElement(b);
        displayTableElement(fa);
        displayTableElement(fb);
        displayTableElement(m);
        displayTableElement(fm);

        if(fm * f(a) < 0)
            b = m;
        else
            a = m; 
    }
    
    printf("\nApproximate root: %f", m);
}