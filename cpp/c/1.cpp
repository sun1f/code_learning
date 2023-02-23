#include <stdio.h>

int main(int, char**)
{
    printf("This fake error is in \"%s\" on line %d.\n", __FILE__, __LINE__);
    return 0;
}
