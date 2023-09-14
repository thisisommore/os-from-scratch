void mem_cpy(char *a, char *b, int bytes_max)
{
    for (int i = 0; i < bytes_max; i++)
    {
        *(a + i) = *(b + i);
    }
}

char *int_to_assci(int num)
{
    int i = 0;
    char buffer[100];
    int mod_n = 10;
    int div_n = 1;
    while ((mod_n / 10) <= num)
    {
        int res = num % mod_n;
        int dig = res / div_n;
        buffer[i] = dig + 48;
        i++;
        mod_n *= 10;
        div_n *= 10;
    }
    // reverse
    int k = i;
    for (int j = 0; j < i / 2; j++)
    {
        char temp = buffer[j];
        buffer[j] = buffer[k - 1];
        buffer[k - 1] = temp;
        k--;
    }
    buffer[i] = 0;

    char *b = &buffer;
    return b;
}