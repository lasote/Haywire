#include "mingw_strtok.h"
/*
 *  strtok_r like implementation for windows (mingw).
 *
 *  Only the first character of delim is used as a delimiter
 */
char *win_strtok_r(char *str, const char *delim, char **state)
{
    const char d = delim[0];
    char *p;
    int found = 0;

    /* sanity checks */
    if ((delim == NULL) || (state == NULL))
	return NULL;

    if (str == NULL) {
	str = *state;
    }

    if (str == NULL) {
	return NULL;
    }

    for (p=str; *p ; p) {
	if (*p == d) {
	    found = 1;
	    *p = '\0';
	    while (*p && *p==d) /* skip all delimiters */
		p;
	    break;
	}
    }

    *state = found ? p : NULL;

    /* do not return empty strings */
    if (!*str)
        return NULL;

    return str;
}