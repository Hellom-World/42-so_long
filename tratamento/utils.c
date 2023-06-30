
t_lay   ft_new_struct_layout(void)
{
    t_lay   layout;

    layout.n_row = 0;
    layout.n_col = 0;
    layout.n_exit = 0;
	layout.n_person = 0;
	layout.n_collect = 0;

    return (layout);
}

int	ft_strrncmp(const char *s1, const char *s2, size_t n)
{
	size_t	len1;
	size_t	len2;

	len1 = 0;
	len2 = 0;
	while (s1[len1] != '\0')
		len1++;
	while (s2[len2] != '\0')
		len2++;
	const char* end1 = s1 + len1 - 1;
	const char* end2 = s2 + len2 - 1;
	while (n > 0 && end1 >= s1 && end2 >= s2)
	{
		if (*end1 != *end2)
			break;
		end1--;
		end2--;
		n--;
	}
	if (n == 0)
		return 0;
	return (unsigned char)(*end1) - (unsigned char)(*end2);
}
int ft_countchar(char *str, char c) {
    int count = 0;

    while (*str != '\0') {
        if (*str == c) {
            count++;
        }
        str++;
    }

    return (count);
}

