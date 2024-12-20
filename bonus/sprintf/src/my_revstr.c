/*
** EPITECH PROJECT, 2024
** my_strcpy
** File description:
** copies an string into another
*/

static char *end(char *src, int x)
{
    int end = x / 2;
    int i = 0;
    char temp;

    x--;
    while (i != end) {
        temp = src[x];
        src[x] = src[i];
        src[i] = temp;
        i++;
        x--;
    }
    return src;
}

static char *reverse(char *src)
{
    int x = 0;

    while (src[x] != '\0')
        x++;
    return end(src, x);
}

char *my_revstr(char *str)
{
    if (str[0] == '\0') {
        return str;
    }
    return reverse(str);
}
