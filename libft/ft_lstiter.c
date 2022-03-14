#include "libft.h"

void ft_lstiter(t_list *lst, void (*f)(void *))
{
    t_list  *temp;

    temp = lst;
    while (temp != 0)
    {
        f(temp->content);
        temp = temp->next;
    }
}
