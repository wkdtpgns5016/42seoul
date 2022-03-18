#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

int check_newline(char *buf, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        if (buf[i] == '\n')
            return (1);
        i++;
    }
    return (0);
}

char    *get_next_line(int fd)
{
    ssize_t        flag;
    char           buf[BUFFER_SIZE];
    char    *backup;
    
    backup = "";
    while (flag != 0 && !check_newline(buf, (int)flag))
    {
        flag = read(fd, buf, BUFFER_SIZE);
        backup = ft_strjoin(backup, buf);
    }
    return (backup);
}

int main() 
{ 
    int fd; 
    int i; 
    int j; 
    char *line = 0; 
    char *lineadress[66]; 
    
    j = 1; 
    printf("\n==========================================\n"); 
    printf("========= TEST 2 : Empty Lines ===========\n"); 
    printf("==========================================\n\n"); 
    if (!(fd = open("/home/bigdata/42seoul/gnlTester/files/41_no_nl", O_RDONLY))) 
    { 
        printf("\nError in open\n"); 
        return (0); 
    }
    printf("%s\n", get_next_line(fd));
    // getchar();
    // while ((line = get_next_line(fd)) != 0) 
    // { 
    //     printf("|%s\n", line); 
    //     free(line); 
    //     j++; 
    // } 
    // printf("|%s\n", line); 
    // free(line); 
    close(fd); 
}
