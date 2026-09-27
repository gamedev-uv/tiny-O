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
    int len = sprintf(buffer, "%.3f", value);
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

float getProduct(float u, int k)
{
    float product = 1;

    for(int i = 0; i < k; i++)
        product *= (u - i);

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

    float h = table[1][0] - table[0][0];
    float u = (x - table[0][0]) / h;
    float value = table[0][1];

    for(int i = 1; i < n; i++)
    {
        float diff = table[0][i + 1];
        float uProduct = getProduct(u, i);
        float deno = getFactorial(i);

        value += diff * uProduct / deno;
    }

    printf("\n f(%f): %f", x, value);
}