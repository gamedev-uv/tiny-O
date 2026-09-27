#include <stdio.h>

float getProduct(int r, float x, float * xPoints, int n)
{
    float product = 1;
    for(int i = 0; i < n; i++)
    {
        if(i == r) continue;
        product *= x - xPoints[i];
    }

    return product;
}

float l(int i, float x, float * xPoints, int n)
{
    return getProduct(i, x, xPoints, n) / getProduct(i, xPoints[i], xPoints, n);
}

float P(float x, float * xPoints, float * yPoints, int n)
{
    float sum = 0;
    for(int i = 0; i < n; i++)
        sum += yPoints[i] * l(i, x, xPoints, n);

    return sum;
}

void main()
{
    int n;

    printf("--- INPUT ---");
    printf("\n - N: ");
    scanf("%d", &n);

    float dataX[n], dataY[n];
    printf(" - Enter Elements -\n");
    for(int i = 0; i < n; i++)
    {
        printf("  - x%d, y%d: ", i, i);
        scanf("%f %f", &dataX[i], &dataY[i]);
    } 

    float x;
    printf(" - Target x: ");
    scanf("%f", &x);

    printf("\n--- OUTPUT ---\n");
    printf("P(%f): %f", x, P(x, dataX, dataY, n));
}