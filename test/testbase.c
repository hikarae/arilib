#include "base.h"

int main (){
    string str;
    stri(&str);
    printf("You entered: %s\n", str);
    stri(&str);
    printf("You entered again: %s\n", str);
    free(str);
    return 0;
}