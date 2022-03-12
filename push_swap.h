#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "./libft/libft.h"
# include <limits.h>

typedef struct s_list
{
	int			content;
	int 		index;
	struct s_list	*next;
}			t_list;

int 	main(int argc, char **argv);

/* Utils */
int 		ft_print_error();
int 		*ft_create_tab(int ac, char **av);
long   		ft_atol(char *str);
int     	ft_len_malloc_tab(int ac, char **av);
int	    	ft_count_words(char const *s, char c);
void		ft_no_leaks(int ac, char **input);
int			ft_check_all(int tmp, char **input, int pars_args);

/* Lists */
void		ft_free(char **str);
void		ft_free_stack(t_list *stack);
void    	ft_get_index(t_list *a, int ac, char **av);
void 		ft_create_list(int ac, char **argv, t_list **stack_a);
int			ft_lstsize(t_list *lst);
void		ft_lstadd_back(t_list **alst, t_list *new);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstnew(int content);

/* Parsing */
int     	ft_check_errors(int argc, char **argv);

/* Instructions */
int     	sa(t_list **stack_a);
int     	sb(t_list **b);
int     	pb(t_list **a, t_list **b);
int 		ra(t_list **a);
int     	pa(t_list **a, t_list **b);
int 		rb(t_list **b);
int			rrb(t_list **b);
int			rra(t_list **a);
int			rrr(t_list **a, t_list **b);

/* Sorting algos */
int			ft_is_sorted(t_list **stack);
void    	ft_sort_small(t_list **a,t_list **b, int ac, char **av);
void		radix_sort(t_list **stack_a, t_list **stack_b);
void   		ft_find_case(t_list **a, int *tab);
int 		ft_get_min(t_list **a);
int  		ft_get_pos(t_list **a);
int    		ft_case_1(int *tab);
int    		ft_case_2(int *tab);
int    		ft_case_3(int *tab);
int    		ft_case_4(int *tab);
int    		ft_case_5(int *tab);
#endif
