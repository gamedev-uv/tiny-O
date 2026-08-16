#include <stdio.h>
#include <math.h>

float f(float x)
{
    return pow(x, 2);
}

float midPointMethod(float a, float b, int n)
{
    float width = (b - a) / n;
    float halfWidth = width / 2;

    float x = a;
    float value = 0;
    for(int i = 0; i < n; i++)
    {
        value += f(x + halfWidth);
        x += width;
    }

    return value * width;
}

float trapeziodMethod(float a, float b, int n)
{
    float width = (b - a) / n;
    float halfWidth = width / 2;

    float x = a;
    float value = f(x);
    for(int i = 1; i <= n - 1; i++)
    {
        x += width;
        value += 2 * f(x);
    }

    x += width;
    value += f(x);

    return halfWidth * value;
}

float simpsonsOneThird(float a, float b, int n)
{
    if(n % 2 != 0)
    {
        printf("\nCan't compute the integral as n is not even");
        return 0;
    }

    float width = (b - a) / n;

    float x = a;
    float value = f(x);

    for(int i = 1; i <= n - 1; i++)
    {
        x += width;
        float mul = i % 2 == 0 ? 2 : 4;
        value += mul * f(x);
    }

    x += width;
    value += f(x);

    return width / 3 * value;
}

void main()
{
    int n;
    float a, b;

    printf("--- INPUT ---");
    printf("\n - Enter n: ");
    scanf("%d", &n);

    printf(" - Enter interval: ");
    scanf("%f %f", &a, &b);

    printf("\n--- OUTPUT ---");
    printf("\n - Midpoint  Appoximation  : %f", midPointMethod(a, b, n));
    printf("\n - Trapeziod Approximation : %f", trapeziodMethod(a, b, n));
    printf("\n - Simpsons  Approximation : %f", simpsonsOneThird(a, b, n));
}