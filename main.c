/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maanton2 <maanton2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 23:33:56 by maanton2          #+#    #+#             */
/*   Updated: 2024/11/14 07:12:33 by maanton2         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
/*
printf("%s\n", fmt);
printf("%d\n", precision);
printf("%d\n", field_width);
printf("r: %s\n", raw_str);
printf("p: %d\n", precision);
printf("f: %d\n", field_width);
printf("%s\n", flag);
*/
int main(int argc, char **argv)
{
	int	expected;
	int	result;

	expected = -1;
	result = -1;
	if (argc >= 2)
		ft_printf(argv[1]);

	result = ft_printf("FT: %6.4d \n", 42);
	expected = printf("OG: %6.4d \n", -42);
	printf("result: %d -  expected: %d",result, expected);
// Teste básico de strings e caracteres// 
/*
    ft_printf("Testando uma string: %s\n", "Hello, World!");
    ft_printf("Caractere único: %c\n", 'A');

    // Testes com números inteiros com flags e largura mínima
    ft_printf("Número com largura mínima 10: %10d\n", 42);
    ft_printf("Número com largura mínima 5 e flag 0 (preenchido com zeros): %05d\n", 42);
    ft_printf("Número com largura mínima 5 e flag - (alinhado à esquerda): %-5d\n", 42);

    // Testes com floats usando precisão
    ft_printf("Float com precisão de 2 casas decimais: %.2f\n", 3.14159);
    ft_printf("Float com precisão de 4 casas decimais: %.4f\n", 3.14159);

    // Flags adicionais: espaço, +, #
    ft_printf("Número positivo com flag +: %+d\n", 42);
    ft_printf("Número positivo com flag de espaço: % d\n", 42);
    ft_printf("Número negativo com flag +: %+d\n", -42);
    ft_printf("Hexadecimal com flag #: %#x\n", 255);
    ft_printf("Octal com flag #: %#o\n", 255);

    // Testes com combinações de flags
    ft_printf("Flag + e largura mínima 10: %+10d\n", 42);
    ft_printf("Flag +, largura mínima 10 e flag 0: %+010d\n", 42);
    ft_printf("Flag # para hexadecimal: %#x\n", 255);

    // Teste com strings e largura mínima
    ft_printf("String com largura mínima 20: %20s\n", "Texto alinhado à direita");
    ft_printf("String com largura mínima -20 (alinhada à esquerda): %-20s\n", "Texto alinhado à esquerda");

    // Casos de largura mínima e precisão em conjunto
    ft_printf("Float com largura mínima 10 e precisão 2: %10.2f\n", 3.14159);
    ft_printf("Inteiro com largura mínima 5 e precisão 2: %5.2d\n", 42);

    // Exemplo com flag 0 e precisão (0 não deve ser aplicado quando a precisão está definida)
    ft_printf("Flag 0 com precisão definida (ignora 0): %010.2d\n", 42);
*/
	return 0;
}
