void get_params(char *command, char *bin_result, char *arguments_res)
{
    char *command_head = command;
    while (*command_head != ' ')
    {
        *(bin_result++) = *(command_head++);
    }
    command_head++;
    *(bin_result++) = 0;

    while (*command_head != 0)
    {
        *(arguments_res++) = *(command_head++);
    }
    *(arguments_res++) = 0;
}