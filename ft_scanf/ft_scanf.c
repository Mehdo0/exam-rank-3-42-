/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouaffa <mmouaffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:32:29 by mmouaffa          #+#    #+#             */
/*   Updated: 2025/04/15 12:35:17 by mmouaffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>

int ft_scanf(const char *format, ...);


int ft_scanf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int count = 0;
        const char *ptr = format;
    char c;

    while (*ptr) {
        if (*ptr == '%') {
            ptr++; // Passer le '%'

            if (*ptr == 'd') { // Lire un entier
                int *num = va_arg(args, int *);
                int temp = 0, sign = 1;

                // Ignorer les espaces
                while (isspace(c = fgetc(stdin)));

                // Gérer le signe négatif
                if (c == '-') {
                    sign = -1;
                    c = fgetc(stdin);
                }

                // Lire les chiffres
                while (isdigit(c)) {
                    temp = temp * 10 + (c - '0');
                    c = fgetc(stdin);
                }

                *num = temp * sign; // Stocker la valeur
                ungetc(c, stdin);   // Remettre le dernier caractère non numérique
                count++;
            }

            else if (*ptr == 's') { // Lire une chaîne
                char *str = va_arg(args, char *);
                int i = 0;

                // Ignorer les espaces
                while (isspace(c = fgetc(stdin)));

                // Lire la chaîne jusqu'à un espace ou EOF
                while (c != EOF && !isspace(c)) {
                    str[i++] = c;
                    c = fgetc(stdin);
                }

                str[i] = '\0'; // Terminer la chaîne
                ungetc(c, stdin);
                count++;
            }
            else if (*ptr == 'c') { // Lire une chaîne
                char *str = va_arg(args, char *);
                int i = 0;

                // Ignorer les espaces
                while (isspace(c = fgetc(stdin)));

                // Lire la chaîne jusqu'à un espace ou EOF
                while (c != EOF && !isspace(c)) {
                    str[i++] = c;
                    c = fgetc(stdin);
                }

                str[i] = '\0'; // Terminer la chaîne
                ungetc(c, stdin);
                count++;
            }
        }
        else if (isspace(*ptr)) {
            // Ignorer les espaces dans format
        }
        else {
            // Vérifier si le caractère correspond dans stdin
            c = fgetc(stdin);
            if (c != *ptr) {
                ungetc(c, stdin);
                break;
            }
        }
        ptr++;
    }

    va_end(args);
    return (count);
}


int main()
{
    int num;
    char str[100];

    printf("Entrez un nombre et un mot : ");
    ft_scanf("%d %s", &num, str);

    printf("Nombre : %d\n", num);
    printf("Mot : %s\n", str);

    return 0;
}
