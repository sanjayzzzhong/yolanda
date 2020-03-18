/*
 * @Author: Sanjay Zhong 
 * @Date: 2020-03-18 22:49:18 
 * @Last Modified by: Sanjay Zhong
 * @Last Modified time: 2020-03-18 22:51:09
 */
#include    "common.h"
#include    <stdarg.h>        /* ANSI C header file */
#include    <syslog.h>

/* error - print a diagnostic and optionally exit */
void error(int status, int err, char *fmt, ...) {
    va_list ap;

    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap);
    va_end(ap);
    if (err)
        fprintf(stderr, ": %s (%d)\n", strerror(err), err);
    if (status)
        exit(status);
}