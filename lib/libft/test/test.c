/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 14:26:49 by aroque            #+#    #+#             */
/*   Updated: 2020/09/05 18:52:14 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <ctype.h>
#include "minunit.h"
#include "libft.h"
 
int tests_run = 0;
 
static char *test_ft_memset(void)
{
	char m1[10];
	char m2[10];
	//char m3[10];
	//char m4[10];
	ft_memset(m1, '.', 5);
	ft_memset(m2, '.', 5);
	mu_assert("Erro: ft_memset(5)", !strncmp(m1, m2, 10));
	//ft_memset(m3, '.', 0);
	//ft_memset(m4, '.', 0);
	//mu_assert("Erro: ft_memset(0)", !strncmp(m3, m4, 10));
	return (0);
}

static char *test_ft_bzero(void)
{
	int i;
	char s1[10];
	char s2[10];
 
	i = 10;
	ft_bzero(s1, i);
	bzero(s2, i);
	while (i--)
		mu_assert("Erro: ft_bzero(10)", s1[i] == s2[i]);
	return (0);
}

static char *test_ft_memcpy(void)
{
	const char s[80] = "ABCDEFGHIJ";
	char buffer1[80];
	char buffer2[80];
	char *s1;
	char *s2;

	s1 = ft_memcpy(buffer1, s, 10);
	s2 = memcpy(buffer2, s, 10);
	for (int i = 0; i < 10; i++)
		mu_assert("Erro: ft_memcpy", s1[i] == s2[i]);
	return (0);
}

static char *test_ft_memccpy(void)
{
	const char *src = "This is the string: not copied";
	char dst1[80];
	char dst2[80];
	char *r1;
	char *r2;
	
	ft_bzero(dst1, 80);
	ft_bzero(dst2, 80);
    r1 = ft_memccpy(dst1, src, '-', 80);
    r2 = memccpy(dst2, src, '-', 80);
	mu_assert("Erro: ft_memccpy", !strncmp(dst1, dst2, 80));
	ft_bzero(dst1, 80);
	ft_bzero(dst2, 80);
    r1 = ft_memccpy(dst1, src, ':', 80);
    r2 = memccpy(dst2, src, ':', 80);
	mu_assert("Erro: ft_memccpy", !strncmp(dst1, dst2, 80));
	ft_bzero(dst1, 80);
	ft_bzero(dst2, 80);
    r1 = ft_memccpy(dst1, src, ':', 10);
    r2 = memccpy(dst2, src, ':', 10);
	mu_assert("Erro: ft_memccpy", !strncmp(dst1, dst2, 80));
	return (0);
}

static char *test_ft_memmove(void)
{
	char s[100];
	strncpy(s + 20, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 22);
	char *s1;
	char *s2;

	s1 = memmove(s + 23, s, 10);
	s2 = ft_memmove(s + 23, s, 10);
	mu_assert("ERRO: ft_memmove", !strncmp(s1, s2, 100));
	s1 = memmove(s + 17, s, 10);
	s2 = ft_memmove(s + 17, s, 10);
	return (0);

}

static char *test_ft_memchr(void)
{
	const char *s = "This is the string: not copied";
	mu_assert("ERROR: ft_memchr(s, 'T', 100)", ft_memchr(s, 'T', 100) == memchr(s, 'T', 100));
	mu_assert("ERROR: ft_memchr(s, ':', 100)", ft_memchr(s, ':', 100) == memchr(s, ':', 100));
	mu_assert("ERROR: ft_memchr(s, '0', 100)", ft_memchr(s, '0', 100) == memchr(s, '0', 100));
	mu_assert("ERROR: ft_memchr(s, 'c', 100)", !strncmp(ft_memchr(s, 'c', 100), "copied", 100));
	mu_assert("ERROR: ft_memchr(s, ':', 0)", ft_memchr(s, ':', 0) == memchr(s, ':', 0));
	mu_assert("ERROR: ft_memchr(s, ':', 10)", ft_memchr(s, ':', 10) == memchr(s, ':', 10));
	return (0);
}

static char *test_ft_memcmp(void)
{
	char *s1 = "This is the string: compared";
	char *s2 = "This is the string: not compared";

	mu_assert("ERROR: ft_memcmp(1)", ft_memcmp(s1, s2, 1) == memcmp(s1, s2, 1));
	mu_assert("ERROR: ft_memcmp(5)", ft_memcmp(s1, s2, 5) == memcmp(s1, s2, 5));
	mu_assert("ERROR: ft_memcmp(10)", ft_memcmp(s1, s2, 10) == memcmp(s1, s2, 10));
	mu_assert("ERROR: ft_memcmp(21)", ft_memcmp(s1, s2, 21) == memcmp(s1, s2, 21));
	mu_assert("ERROR: ft_memcmp(51)", ft_memcmp(s1, s2, 51) == memcmp(s1, s2, 51));
	mu_assert("ERROR: ft_memcmp("")", ft_memcmp(s1, "", 51) == memcmp(s1, "", 51));
	mu_assert("ERROR: ft_memcmp("")", ft_memcmp(s1, "", 0) == memcmp(s1, "", 0));
	mu_assert("ERROR: ft_memcmp("")", ft_memcmp("", "", 0) == memcmp("", "", 0));
	return (0);
}

static char *test_ft_strchr(void)
{
	const char *s = "This is the string: not copied";
	mu_assert("ERROR: ft_strchr(s, 'T')", ft_strchr(s, 'T') == strchr(s, 'T'));
	mu_assert("ERROR: ft_strchr(s, ':')", ft_strchr(s, ':') == strchr(s, ':'));
	mu_assert("ERROR: ft_strchr(s, '0')", ft_strchr(s, '0') == strchr(s, '0'));
	mu_assert("ERROR: ft_strchr(s, 'c')", !strncmp(ft_strchr(s, 'c'), "copied", 100));
	mu_assert("ERROR: ft_strchr(s, ':')", ft_strchr(s, ':') == strchr(s, ':'));
	mu_assert("ERROR: ft_strchr(s, ':')", ft_strchr(s, ':') == strchr(s, ':'));
	return (0);
}

static char *test_ft_strrchr(void)
{
	const char *s = "This is the string: not copied";
	mu_assert("ERROR: ft_strrchr(s, 'T')", ft_strrchr(s, 'T') == strrchr(s, 'T'));
	mu_assert("ERROR: ft_strrchr(s, ':')", ft_strrchr(s, ':') == strrchr(s, ':'));
	mu_assert("ERROR: ft_strrchr(s, '0')", ft_strrchr(s, '0') == strrchr(s, '0'));
	mu_assert("ERROR: ft_strrchr(s, 'c')", !strncmp(ft_strrchr(s, 'c'), "copied", 100));
	mu_assert("ERROR: ft_strrchr(s, ':')", ft_strrchr(s, ':') == strrchr(s, ':'));
	mu_assert("ERROR: ft_strrchr(s, ':')", ft_strrchr(s, ':') == strrchr(s, ':'));
	return (0);
}

static char *test_ft_strncmp(void)
{
	//const char *s1 = "This is the string: not copied";
	//const char *s2 = "This is the string: copied";
	//const char *s3 = "This is the string: not copied anymore";
	//mu_assert("ERROR: ft_strncmp", ft_strncmp(s1, s2, 10) == strncmp(s1, s2, 10));
	//mu_assert("ERROR: ft_strncmp", ft_strncmp(s1, s2, 30) == strncmp(s1, s2, 30));
	//mu_assert("ERROR: ft_strncmp", ft_strncmp(s1, s2, 100) == strncmp(s1, s2, 100));
	//mu_assert("ERROR: ft_strncmp", ft_strncmp(s1, s2, 0) == strncmp(s1, s2, 0));
	//mu_assert("ERROR: ft_strncmp", ft_strncmp("", s2, 0) == strncmp("", s2, 0));
	//mu_assert("ERROR: ft_strncmp", ft_strncmp("", "", 0) == strncmp("", "", 0));
	//mu_assert("ERROR: ft_strncmp", ft_strncmp(s3, s1, strlen(s1)) == strncmp(s3, s1, strlen(s1)));
	//mu_assert("ERROR: ft_strncmp", ft_strncmp(s3, s1, strlen(s3)) == strncmp(s3, s1, strlen(s3)));
	return (0);
}

static char *test_ft_atoi(void)
{
	mu_assert("ERROR: ft_atoi(0)", ft_atoi("0") == atoi("0"));
	mu_assert("ERROR: ft_atoi(+1)", ft_atoi("+1") == 1);
	mu_assert("ERROR: ft_atoi(-1)", ft_atoi("-1") == -1);
	mu_assert("ERROR: ft_atoi(  42)", ft_atoi("\n\t 42") == 42);
	mu_assert("ERROR: ft_atoi(INT_MAX)", ft_atoi("2147483647") == INT_MAX);
	mu_assert("ERROR: ft_atoi(INT_MIN)", ft_atoi("-2147483648") == INT_MIN);
	mu_assert("ERROR: ft_atoi(LONG_MAX)", ft_atoi("99999999999999999999") == atoi("99999999999999999999"));
	mu_assert("ERROR: ft_atoi(LONG_MIN)", ft_atoi("-99999999999999999999") == atoi("-99999999999999999999"));
	return (0);
}

static char	*test_ft_isalpha(void)
{
	int i;

	i = -1;
	while (++i < 530)
		mu_assert("ERROR: ft_isalpha()", ft_isalpha(i) == isalpha(i));
	return (0);
}

static char	*test_ft_isdigit(void)
{
	int i;

	i = -1;
	while (++i < 530)
		mu_assert("ERROR: ft_isdigit()", ft_isdigit(i) == isdigit(i));
	return (0);	
}

static char	*test_ft_strdup(void)
{
	char *s = "String to copy";

	mu_assert("ERROR: ft_strdup", !strcmp(ft_strdup(s), strdup(s)));
	return (0);
}

static char *test_ft_substr(void)
{
	mu_assert("ERROR: ft_substr(Sao)", !strncmp(ft_substr("42SaoPaulo", 2, 3), "Sao", 9));
	printf("%s\n", ft_substr("42SaoPaulo", 99, 3));
	mu_assert("ERROR: ft_substr()", !strncmp(ft_substr("42SaoPaulo", 99, 3), "", 9));
	mu_assert("ERROR: ft_substr(42)", !strncmp(ft_substr("42SaoPaulo", 0, 2), "42", 9));
	mu_assert("ERROR: ft_substr(42)", !strncmp(ft_substr("42SaoPaulo", 0, 99), "42SaoPaulo", 11));
	return (0);
}

static char	*test_ft_strjoin(void)
{
	mu_assert("ERROR: ft_substr(Sao Paulo)", !strncmp(ft_strjoin("Sao ", "Paulo"), "Sao Paulo", 99));
	mu_assert("ERROR: ft_substr(Sao)", !strncmp(ft_strjoin("Sao", ""), "Sao", 4));
	mu_assert("ERROR: ft_substr(Paulo)", !strncmp(ft_strjoin("", "Paulo"), "Paulo", 5));
	mu_assert("ERROR: ft_substr()", !strncmp(ft_strjoin("", ""), "", 1));
	return (0);
}

static char *test_ft_strtrim(void)
{
	mu_assert("ERROR: ft_strtrim(spaces)", !strncmp(ft_strtrim("   spaces  ", " "), "spaces", 7));
	mu_assert("ERROR: ft_strtrim(spaces)", !strncmp(ft_strtrim("spaces", ""), "spaces", 7));
	mu_assert("ERROR: ft_strtrim(spaces)", !strncmp(ft_strtrim("   spaces", " "), "spaces", 7));
	mu_assert("ERROR: ft_strtrim(spaces)", !strncmp(ft_strtrim("   ", " "), "", 7));
	mu_assert("ERROR: ft_strtrim(spaces)", !strncmp(ft_strtrim(" ++--- spaces++\n  ", "\n +-"), "spaces", 7));
	return (0);
}
 
static char	*test_ft_split(void)
{
	char *src = "lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse";
	char *src2 = "  lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse  ";
	char **split = malloc(13 * sizeof(char *));
	split = ft_split(src, ' ');

	mu_assert("ERROR: ft_split[0]", !strcmp(split[0], "lorem"));
	mu_assert("ERROR: ft_split[1]", !strcmp(split[1], "ipsum"));
	mu_assert("ERROR: ft_split[11]", !strcmp(split[11], "Suspendisse"));
	mu_assert("ERROR: ft_split[12]", split[12] == 0);
	split = ft_split(src2, ' ');
	mu_assert("ERROR: ft_split[0]", !strcmp(split[0], "lorem"));
	mu_assert("ERROR: ft_split[1]", !strcmp(split[1], "ipsum"));
	mu_assert("ERROR: ft_split[11]", !strcmp(split[11], "Suspendisse"));
	mu_assert("ERROR: ft_split[12]", split[12] == 0);
	//for (int i = 0; i < 13; i++)
	//	free(split[i]);
	free(*split);
	return (0);
}

static char	*test_ft_itoa(void)
{
	mu_assert("ERROR: ft_itoa(0)", !strcmp(ft_itoa(0), "0"));
	mu_assert("ERROR: ft_itoa(42)", !strcmp(ft_itoa(42), "42"));
	mu_assert("ERROR: ft_itoa(42)", !strcmp(ft_itoa(-42), "-42"));
	mu_assert("ERROR: ft_itoa(INT_MAX)", !strcmp(ft_itoa(INT_MAX), "2147483647"));
	mu_assert("ERROR: ft_itoa(INT_MAX)", !strcmp(ft_itoa(INT_MIN), "-2147483648"));
	return (0);
}

static char	*test_ft_strmapi(void)
{
	return (0);
}

static char	*test_ft_lstnew(void)
{
	t_list *lst;

	lst = ft_lstnew("List Item");
	mu_assert("ERROR: ft_lstnew() content", !strcmp(lst->content, "List Item"));
	mu_assert("ERROR: ft_lstnew() next", lst->next == NULL);
	free(lst);
	return (0);
}

static char	*test_ft_lstadd_front(void)
{
	t_list *lst1 = ft_lstnew("Previous First");
	t_list *lst2 = ft_lstnew("Second First");
	ft_lstadd_front(&lst1, lst2);
	mu_assert("ERROR: ft_lstadd_front()", lst1->content == lst2->content);
	return (0);
}

static char	*test_ft_lstsize(void)
{
	t_list *lst1 = ft_lstnew("First");
	t_list *lst2 = ft_lstnew("Second");
	t_list *lst3 = ft_lstnew("Third");
	mu_assert("ERROR: ft_lstsize single", ft_lstsize(lst1) == 1);
	ft_lstadd_front(&lst1, lst2);
	ft_lstadd_front(&lst1, lst3);
	mu_assert("ERROR: ft_lstsize", ft_lstsize(lst1) == 3);
	return (0);
}

static char	*test_ft_lstadd_back(void)
{
	t_list *lst1 = ft_lstnew("First");
	t_list *lst2 = ft_lstnew("Second");
	ft_lstadd_back(&lst1, lst2);
	mu_assert("ERROR: ft_lstadd_back()", lst1->next == lst2);
	mu_assert("ERROR: ft_lstadd_back()", !strcmp(lst1->content, "First"));
	mu_assert("ERROR: ft_lstadd_back()", !strcmp(lst1->next->content, "Second"));
	return (0);
}

void	del(void *content)
{
	(void)content;
}

static char *test_ft_lstlast(void)
{
	t_list *lst1 = ((void *)0);
	t_list *lst2;
	t_list *lst3;

	mu_assert("Error: ft_lstlast()", lst1 == ft_lstlast(lst1));
	lst2 = ((void *)0);
	lst3 = ft_lstlast(lst1);
	mu_assert("Error: ft_lstlast()", lst2 == lst3);
	return (0);
}

static char	*test_ft_lstdelone(void)
{
	t_list *lst1 = ft_lstnew("First");
	t_list *lst2 = ft_lstnew("Second");
	t_list *lst3 = ft_lstnew("Third");
	ft_lstadd_back(&lst1, lst2);
	ft_lstadd_back(&lst1, lst3);
	ft_lstdelone(lst1, del);
	//mu_assert("ERROR: ft_lstdelone", !lst1->content);
	return (0);
}

static char	*test_ft_lstclear(void)
{
	t_list *lst1 = ft_lstnew("First");
	t_list *lst2 = ft_lstnew("Second");
	t_list *lst3 = ft_lstnew("Third");
	ft_lstadd_back(&lst1, lst2);
	ft_lstadd_back(&lst1, lst3);
	mu_assert("ERROR: ft_lstclear", lst1);
	mu_assert("ERROR: ft_lstclear", lst1->next);
	ft_lstclear(&lst1, del);
	mu_assert("ERROR: ft_lstclear", !lst1);
	return (0);
}

static void	*increment(void *c)
{
	return (c);
}

static char	*test_ft_lstmap(void)
{
	t_list *lst1 = ft_lstnew("1");
	ft_lstadd_back(&lst1, ft_lstnew("2"));
	ft_lstadd_back(&lst1, ft_lstnew("3"));
	//ft_lstiter(lst1, ft_putstr);
	ft_lstmap(lst1, increment, del);
	//ft_lstiter(lst1, ft_putstr);
	return (0);
}


static char *test_ft_atof(void)
{
	mu_assert("ERROR: ft_atof(0)", ft_atof("12.25") == atof("12.25"));
	//mu_assert("ERROR: ft_atof(+1)", ft_atoi("+1") == 1);
	//mu_assert("ERROR: ft_atof(-1)", ft_atoi("-1") == -1);
	//mu_assert("ERROR: ft_atof(  42)", ft_atoi("\n\t 42") == 42);
	//mu_assert("ERROR: ft_atof(INT_MAX)", ft_atoi("2147483647") == INT_MAX);
	//mu_assert("ERROR: ft_atof(INT_MIN)", ft_atoi("-2147483648") == INT_MIN);
	//mu_assert("ERROR: ft_atof(LONG_MAX)", ft_atoi("99999999999999999999") == atoi("99999999999999999999"));
	//mu_assert("ERROR: ft_atof(LONG_MIN)", ft_atoi("-99999999999999999999") == atoi("-99999999999999999999"));
	return (0);
}


static char *test_suite()
{
	mu_run_test(test_ft_memset);
    mu_run_test(test_ft_bzero);
	mu_run_test(test_ft_memcpy);
	mu_run_test(test_ft_memccpy);
	mu_run_test(test_ft_memmove);
	mu_run_test(test_ft_memchr);
	mu_run_test(test_ft_memcmp);
	mu_run_test(test_ft_strchr);
	mu_run_test(test_ft_strrchr);
	mu_run_test(test_ft_strncmp);
	mu_run_test(test_ft_atoi);
	mu_run_test(test_ft_isalpha);
	mu_run_test(test_ft_isdigit);
	mu_run_test(test_ft_strdup);
	mu_run_test(test_ft_substr);
	mu_run_test(test_ft_strjoin);
	mu_run_test(test_ft_strtrim);
	mu_run_test(test_ft_split);
	mu_run_test(test_ft_itoa);
	mu_run_test(test_ft_strmapi);
	mu_run_test(test_ft_lstnew);
	mu_run_test(test_ft_lstadd_front);
	mu_run_test(test_ft_lstsize);
	mu_run_test(test_ft_lstadd_back);
	mu_run_test(test_ft_lstlast);
	mu_run_test(test_ft_lstdelone);
	mu_run_test(test_ft_lstclear);
	mu_run_test(test_ft_lstmap);
	return (0);
}
 
int main(void) {

     char *result;
	 
	 result = test_suite();
	 printf("-----------------------------------\n");
     if (result) 
	 {
		 printf("Erro detectado!\n");
         printf("%s\n", result);
	 }	
     else
         printf("Nenhum teste com falha.\n");
     printf("Testes executados: %d\n", tests_run);
	 printf("-----------------------------------\n");
     return (0);
}
