/**
 * Some platform-specific auxiliary functions for Lua.
 */

#ifndef _TINY_LUA_H_
#define _TINY_LUA_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <time.h>


void tl_print_lua_string(const char*, size_t);

void tl_print_lua_error(const char*, const char*);

clock_t tl_clock (void);

#ifdef __cplusplus
}
#endif

#endif /* _TINY_LUA_H_ */
