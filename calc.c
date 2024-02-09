#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* my_getnbr_base(int n, char *base) {
    int base_size = strlen(base);
    char *result = (char *)malloc(sizeof(char) * 2);  // Au moins 2 caractères pour stocker le nombre et '\0'
    int index = 0;

    while (n > 0) {
        int remainder = n % base_size;
        result[index++] = base[remainder];
        n /= base_size;
    }

    result[index] = '\0';
    
    int d = 0, fin = index - 1;
    while(d < fin) {
	char temp = result[d];
	result[d] = result[fin];
	result[fin] = temp;
	d++;
	fin--;
    }

    return result;
}

char* my_addnbr_base(char *n, char *n2, char *base) {

    int nb = 0, nb2 = 0, nb3 = 0, nb4 = 0, nt = 0;	
    size_t l = strlen(base);
    for(int i=0; i < l; ++i) {
	if(base[i] == n[0]) {
            nb = i;
	    //printf("\n%c\n%c\n%d\n",base[i], n[0],nb);
    	}
	if(base[i] == n[1]) {
	    nb2 = i;
	    //printf("\n%c\n%c\n%d\n",base[i],n[1],nb2);
	}
	if(base[i] == n2[0]) {
	    nb3 = i;
	    //printf("\n%c\n%c\n%d\n", base[i],n2[0],nb3);
	}
	if(base[i] == n2[1]) {
	    nb4 = i;
	    //printf("\n%c\n%c\n%d\n", base[i],n2[1],nb4);
	}
    }
    int result1 = nb * 10 + nb2;
    int result2 = nb3 * 10 + nb4;

    int resultat = result1 + result2; 
    //printf("RESULTAT: %d = %d + %d |\nnb=%d\nnb2=%d\nnb3=%d\nnb4=%d\n",resultat, result1,result2,nb, nb2,nb3,nb4); 
    return my_getnbr_base(resultat, base);
}

int main() {
    char *base = "ABCDEFGHIJ";  // A=0, B=1, ...K=9

    char *n1 = my_getnbr_base(12, base);
    printf("%s == BC\n", n1);

    char *n2 = my_getnbr_base(24, base);
    printf("%s == CE\n", n2);

    char *n3 = my_addnbr_base(n1, n2, base);
    printf("%s == DG\n", n3);

    free(n1);
    free(n2);
    free(n3);

    return 0;
}
