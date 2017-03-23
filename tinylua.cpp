/**
 * Implements the functions declared on tinylua.h header.
 */

#include <Arduino.h>

#include "tinylua.h"


void tl_print_lua_string(const char* str, size_t len)
{
  Serial.write(str, len);
}

void tl_print_lua_error(const char* format, const char* param)
{
  size_t len = strlen(format) + strlen(param);
  char* buff = (char*) malloc(len * sizeof(char));
  sprintf(buff, format, param);
  Serial.println(buff);
  free(buff);
}

clock_t tl_clock (void)
{
     return (clock_t) micros();
}
