#include "push_swap.h"

// LIBFT USE
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

t_list	*ft_lstnew(int content)
{
	t_list	*element;

	element = malloc(sizeof(*element));
	if (!element)
		return (NULL);
	element->content = content;
	element->next = NULL;
	return (element);
}

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*temp;

	if (alst)
	{
		if (!*alst)
			*alst = new;
		else
		{
			temp = (*alst);
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = new;
		}
	}
}

int	ft_lstsize(t_list *lst)
{
	int		nb_element;

	nb_element = 0;
	if (lst)
	{
		while (lst)
		{
			lst = lst->next;
			nb_element++;
		}
	}
	return (nb_element);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
	}
	return (lst);
}

static char	**ft_free(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

int	ft_count_words(char const *s, char c)
{
	size_t		i;
	int			count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char	*ft_malloc_word(const char *str, int start, int end)
{
	char	*malloc_w;
	int		i;
	int		len;

	i = 0;
	len = (end - start) + 1;
	malloc_w = (char *)malloc(sizeof(char) * len);
	if (!malloc_w)
		return (0);
	while (start < end)
	{
		malloc_w[i] = str[start];
		i++;
		start++;
	}
	malloc_w[i] = '\0';
	return (malloc_w);
}

static char	**ft_malloc_array(char const *s, char **array, char c)
{
	size_t	i;
	size_t	j;
	int		index;

	i = 0;
	j = 0;
	index = -1;
	while (i <= strlen(s))
	{
		if ((s[i] != c) && index < 0)
			index = i;
		else if ((s[i] == c || i == strlen(s)) && index >= 0)
		{
			array[j] = ft_malloc_word(s, index, i);
			if (!array[j])
				return (ft_free(array));
			index = -1;
			j++;
		}
		i++;
	}
	array[j] = 0;
	return (array);
}

char	**ft_split(char *s, char c)
{
	char	**array;

	if (!s)
		return (NULL);
	array = malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	ft_malloc_array(s, array, c);
	return (array);
}

void    printList(t_list *head)
{ 
	t_list *current = head;
    
	while (current != NULL)
    {
        printf("%d\n", current->content);
        current = current->next;
    }
}