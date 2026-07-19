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
    float a = 0, b = 2;
    
    float precision;
    printf("--- [INPUT] ---");
    printf("\n - Enter number of iterations/precision: ");
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

    for(int i = 1; i <= steps; i++)
    {
        float m = (a + b) / 2;
        float value = f(m);

        printf("\n| %02d |", i);
        displayTableElement(a);
        displayTableElement(b);
        displayTableElement(f(a));
        displayTableElement(f(b));
        displayTableElement(m);
        displayTableElement(f(m));

        if(value < 0)
            a = m;
        else
            b = m;
    }
}