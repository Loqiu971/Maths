![Maths Logo](https://github.com/Loqiu971/Maths/blob/main/icone2.jpg "Maths logo")

# Maths [PROG: C]

## Description

Sujet:

```bash
char *my_getnbr_base(int n, char *base);
char *my_addnbr_base(char *n1, char *n2, char *base);
```

Le principe de ces fonctions est d’effectuer de l’arithmétique avec des nombres encodés dans
des bases arbitraires. Les nombres sont de simple chaíne de caractère.

## Code  :
```bash
#include <stdio.h>
void main()
{
char *base = "ABCDEFGHIJ"; // A=0, B=1, ...K=9
char *n1 = my_getnbr_base(12, base);
printf("%s == BC\n", n1);
char *n2 = my_getnbr_base(24, base);
printf("%s == CE\n", n2);
char *n3 = my_addnbr_base(n1, n2, base);
printf("%s == DG\n", n3):
free(n1);
free(n2);
free(n3);
}
```

Il vous est demandé de fournir un main.c testant vos fonctions.