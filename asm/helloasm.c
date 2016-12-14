#include <stdio.h>

int main(int argc, char* argv[])
{
    int a = 1;
    int nValue;
    
    // ams (asms : output : input : clobber); 
    __asm__ ("mov %1, %0\n\t"
             "add $1, %0"
             : "=r" (nValue)
             : "r" (a));
     
    printf("%d\n", nValue);

    return 0;
}
