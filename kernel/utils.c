void mem_cpy(char *a, char *b, int bytes_max)
{
    for (int i = 0; i < bytes_max; i++)
    {
        *(a + i) = *(b + i);
    }
}