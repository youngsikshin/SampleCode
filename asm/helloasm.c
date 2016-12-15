#include <stdio.h>

int main(int argc, char* argv[])
{
    int a = 3;
    int nValue;//2
    
    // ams (asms : output : input : clobber); 
    __asm__ __volatile__("mov $5, %%eax\n\t"
                         "mov $2, %0"
                         : "=r" (nValue)
                         : "r" (a));
     
    printf("%d %d \n", a, nValue);


    int A = 5;
    int B = 7;
    int C = 0;

    __asm__ __volatile__ ("mov %1, %%eax\n\t"
                          "mov %2, %%ebx\n\t"
                          "add %%ebx, %%eax\n\t"
                          "mov %%eax, %0"
                          : "=r" (C)
                          : "r" (A), "r" (B));

    printf("%d + %d = %d\n", A, B, C);

    __asm__ __volatile__ ("mov %1, %%ebx\n\t"
                          "sub %2, %%ebx\n\t"
                          "mov %%ebx, %0"
                          : "=r" (C)
                          : "r" (A), "r" (B));

    printf("%d - %d = %d\n", A, B, C);

    __asm__ __volatile__ ("mov $15, %%ebx\n\t"
                          "mov %1, %%eax\n\t"
                          "mul %%ebx\n\t"
                          "mov %0, %%eax"
                          : "=r" (C)
                          : "r" (A));

    printf("%d * %d = %d\n", A, 15, C);

    B = 0;

    __asm__ __volatile__ ("mov $17, %%eax\n\t"
                          "mov %2, %%ebx\n\t"
                          "cdq\n\t"
                          "div %%ebx\n\t"
                          "mov %%eax, %0\n\t"
                          "mov %%edx, %1"                    
                          : "=r" (B), "=g" (C)
                          : "g" (A));

    printf("%d / %d = %d, %d\n", 17, A, B, C);

    __asm__ __volatile__ ("mov %0, %%eax\n\t"
                          "inc %%eax\n\t"
                          "Dec %%eax\n\t"
                          "Dec %%eax\n\t"
                          "mov %%eax, %0"
                          : "=r" (A)
                          : "r" (A));
    
    printf("%d\n",A);

    __asm__ __volatile__ ("mov %1, %%eax\n\t"
                          "shl $3, %%eax\n\t"
                          "mov %%eax, %0"
                          : "=r" (nValue)
                          : "r" (nValue));

    printf("shl result : %d\n", nValue);

    __asm__ __volatile__ ("mov %1, %%eax\n\t"
                          "shr $2, %%eax\n\t"
                          "mov %%eax, %0"
                          : "=r" (nValue)
                          : "r" (nValue));

    printf("shr result : %d\n", nValue);

    nValue = 0;
    __asm__ __volatile__ ("mov $0, %%eax\n\t"
                          "SIMDLOOP:\n\t"
                          "inc %%eax\n\t"
                          "cmp $1000, %%eax\n\t"
                          "jne SIMDLOOP\n\t"
                          "mov %%eax, %0"
                          : "=r" (nValue));

    printf("Result: %d\n",nValue);

    nValue = 1000;
    __asm__ __volatile__ ("mov $0, %%eax\n\t"
                          "SIMDLOOP2:\n\t"
                          "dec %%eax\n\t"
                          "cmp $0, %%eax\n\t"
                          "jne SIMDLOOP2\n\t"
                          "mov %%eax, %0"
                          : "=r" (nValue));

    printf("Result: %d\n",nValue);


    return 0;
}
