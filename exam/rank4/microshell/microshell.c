#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define TYPE_END 0
#define TYPE_PIPE 1
#define TYPE_BREAK 2

typedef struct s_list {
    int type;
    int length;
    int pipe[2];
    char **arg;
    struct s_list *prev;
    struct s_list *next;
} t_list;

int ft_strlen(char *str)
{
    int len;

    len = 0;
    while (*str++)
        len++;
    return (len);
}

int print_error(char *str)
{
    write(2, str, ft_strlen(str));
    return (1);
}

int error_fatal(void)
{
    print_error("error: fatal\n");
    exit(1);
    return (1);
}

char *error_fatal_ptr(void)
{
    error_fatal();
    exit(1);
    return (NULL);
}

char *ft_strdup(char *str)
{
    char *new;
    int i;

    if (!(new = (char *)malloc(sizeof(char) * ft_strlen(str) + 1)))
        return (error_fatal_ptr());
    i = 0;
    while (str[i])
    {
        new[i] = str[i];
        i++;
    }
    new[i] = 0;
    return (new);
}

int add_arg(t_list *list, char *arg)
{
    char **new;
    int i;

    i = 0;
    new = NULL;
    if (!(new = (char **)malloc(sizeof(char *) * (list->length + 2))))
        return (error_fatal());
    while (i < list->length)
    {
        new[i] = list->arg[i];
        i++;
    }
    if (list->length > 0)
        free(list->arg);
    new[i++] = ft_strdup(arg);
    new[i] = 0;
    list->arg = new;
    list->length++;
    return (0);
}

int list_push(t_list **list, char *arg)
{
    t_list *new;

    if (!(new = (t_list *)malloc(sizeof(t_list))))
        return (error_fatal());
    new->arg = NULL;
    new->length = 0;
    new->type = TYPE_END;
    new->prev = NULL;
    new->next = NULL;
    if (*list)
    {
        (*list)->next = new;
        new->prev = *list;
    }
    *list = new;
    return (add_arg(new, arg));
}

int list_rewind(t_list **list)
{
    while ((*list) && (*list)->prev)
        (*list) = (*list)->prev;
    return (0);
}

int list_clear(t_list **list)
{
    t_list *tmp;
    int i;

    list_rewind(list);
    while (*list)
    {
        tmp = (*list)->next;
        i = 0;
        while (i < (*list)->length)
            free((*list)->arg[i++]);
        free((*list)->arg);
        free(*list);
        *list = tmp;
    }
    *list = NULL;
    return (0);
}


int parse(t_list **list, char *arg)
{
    int is_break;

    is_break = (strcmp(";", arg) == 0);
    if (is_break && !*list)
        return (0);
    else if (!is_break && (!*list || (*list)->type > TYPE_END))
        return (list_push(list, arg));
    else if (strcmp("|", arg) == 0)
        (*list)->type = TYPE_PIPE;
    else if (is_break)
        (*list)->type = TYPE_BREAK;
    else
        return (add_arg(*list, arg));
    return (0);
}

int exec_cmd(t_list *list, char **env)
{
    pid_t pid;
    int status;
    int is_pipe;
    int ret;

    is_pipe = 0;
    ret = 1;
    if (list->type == TYPE_PIPE || (list->prev && list->prev->type == TYPE_PIPE))
    {
        is_pipe = 1;
        if (pipe(list->pipe))
            return (error_fatal());
    }
    pid = fork();
    if (pid < 0)
        return (error_fatal());
    else if (pid == 0)
    {
        if (list->type == TYPE_PIPE 
            && dup2(list->pipe[1], 1) < 0)
            return (error_fatal());
        if (list->prev && list->prev->type == TYPE_PIPE 
            && dup2(list->prev->pipe[0], 0) < 0)
            return (error_fatal());
        if ((ret = execve(list->arg[0], list->arg, env)) < 0)
        {
            print_error("error: cannot execute ");
            print_error(list->arg[0]);
            print_error("\n");
        }
        exit(ret);
    }
    else
    {
        waitpid(pid, &status, 0);
        if (is_pipe)
        {
            close(list->pipe[1]);
            if (!list->next || list->type == TYPE_BREAK)
                close(list->pipe[0]);
        }
        if (list->prev && list->prev->type == TYPE_PIPE)
                close(list->prev->pipe[0]);
        if (WIFEXITED(status))
            ret = WEXITSTATUS(status);
    }
    return (ret);
}

int exec_cmds(t_list **list, char **env)
{
    int ret;

    ret = 0;
    list_rewind(list);
    while (*list)
    {
        if (strcmp("cd", (*list)->arg[0]) == 0)
        {
            ret = 0;
            if ((*list)->length < 2)
                ret = print_error("error: cd: bad arguments\n");
            else if (chdir((*list)->arg[1]))
            {
                ret = print_error("error: cd: cannot change directory to ");
                print_error((*list)->arg[1]);
                print_error("\n");
            }
        }
        else
            ret = exec_cmd(*list, env);
        if (!(*list)-> next)
            break;
        (*list) = (*list)->next;
    }
    return (ret);
}

int main(int ac, char **av, char **env)
{
    t_list *list;
    int i;
    int ret;

    i = 1;
    ret = 0;
    list = NULL;
    while (i < ac)
        parse(&list, av[i++]);
    if (list)
        ret = exec_cmds(&list, env);
    list_clear(&list);
    return (ret);
}