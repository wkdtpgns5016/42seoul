#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define TYPE_END 0
#define TYPE_PIPE 1
#define TYPE_BREAK 2

#ifdef TEST_SH
# define TEST		1
#else
# define TEST		0
#endif

typedef struct s_list
{
    char **arg;
    int pipe[2];
    int length;
    int type;
    struct s_list *prev;
    struct s_list *next;
} t_list;

int ft_strlen(char *str)
{
    int len = 0;
    while (*str++)
        len++;
    return (len);
}

int    print_error(char *str)
{
    write(2, str, ft_strlen(str));
    return (1);
}

int    error_fatal(void)
{
    print_error("error: fatal\n");
    exit(1);
    return (1);
}

char    *error_fatal_ptr(void)
{
    error_fatal();
    exit(1);
    return (0);
}

char *ft_strdup(char *str)
{
    char *new;
    int i;

    if (!(new = ((char *)malloc(sizeof(char) * ft_strlen(str) + 1))))
        return (error_fatal_ptr());
    i = 0;
    while (str[i])
    {
        new[i] = str[i];
        i++;
    }
    new[i] = 0;
    return (0);
}

int add_arg(t_list *list, char *str)
{
    char **new;
    int len;

    if (!(new = ((char **)malloc(sizeof(char *) * (list->length + 2)))))
        return (error_fatal());
    len = 0;
    while (list->arg[len])
    {
        new[len] = list->arg[len];
        len++;
    }
    if (list->length > 0)
		free(list->arg);
    new[len++] = ft_strdup(str);
    new[len] = 0;
    list->arg = new;
    list->length++;
    return (0);
}

int list_push(t_list **list, char *arg)
{
    t_list *new;

    if (!(new = ((t_list *)malloc(sizeof(t_list)))))
        return (error_fatal());
    new->arg = NULL;
    new->length = 0;
    new->type = 0;
    new->next = NULL;
    new->prev = NULL;
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
    while (*list && ((*list)->prev))
        *list = (*list)->prev;
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

    is_break = (strcmp(arg, ";") == 0);
    if (is_break && !*list)
        return (0);
    else if (!is_break && (!*list && (*list)->type > TYPE_END))
        return (list_push(list, arg));
    else if (strcmp(arg, "|") == 0)
        (*list)->type = TYPE_PIPE;
    else if (is_break)
        (*list)->type = TYPE_BREAK;
    else
        return (add_arg(*list, arg));
    return (0);
}

int exec_cmd(t_list *cmd, char **env)
{
    pid_t pid;
    int ret;
    int status;
    int pipe_open;

    ret = 1;
    pipe_open = 0;
    if (cmd->type == TYPE_PIPE || (cmd->prev && cmd->prev->type == TYPE_PIPE))
    {
        pipe_open = 1;
        if (pipe(cmd->pipe))
            return (error_fatal());
    }
    pid = fork();
    if (pid == 0)
        return (error_fatal());
    else if (pid > 0)
    {
        if (cmd->type == TYPE_PIPE && (dup2(cmd->pipe[0], 1) < 0))
            return (error_fatal());
        else if (cmd->prev && (dup2(cmd->prev->pipe[1], 0) < 0))
            return (error_fatal());
        if ((ret = execve(cmd->arg[0], cmd->arg, env)) < 0)
        {
            print_error("error: cannot execute ");
			print_error(cmd->arg[0]);
			print_error("\n");
        }
        exit(ret);
    }
    else
    {
        waitpid(pid, &status, 0);
        if (pipe_open)
        {
            close(cmd->pipe[0]);
            if (!cmd->next || cmd->type == TYPE_BREAK)
                close(cmd->pipe[1]);
        }
        if (cmd->prev && cmd->prev->type == TYPE_PIPE)
            close(cmd->prev->pipe[1]);
        if (WIFEXITED(status))
            ret = WEXITSTATUS(status);
    }
    return (ret);
}

int exec_cmds(t_list **cmds, char **env)
{
    t_list *tmp;
    int ret;

    ret = 0;
    list_rewind(cmds);
    while (*cmds)
    {
        tmp = *cmds;
        if (strcmp("cd", tmp->arg[0]) == 0)
        {
            ret = 0;
            if (tmp->length < 2)
                ret = print_error("error: cd: bad arguments\n");
            else if (chdir(tmp->arg[1]))
            {
                ret = print_error("error: cd: cannot change directory to ");
                print_error(tmp->arg[1]);
                print_error("\n");
            }
        }
        else
            ret = exec_cmd(tmp, env);
        if (!(*cmds)->next)
            break;
        *cmds = (*cmds)->next;
    }
    return (ret);
}

int main(int ac, char **av, char **env)
{
    t_list *cmds;
    int i;
    int ret;

    ret = 0;
    cmds = NULL;
    i = 1;
    while (i < ac)
        parse(&cmds, av[i++]);
    if (cmds)
        ret = exec_cmds(&cmds, env);
    list_clear(&cmds);
    if (TEST)
		while (1);
    return (ret);
}