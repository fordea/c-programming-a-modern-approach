#include <stdio.h>
#include <string.h>

#define NUM_COMMANDS (sizeof(file_cmd) / sizeof(file_cmd[0]))
#define MAX 51

void new_cmd(void);
void open_cmd(void);
void close_cmd(void);
void close_all_cmd(void);
void save_cmd(void);
void save_as_cmd(void);
void save_all_cmd(void);
void print_cmd(void);
void exit_cmd(void);

void print_command_list(void);
void get_command(char *cmd, int n);
void parse_command(char *cmd);

struct {
    char *cmd_name;
    void (*cmd_pointer)(void);

} file_cmd[] =
{{"new",        new_cmd},
 {"open",       open_cmd},
 {"close",      close_cmd},
 {"close all",  close_all_cmd},
 {"save",       save_cmd},
 {"save as",    save_as_cmd},
 {"save all",   save_all_cmd},
 {"print",      print_cmd},
 {"exit",       exit_cmd}
};

int main(void)
{
    char cmd[MAX];
    int i;
    print_command_list();

    get_command(cmd, MAX);
    do {
        parse_command(cmd);
        get_command(cmd, MAX);
    } while ((strcmp(cmd, "q")) != 0);

    return 0;
}

void get_command(char *cmd, int n)
{
    printf("Enter command (q to quit): ");
    fgets(cmd, n, stdin);
    cmd[strlen(cmd)-1] = '\0';  /* remove the \n character */
}

void parse_command(char *cmd)
{
    int i;
    for (i = 0; i < NUM_COMMANDS; i++)
        if (strcmp(cmd, file_cmd[i].cmd_name) == 0)
            file_cmd[i].cmd_pointer();
}

void print_command_list(void)
{
    int i;
    printf("List of commands:\n");
    for (i = 0; i < NUM_COMMANDS; i++)
        printf("%s\n", file_cmd[i].cmd_name);
}

void new_cmd(void)
{
    printf("Called new_cmd\n");
}

void open_cmd(void)
{
    printf("Called open_cmd\n");
}

void close_cmd(void)
{
    printf("Called close_cmd\n");
}

void close_all_cmd(void)
{
    printf("Called close_all_cmd\n");
}

void save_cmd(void)
{
    printf("Called save_cmd\n");
}

void save_as_cmd(void)
{
    printf("Called save_as_cmd\n");
}

void save_all_cmd(void)
{
    printf("Called save_all_cmd\n");
}

void print_cmd(void)
{
    printf("Called print_cmd\n");
}

void exit_cmd(void)
{
    printf("Called exit_cmd\n");
}
