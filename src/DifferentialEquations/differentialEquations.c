#include <stdio.h>

float f(float x, float y)
{
    return x + y;
}

float eulersMethod(float x0, float y0, float h, float xT)
{
    float x = x0;
    float y = y0;
    while(x < xT)
    {
        if(x + h > xT)
            h = xT - x;

        y = y + f(x, y) * h;  
        x = x + h;
    }

    return y;
}

float rk4Method(float x0, float y0, float h, float xT)
{
    float x = x0;
    float y = y0;
    while(x < xT)
    {
        if(x + h > xT)
            h = xT - x;

        float k1 = h * f(x, y);
        float k2 = h * f(x + h/2.0f, y + k1/2.0f);
        float k3 = h * f(x + h/2.0f, y + k2/2.0f);
        float k4 = h * f(x + h, y + k3);

        y = y + 1.0f/6.0f * (k1 + 2 * k2 + 2 * k3 + k4); 
        x = x + h;
    }

    return y;
}

void main()
{
    float x0, y0;
    float h, xT;

    printf("--- INPUT ---\n");
    printf(" - x0: ");
    scanf("%f", &x0);

    printf(" - y0: ");
    scanf("%f", &y0);

    printf(" -  h: ");
    scanf("%f", &h);

    printf(" - xT: ");
    scanf("%f", &xT);

    printf("\n--- OUTPUT ---");
    printf("\nEuler's Method: f(%f): %f", xT, eulersMethod(x0, y0, h, xT));
    printf("\nRK 4    Method: f(%f): %f", xT, rk4Method(x0, y0, h, xT));
}