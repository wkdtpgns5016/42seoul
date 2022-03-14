#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void *))
{
    t_list  *temp;
    t_list  *next;
    
    temp = *lst;
    while (temp != 0)
    {
        next = temp->next;
        del(temp->content);
        free(temp);
        //ft_lstdelone(temp, del);
        temp = next;
    }
    *lst = 0;
}
