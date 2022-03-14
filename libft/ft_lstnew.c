#include "libft.h"

t_list  *ft_lstnew(void *content)
{
    t_list *lst;

    lst = (t_list *)malloc(sizeof(t_list));
    if (lst == 0)
        return (0);
    if (lst->content == 0)
        return (0);
    lst->content = content;
    lst->next = 0;
    return (lst);
}
