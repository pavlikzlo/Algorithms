#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int IsRepetitive(char *s)
{
    unsigned long prefix_length = strlen(s);
    long divider = 1;
    while (divider <= (prefix_length/2)) {
        if ((prefix_length%divider) == 0) {
            char *temp = (char*)malloc(sizeof(char)*divider);
            char *temp2 = (char*)malloc(sizeof(char)*divider);
            strncpy(temp, s, divider);
            strncpy (temp2, s+divider, divider);
            long count = divider;
            while (!strcmp(temp, temp2) && (count < prefix_length)) {
                count += divider;
                strcpy(temp,temp2);
                strncpy(temp2, s+count, divider);
            }
            if ((count) == prefix_length) {
                printf("%ld %ld\n", prefix_length, prefix_length/divider);
                return 1;
            }
        }
        divider++;
    }
    return 0;
}

void Prefix(char *s)
{
    int string_length = 0, prefix_length = 2;
    string_length = strlen(s);
    while (prefix_length <= string_length) {
        char *new_prefix = (char*)malloc(sizeof(char)*prefix_length);
        strncpy(new_prefix, s, prefix_length);
        IsRepetitive(new_prefix);
        prefix_length++;
    }
}

int main(int argc, char *argv[]) {
    int string_length = 0;
    char *xyi = (char*)malloc(10);
    strcpy (xyi, "aaaa");
    string_length = strlen(argv[1]);
    Prefix(argv[1]);
    //IsRepetitive(xyi);
    return 0;
}