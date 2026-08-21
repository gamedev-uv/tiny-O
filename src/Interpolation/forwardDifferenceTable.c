#include <stdio.h>
#include <string.h>

int printRepeat(char ch, int n)
{
    for(int i = 0; i < n; i++)
        printf("%c", ch);

    return n;
}

void displayTableElement(int value, int width)
{
    char buffer[50];
    int len = sprintf(buffer, "%02d", value);
    int leftPad = (width - len) / 2;
    int rightPad = width - len - leftPad;

    printRepeat(' ', leftPad);
    printf("%s", buffer);
    printRepeat(' ', rightPad);
}

void main()
{
    int n;
    printf("--- INPUT ---");
    printf("\n - Enter n: ");
    scanf("%d", &n);

    int x[n];
    int deltas[n  * (n + 1) / 2];

    printf(" - Enter x, y values: \n");
    for(int i = 0; i < n; i++)
    {
        printf("  - x%d, y%d: ", i, i);
        scanf("%d %d", &x[i], &deltas[i]);
    }

    int offset = n;
    int prevCol = 0;
    int presCol = offset;

    for(int i = 1; i <= n; i++)
    {
        int count = n - i;
        for(int j = 0; j < count; j++)
        {
            int k = prevCol + j;
            deltas[presCol + j] = deltas[k + 1] - deltas[k];
        }

        offset--;
        prevCol = presCol;
        presCol += offset;
    }

    printf("\n\n=== FORWARD DIFFERENCE TABLE ===\n");
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
        displayTableElement(x[i], 10);

        int offset = i;
        for(int j = 0; j < n - i; j++)
        {
            displayTableElement(deltas[offset], 10 + j);
            offset += n - j;
        }

        printf("\n");
    }
}