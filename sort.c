#include <stdio.h>
#include <ctype.h>
#include <dirent.h>
#include <sys/dir.h>
#include <stdlib.h>

#ifndef nullptr
#define nullptr ((void*)0)
#endif

unsigned short int
cmpstring(const char *str1, const char *str2)
{
    while ((*str1 != 0) && (*str2 != 0)) {
        char a = tolower(*str1);
        char b = tolower(*str2);
        if (a == b) {
            *str1++;
            *str2++;
        }
        else if (a < b)
            return 1;
        else if (a > b)
            return 0;
    }
    return (*str1 == 0) ? 1 : 0;
}

void
strsort(char *list[], int maxstr)
{
    char *old;
    int x, changes;

    x = changes = 1;
    while (changes) {
        changes = x = 0;
        while (x < (maxstr - 1)) {
            if (cmpstring(list[x+1],list[x])) {
                changes++;
                old = list[x];
                list[x] = list[x+1];
                list[x+1] = old;
            }
            x++;
        }
    }
    return;
}

int
sortdir(struct dirent **list)
{
    struct dirent *old;
    int x, changes;

    x = changes = 1;
    while (changes) {
        changes = x = 0;
        while (list[x+1] != nullptr) {
            if (cmpstring(list[x+1]->d_name,list[x]->d_name)) {
                changes++;
                old = list[x];
                list[x] = list[x+1];
                list[x+1] = old;
            }
            x++;
        }
    }
    return x;
}

int main()
{
    char *sort[] = {"ryan", "likes", "life", "when", "he", "is", "writing", "code"};

    strsort(sort, sizeof(sort)/sizeof(char**));

    int i = 0;
    while (sort[i]) 
        puts(sort[i++]);
}
