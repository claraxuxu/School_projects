/*
** EPITECH PROJECT, 2020
** append_char_str
** File description:
** add things after a char or a str
*/

char *append_char(char *str, char to_add)
{
    char *result = NULL;
    int size = 0;

    if (str == NULL) {
        result = malloc(sizeof(char) * 2);
        result[0] = to_add;
        result[1] = 0;
    } else {
        size = my_strlen(str);
        result = malloc(sizeof(char) * (size + 2));
        result = my_strcpy(result, str);
        result[size] = to_add;
        result[size + 1] = 0;
        free(str);
    }
    return result;
}

char **append_str(char **tab, char *str)
{
    int size = my_tablen((char const **)tab);
    char **res = size < 0 ? NULL : malloc(sizeof(char *) * (size + 2));
    int i = 0;

    if (str == NULL || str[0] == 0 || res == NULL)
        return tab;
    if (tab == NULL) {
        res = malloc(sizeof(char *) * 2);
        res[0] = my_strdup(str);
        res[1] = NULL;
        return (res);
    }
    for (; tab[i] != NULL; i++)
        res[i] = my_strdup(tab[i]);
    res[i] = my_strdup(str);
    res[i + 1] = NULL;
    free_tab((void **)tab);
    return (res);
}
