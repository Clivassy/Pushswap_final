#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//#include "libft.h"
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>
# include <stdlib.h>
# include <stdint.h>

typedef struct s_list
{
	int			content;
	int 		index;
	struct s_list	*next;
}			t_list;

int 	main(int argc, char **argv);

/* Utils */
int 		*ft_create_tab_from_av(int ac, char **av);
int 		*ft_create_tab_from_str(int ac, char **input);
int 		ft_print_error();
int			ft_tab_len(int ac, char *av);
long   		ft_atol(char *str);
int			ft_atoi(const char *nptr);
int     	ft_len_malloc_tab(int ac, char **av);
int	    	ft_count_words(char const *s, char c);
void	ft_free_tab(char **str);

/* Lists */
void	ft_free_stack(t_list *stack);
void	  	ft_get_index(t_list *a, int ac, char **av);
void    	printList(t_list *head);
t_list 		*ft_create_list(int ac, char **argv, t_list **stack_a);
int    		ft_search_element(t_list *head, int index);
void    	ft_delete_first_node(t_list **stack);
void    	ft_delete_last_node(t_list **head_ref);
void    	ft_push_at_start(t_list **stack, int val);


/* Parsing */
int     	ft_check_errors(int argc, char **argv);
int     	ft_check_int_overflow(char *arg);
int     	ft_check_double(int ac, char **av);
int    		ft_check_argv_input(char *nptr);

/* Instructions */
int     	ft_swap_nodes(t_list **stack);
int			ft_push(t_list **stack_to, t_list **stack_from);
int			ft_reverseRotate(t_list **stack);
int			ft_rotate(t_list **stack);
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
void   		ft_find_case(t_list **a, int *tab);
int  		ft_get_pos(t_list **a);
int     	ft_get_max_bits(t_list *stack);
int     	ft_min_position(t_list **stack, int *tab);
int			ft_is_sorted(t_list **stack);
void    	ft_sort_small_stack(t_list **a,t_list **b, int ac, char **av);
void    	ft_sort_two_nb(t_list **stack, int *tab);
void    	ft_sort_three(t_list **a);
void    	ft_sort_four(t_list **a, t_list **b, int pos);
void       	ft_sort_five(t_list **a, t_list **b, int pos);
t_list    	*ft_sort_4(t_list **a, int *tab);
void		radix_sort(t_list **stack_a, t_list **stack_b);
int 		ft_get_min(t_list **a);

//LIBFT (temp)
int	    	ft_isdigit(int c);
int			ft_lstsize(t_list *lst);
void		ft_lstadd_back(t_list **alst, t_list *new);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstnew(int content);
char		**ft_split(char *s, char c);
#endif