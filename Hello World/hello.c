#include <stdio.h>

int main() {

    char name[50];

    printf("Haii!! :33\n");
    printf("Whatcha called mate?\n");

    fgets(name, 50, stdin);

    int i = 0;
    while(name[i] != '\0'){
        i++;
    }

    name[i-1] = '\0';

    printf("Yoo, hi %s\n", name);
    printf("Your name has %d characters.\n", i-1);

    return 0;

}