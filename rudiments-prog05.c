#include <stdio.h>
#include <stdbool.h>

int main()
{
        int zero,one;
        zero = 0b0;
        one = 0b1;
        bool retry;
        printf("\n\tOPERATEURS\n\n");
        printf("%d &  %d = %d  \n", zero, zero, zero &  zero);
        printf("%d &  %d = %d  \n", zero, one,  zero &  one);
        printf("%d &  %d = %d  \n", one,  zero, one  &  zero);
        printf("%d &  %d = %d\n\n", one,  one,  one  &  one);
        printf("%d && %d = %d  \n", zero, zero, zero && zero);
        printf("%d && %d = %d  \n", zero, one,  zero && one);
        printf("%d && %d = %d  \n", one,  zero, one  && zero);
        printf("%d && %d = %d\n\n", one,  one,  one  && one);
        printf("%d |  %d = %d  \n", zero, zero, zero |  zero);
        printf("%d |  %d = %d  \n", zero, one,  zero |  one);
        printf("%d |  %d = %d  \n", one,  zero, one  |  zero);
        printf("%d |  %d = %d\n\n", one,  one,  one  |  one);
        printf("%d || %d = %d  \n", zero, zero, zero || zero);
        printf("%d || %d = %d  \n", zero, one,  zero || one);
        printf("%d || %d = %d  \n", one,  zero, one  || zero);
        printf("%d || %d = %d\n\n", one,  one,  one  || one);
        printf("%d ~    = %d   \n", zero,            ~  zero);
        printf("%d ~    = %d \n\n", one,             ~  one);
        printf("%d ^  %d = %d  \n", zero, zero, zero ^  zero);
        printf("%d ^  %d = %d  \n", zero, one,  zero ^  one);
        printf("%d ^  %d = %d  \n", one,  zero, one  ^  zero);
        printf("%d ^  %d = %d\n\n", one,  one,  one  ^  one);
        printf("%d !    = %d   \n", zero,            !  zero);
        printf("%d !    = %d   \n", one,             !  one);
        do
        {
                printf("\nChoisissez deux nombres pour recommencer les opérations:\n - ");
                scanf("%d", &zero);
                printf(" - ");
                scanf("%d", &one);
                printf("\n%d &  %d = %d  \n", zero, zero, zero &  zero);
                printf("%d &  %d = %d  \n", zero, one,  zero &  one);
                printf("%d &  %d = %d  \n", one,  zero, one  &  zero);
                printf("%d &  %d = %d\n\n", one,  one,  one  &  one);
                printf("%d && %d = %d  \n", zero, zero, zero && zero);
                printf("%d && %d = %d  \n", zero, one,  zero && one);
                printf("%d && %d = %d  \n", one,  zero, one  && zero);
                printf("%d && %d = %d\n\n", one,  one,  one  && one);
                printf("%d |  %d = %d  \n", zero, zero, zero |  zero);
                printf("%d |  %d = %d  \n", zero, one,  zero |  one);
                printf("%d |  %d = %d  \n", one,  zero, one  |  zero);
                printf("%d |  %d = %d\n\n", one,  one,  one  |  one);
                printf("%d || %d = %d  \n", zero, zero, zero || zero);
                printf("%d || %d = %d  \n", zero, one,  zero || one);
                printf("%d || %d = %d  \n", one,  zero, one  || zero);
                printf("%d || %d = %d\n\n", one,  one,  one  || one);
                printf("%d ~    = %d   \n", zero,            ~  zero);
                printf("%d ~    = %d \n\n", one,             ~  one);
                printf("%d ^  %d = %d  \n", zero, zero, zero ^  zero);
                printf("%d ^  %d = %d  \n", zero, one,  zero ^  one);
                printf("%d ^  %d = %d  \n", one,  zero, one  ^  zero);
                printf("%d ^  %d = %d\n\n", one,  one,  one  ^  one);
                printf("%d !    = %d   \n", zero,            !  zero);
                printf("%d !    = %d   \n", one,             !  one);
                printf("\nVoulez-vous recommencer ? (1/0)\n");
                scanf("%d", &retry);
        }
        while (retry);
        return 0;
}

