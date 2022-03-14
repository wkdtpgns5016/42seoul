#include "libft.h"

void    ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list *temp;

    temp = *lst;
    if (temp == 0)
        *lst = new;
    else 
    {
        temp = *lst;
        while (temp->next != 0)
            temp = temp->next;
        temp->next = new;
    }
}
