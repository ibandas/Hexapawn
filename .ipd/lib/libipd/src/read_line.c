#include "libipd.h"

#include <ctype.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define READ_LINE_BUF_SIZE 80

static
void* realloc_or_die(void* old, size_t size)
{
    void* longer = realloc(old, size);

    if (longer == NULL) {
        free(old);
        perror(NULL);
        exit(1);
    }

    return longer;
}

char* read_line(void)
{
    return fread_line(stdin);
}

char* fread_line(FILE* inf)
{
    if (feof(inf)) return NULL;

    int c = getc(inf);
    if (c == EOF) return NULL;

    size_t capacity = READ_LINE_BUF_SIZE;
    size_t size     = 0;

    char* buffer    = realloc_or_die(NULL, capacity);

    for (;;) {
        if (c == EOF || c == '\n') {
            buffer[size] = '\0';
            return buffer;
        } else {
            buffer[size++] = (char) c;
        }

        c = getc(inf);

        if (size + 1 > capacity) {
            capacity *= 2;
            buffer = realloc_or_die(buffer, capacity);
        }
    }
}

char* prompt_line(const char* format, ...)
{
    va_list ap;
    va_start(ap, format);
    vprintf(format, ap);
    fflush(stdout);
    return read_line();
}
