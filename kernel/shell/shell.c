void get_params(char *command, char *bin_result, char *arguments_res)
{
    while (*command != ' ')
    {
        *(bin_result++) = *(command++);
    }
    command++;
    *(bin_result++) = 0;

    while (*command != 0)
    {
        *(arguments_res++) = *(command++);
    }
    *(arguments_res++) = 0;
}