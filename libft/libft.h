/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semebrah <semebrah@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:43:06 by semebrah          #+#    #+#             */
/*   Updated: 2025/11/27 16:31:10 by semebrah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "stdarg.h"
# include <ctype.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/select.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

# define DEC "0123456789"
# define HEX "0123456789abcdef"
# define HEXCAPS "0123456789ABCDEF"

typedef struct s_template
{
	size_t			start;
	size_t			end;

	size_t			len;

	int				left;
	int				sign;
	int				space;
	int				alt;
	int				zero;
	int				width;
	int				precision;
	char			specifier;
}					t_template;

int					ft_islower(int c);
int					ft_isupper(int c);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isspace(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
size_t				ft_strlen(const char *s);
void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
int					ft_atoi(const char *nptr);
void				*ft_calloc(size_t nmemb, size_t size);
char				*ft_strdup(const char *s);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new_node);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new_node);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

// get_next_line_bonus.c
char				*get_next_line(int fd);

// ft_printf.c
int					ft_printf(const char *f, ...);

// parser.c
void				ft_reset_template(t_template *tpl);
int					ft_next_template(const char *str, size_t start,
						t_template *tpl);

// converter.c
char				*convert(unsigned long long n, char *base_to);

// utils.c
int					ft_is_member(char c, char *chars);
ssize_t				ft_index(const char *s, size_t start, char *chars);
char				*strgen(char c, size_t size);
char				*append(char *s1, char *s2, ssize_t s1size, ssize_t s2size);

// printers1.c
void				print_c(int c, t_template *tpl);
void				print_s(char *str, t_template *tpl);
void				print_p(unsigned long long val, t_template *tpl);
void				print_d(long long val, t_template *tpl);
void				print_u(unsigned int val, t_template *tpl);

// printers2.c
void				print_x(unsigned int val, t_template *tpl);
void				print(char *str, t_template *tpl, size_t size);

// handlers1.c
char				*handle_precision(t_template *tpl, char *str, int zero);
char				*handle_width(t_template *tpl, int size, char c,
						int negative);
char				*handle_left(t_template *tpl, char *str, char *str_gen,
						size_t str_size);
char				*handle_alt(t_template *tpl, char *str);
char				*handle_sign(t_template *tpl, char *str, int negative);

// handlers2.c
char				*handle_space(t_template *tpl, char *str, int negative);
char				handle_zero(t_template *tpl);

#endif
