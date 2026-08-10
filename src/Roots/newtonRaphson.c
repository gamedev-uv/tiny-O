#include <stdio.h>
#include <math.h>

float f(float x)
{
    return pow(x, 3) - 9 * x + 3;
}

float dF(float x)
{
    return 3 * pow(x, 2) - 9;
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
    float x0;
    printf("--- [INPUT] ---");
    printf("\n - x_0: ");
    scanf("%f", &x0);

    float precision;
    printf(" - Iterations/precision: ");
    scanf("%f", &precision);

    int steps;
    if(roundf(precision) == precision)
        steps = (int) precision;
    else
        steps = __INT_MAX__;

    float x = x0;
    int width = printf("| i  |      x      |    f(x)    |    f'(x)    |\n");
    for(int i = 0; i < width - 1; i++) 
        printf("-");

    int i = 1;
    while(i <= steps)
    {
        float fx = f(x);
        float dfx = dF(x);

        if(dfx == 0)
        {
            printf("\nCan't compute further as the derivate at the point is zero!");
            break;
        }

        printf("\n| %02d | ", i);
        displayTableElement(x);
        displayTableElement(fx);
        displayTableElement(dfx);
        if(fabsf(fx) <= precision && steps == __INT_MAX__)
            break;

        x = x - (fx / dfx);
        i++;
    }

    printf("\n\n--- [OUTPUT] ---");
    printf("\nRoot: %f", x);
}