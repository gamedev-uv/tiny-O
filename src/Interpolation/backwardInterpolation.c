#include <stdio.h>
#include <string.h>

int printRepeat(char ch, int n)
{
    for(int i = 0; i < n; i++)
        printf("%c", ch);

    return n;
}

void displayTableElement(float value, int width)
{
    char buffer[50];
    int len = sprintf(buffer, "%f", value);
    int leftPad = (width - len) / 2;
    int rightPad = width - len - leftPad;

    printRepeat(' ', leftPad);  
    printf("%s", buffer);
    printRepeat(' ', rightPad);
}

void displayTable(float* table, int n)
{
    printf("\n -- DIFFERENCE TABLE --\n");
    int len = printf("|    x    |    y    |");
    for(int i = 1; i < n; i++)
    {
        len += printf("    y");
        len += printRepeat('\'', i);
        len += printf("    |");
    }
    
    printf("\n");
    printRepeat('-', len);
    printf("\n");

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= n - i; j++)
            displayTableElement(table[i * (n + 1) + j], 10 + j);
        
        printf("\n");
    }
}

float getFactorial(float x)
{
    float f = 1;
    for(int i = 2; i <= x; i++)
        f *= i;

    return f;
}

float getProduct(float x, int k)
{
    float product = x;
    
    for(int i = 1; i <= k; i++)
        product *= (x + i);

    return product;
}

void main()
{
    int n;
    float x;
    printf("--- INPUT ---");
    printf("\n - Enter n: ");
    scanf("%d", &n);

    float table[n][n+1];
    float * tablePtr = &table[0][0];
    printf(" - Enter x, y values: \n");
    for(int i = 0; i < n; i++)
    {
        printf("  - x%d, y%d: ", i, i);
        scanf("%f %f", &table[i][0], &table[i][1]);
    }

    printf(" - xT: ");
    scanf("%f", &x);

    for(int j = 2; j <= n; j++)
    {
        int lIndex = n - j; //Last Index
        for(int i = 0; i <= lIndex; i++)
            table[i][j] = table[i + 1][j - 1] - table[i][j - 1];
    }

    printf("\n--- OUTPUT ---");
    displayTable(tablePtr, n);

    float h = table[1][0] - table[0][0]; // h = x_1 - x_0
    float v = (x - table[n - 1][0]) / h;     //x - x_n / h
    
    float value = table[n - 1][1];            //value = y_n
    for(int i = 0; i < n - 1; i++)
    {
        float diff = table[n - 2 - i][2 + i];
        float vProduct = getProduct(v, i);
        float deno = getFactorial(i + 1);

        value += diff * vProduct / deno;
    }

    printf("\n f(%f): %f", x, value);
}