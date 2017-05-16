#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ARRAY_SIZE(x) (sizeof(x) / sizeof(*x))
#define PRINT_TM 8

const char *msg = "Hello, world!";

const char *ASCII = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890`~!@#$%^&*()_-+={}[]:\";'<>,.?/\\|";

void print_rand(int len)
{
    int i;
    for (i = 0; i < len; i++)
        putchar(ASCII[rand() % strlen(ASCII)]);
}

int main(void)
{
    srand(time(NULL));

    int l = strlen(msg);
    int hour = -1;

    struct tm *tm_struct;

    while (hour != PRINT_TM)
    {
        time_t cur = time(NULL);
        tm_struct = localtime(&cur);

        hour = tm_struct->tm_hour;

        print_rand(l);
        putchar('\n');
    }

    printf("%s\n", msg);
}
