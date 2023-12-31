#ifndef ERROR_H
#define ERROR_H

#include "text.h"
#include "general.h"

/* code for error */
char *message_selector(general_t info);
void error(general_t *info);
void error_extra(general_t *info, char *extra);

#endif
