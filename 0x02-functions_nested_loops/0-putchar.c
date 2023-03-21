#include "main.h"
/*
 */
int main(void)
{
        char word[8] = "_putchar";
        int i = 0;

        while(i < sizeof(word))
        {
                _putchar(word[i]);
                i++;
        }
        _putchar('\n');

        return (0);

}
