/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 08:35:25 by plamusse          #+#    #+#             */
/*   Updated: 2018/04/25 19:25:31 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFT_H

# define FT_LIBFT_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "ft_printf.h"

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

typedef struct		s_vec
{
	double			x;
	double			y;
	double			z;
}					t_vec;

size_t				ft_strlen(const char *s);

int					ft_tablen(const char **tab);

char				*ft_strdup(const char *s1);

char				*ft_strcpy(char *dst, const char *src);

char				*ft_strncpy(char *dst, const char *src, size_t len);

char				*ft_strcat(char *s1, const char *s2);

char				*ft_strncat(char *restrict s1, const char *restrict s2,
						size_t n);

char				*ft_strstr(const char *big, const char *little);

int					ft_strcmp(const char *s1, const char *s2);

int					ft_strncmp(const char *s1, const char *s2, size_t n);

size_t				ft_strlcat(char *dst, const char *src, size_t size);

int					ft_atoi(const char *str);

double				ft_atof(char *str);

int					ft_isalpha(int c);

int					ft_isalnum(int c);

int					ft_isdigit(int c);

int					ft_ishexa(int c);

int					ft_isascii(int c);

int					ft_isprint(int c);

int					ft_isspace(int c);

void				*ft_memset(void *b, int c, size_t len);

void				ft_bzero(void *s, size_t n);

void				*ft_memcpy(void *dst, const void *src, size_t n);

void				*ft_memccpy(void *dst, const void *src, int c,
						size_t n);

void				*ft_memmove(void *dst, const void *src, size_t len);

void				*ft_memchr(const void *s, int c, size_t n);

int					ft_memcmp(const void *s1, const void *s2, size_t n);

char				*ft_strchr(const char *s, int c);

char				*ft_strrchr(const char *s, int c);

char				*ft_strnstr(const char *big, const char *little,
						size_t len);

int					ft_toupper(int c);

int					ft_tolower(int c);

void				*ft_memalloc(size_t size);

void				ft_memdel(void **ap);

char				*ft_strnew(size_t size);

void				ft_strdel(char **as);

void				ft_strclr(char *s);

void				ft_tabclr(char **tab);

void				ft_striter(char *s, void (*f)(char *));

void				ft_striteri(char *s, void (*f)(unsigned int, char *));

char				*ft_strmap(char const *s, char (*f)(char));

char				*ft_strmapi(char const *s, char (*f)(unsigned int,
						char));

int					ft_strequ(char const *s1, char const *s2);

int					ft_strnequ(char const *s1, char const *s2, size_t n);

char				*ft_strsub(char const *s, unsigned int start,
						size_t len);

char				*ft_strjoin(char const *s1, char const *s2);

char				*ft_strtrim(char const *s);

char				**ft_strsplit(char const *s, char c);

char				*ft_itoa(int n);

int					ft_abs(int n);

double				ft_fabs(double n);

ssize_t				ft_intlen(ssize_t n);

char				*ft_strrev(const char *s);

void				ft_perror(char *str);

int					ft_printf(const char *format, ...);

void				ft_putchar(char c);

void				ft_putstr(char const *s);

void				ft_putendl(char const *s);

void				ft_putnbr(int n);

void				ft_putchar_fd(char c, int fd);

void				ft_putstr_fd(const char *s, int fd);

void				ft_putendl_fd(char const *s, int fd);

void				ft_putnbr_fd(int n, int fd);

/*
**	List
*/

int					ft_lstlen(t_list *lst);
t_list				*ft_lstnew(void const *content,
						size_t content_size);
void				ft_lstdelone(t_list **alst,
						void (*del)(void *, size_t));
void				ft_lst_del(t_list **alst,
						void (*del)(void *, size_t));
void				ft_lst_memclr(void *content, size_t content_size);
t_list				*ft_lst_push_front(t_list **alst, t_list *new);
t_list				*ft_lst_push_back(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst,
						void (*f)(t_list *elem));

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
**	Listes doublement circulaires
*/

void				ft_lst2c_del(t_list **alst,
						void (*del)(void *, size_t));
int					ft_lst2c_len(t_list *lst);
t_list				*ft_lst2c_push_back(t_list **alst, t_list *new);

/*
**	Vector
*/

t_vec				ft_vec3Sub(t_vec v1, t_vec v2);
double				ft_vec3Dot(t_vec v1, t_vec v2);
t_vec				ft_vec3Normalize(t_vec v);
t_vec				ft_vec3Scale(t_vec v, double scale);
t_vec				ft_vec3Add(t_vec v1, t_vec v2);

#endif
