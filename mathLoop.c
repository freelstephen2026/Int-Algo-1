#include <math.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>

int numOfDigits(int n); //returns the number of digits from integer n
char nthDigit(int x, int n); //returns the nth digit of int x
char* intToStr(int n); //convert int n to a string
void erase(char* s); //clear the last thing printed in Console
int intSqrt(int n); //takes the integer-valued square root of an integer n
void clear_keyboard_buffer(void); //clears the keyboard buffer

int main(int argc, char* argv[])
{
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);
    num = intSqrt(num);
    char* lastPrint, *new_lastPrint;
    //important: new_lastPrint stores the last thing was printed through the Console, where we can later execute a function on to eliminate the last printed string from Console
    lastPrint = intToStr(num);
    new_lastPrint = lastPrint;
    printf("%d", num);
    int cond = 0;
    int which = 1;
    int new_which = 1;
    while (cond == 0)
    {
        if (which == 0)
        {
            num = intSqrt(num);
            new_lastPrint = intToStr(num);
            new_which = 1;
        }

        else if (which == 1)
        {
            num = 2 * num;
            new_lastPrint = intToStr(num);
            new_which = 0;
        }
        which = new_which;
        
        erase(lastPrint);
        lastPrint = new_lastPrint;
        printf(lastPrint);
        
        if (num == 1)
        {
            cond = 1;
        }
    }

    printf("We have reached the integer 1");

	return 0;
}

int numOfDigits(int n) 
{
    char str[50];
    sprintf(str, "%d", n);
    return strlen(str);
}

char nthDigit(int x, int n)
{
    char str[50];
    sprintf(str, "%d", x);
    return str[n];
}

char* intToStr(int n) 
{
    char* ret = malloc(50);
    int i;
    for (i = 0; i < numOfDigits(n); i++)
    {
        ret[i] = nthDigit(n, i);
    }
    for (i = numOfDigits(n); i < 50; i++)
    {
        ret[i] = '\0';
    }

    return ret;
}

void erase(char* s) 
{
    int i;
    Sleep(1000);
    for (i = 0; i < strlen(s); i++)
    {
        printf("\b");
    }
}

int intSqrt(int n)
{
    int ret;
    ret = sqrt(n);
    return ret;
}

void clear_keyboard_buffer(void)
{
    char c;
    scanf("%c", &c);
    while (c != '\n')
    {
        scanf("%c", &c);
    }
}