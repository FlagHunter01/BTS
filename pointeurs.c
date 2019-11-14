#include <stdio.h>
#include <stdlib.h>

int i, j, k;
int* p_entier;

char alpha;
char* p_char = &alpha;

float F1;
float* p_float = &F1;

int main()
{
        i = 20;
        p_entier = &i;
        printf("@ de i = %d\ni = %d\np_entier = %d\n", &i, i, p_entier);
        i = i + 10;
        printf("@ de i = %d\ni = %d\np_entier = %d\n", &i, i, p_entier);
        printf("@ de i = %d\n@ de j = %d\n@ de k = %d\n", &i, &j, &k);
        p_entier = p_entier + 1;
        printf("@ de p_entier = %d\n", p_entier);
        p_entier = p_entier + 1;
        printf("@ de p_entier = %d\n", p_entier);
        printf("@ de p_char = %d\n", p_char);
        p_char = p_char + 1;
        printf("@ de p_char = %d\n", p_char);
        printf("@ de p_float = %d\n", p_float);
        p_float = p_float + 1;
        printf("@ de p_float = %d\n", p_float);
        p_float = p_float + 5;
        printf("@ de p_float = %d\n", p_float);
        printf("Taille entier = %d\nTaille char = %d\nTaille float = %d\n", sizeof (i), sizeof (alpha), sizeof(F1));
        return 0;
}
