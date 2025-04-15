/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sconef.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouaffa <mmouaffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:43:33 by mmouaffa          #+#    #+#             */
/*   Updated: 2025/04/15 12:53:49 by mmouaffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>

int ft_scanf(const char *format, ...)
{
    va_list(args);
    va_start(args, format);
    int count = 0;
    const char    *ptr = format;
    char    c;

    while (*ptr)
    {
        if (*ptr == '%')
        {
            *ptr++;
            if (*ptr == 'd'){
                int *num = va_arg(args, int *);
                int sign = 1; int temp = 0;

                while (isspace(c = fgetc(stdin)));
                if (c == '-')
                {
                    sign = -1;
                    c = fgetc(stdin);
                }
                while (isdigit(c))
                {
                    temp = temp * 10 + (c - '0');
                    c = fgetc(stdin);
                    
                }
                *num = temp * sign;
                ungetc(c, stdin);
                count++;
                
            }
            else if (*ptr == 's' || *ptr == 'c'){
                char    *str = va_arg(args, char *);
                int i = 0;

                while (isspace(c = fgetc(stdin)));

                while (c != EOF && !isspace(c))
                {
                    str[i++] = c;
                    c = fgetc(stdin);
                }
                
                ungetc(c, stdin);
                str[i] = '\0';
                count++;
            }
            else if (isspace(*ptr)){}
            else {
                c = fgetc(stdin);
                if (c != *ptr){
                    ungetc(c, stdin);
                    break;
                }
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