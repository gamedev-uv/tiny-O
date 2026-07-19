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
    printf("Finding root of the equation x^3 + x - 1. Using a = 0, b = 2");
    printf("\n--- INPUT ---");
    printf("\n - Enter precision: ");
    scanf("%f", &precision);

    int steps = (int) ceil(log2f(fabsf(b - a) / precision));

    float m = (a + b) / 2;
    for(int i = 0; i < steps ; i++)
    {
        float value = f(m);

        if(fabsf(value) <= precision) 
            break;

        if(value < 0)
            a = m;
        else
            b = m;

        m = (a + b) / 2;
    }

    printf("\n--- OUTPUT ---");
    printf("\nApproximate root: %f. After %d iterations", m, steps);
}