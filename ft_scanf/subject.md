ft-scanf.c
functions: fgetc, ungetc, ferror, feof, isspace, isdigit, stdin, va_start, va_arg, va_copy, va_end.

Écrire une fonction nommée "ft_scanf" qui imitera le vrai scanf avec les contraintes suivantes :

Il gérera les conversions %s et %d.

Ne pas gérer les options * m et n.

Ne pas gérer la largeur maximale du champ.

Ne pas gérer les modificateurs de type (h, hh, l, ...).

Ne pas gérer les conversions commençant par %n$.

Déclaration :

int ft_scanf(const char * , ...);  

void va_start(va_list last)  
type va_arg(va_list ap, type)  
void va_end(va_list ap)  
void va_copy(va_list dest, va_list src)