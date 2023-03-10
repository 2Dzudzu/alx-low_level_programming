#include "main.h"

/**
 *_strstr - locates a substring within a string
 *
 *@haystack: pointer that contains the address of the string to be evaluated
 *@needle: pointer that contains the string to evaluate @haystack
 *
 *Return: address of the located string in @haystack if no substring is found
 *then retun NULL
 */
char *_strstr(char *haystack, char *needle)
{
        char *result = haystack, *fneedle = needle;

        while (*haystack)
        {
                while (*needle)
                {
                        if (*haystack++ != *needle++)
                        {
                                break;
                        }
                }
                if (!*needle)
                {
                        return (result);
                }
                needle = fneedle;
                result++;
                haystack = result;
		}
        return (0);
	 {
                        if (*haystack++ != *needle++)
                        {
                                break;
                        }
                }
                if (!*needle)
                {
                        return (result);
                }
                needle = fneedle;
                result++;
                haystack = result;
        }
        return (0);
}
