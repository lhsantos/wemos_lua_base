# Tiny Lua for ESP8266

This is a simple base project to include the Lua programming language in Arduino code using ESP8266 based boards. It allows to run Lua scripts stored as strings (you must embed or load them from somewhere else yourself), with some libraries excluded (io, os, package, coroutine).

## Requirements

This project uses the lastest version of [ESP8266 Arduino](https://github.com/esp8266/Arduino) project and the source code for [Lua 5.3.4](https://www.lua.org/source/). It has been tested on Arduino IDE 1.8.2 for Linux with a WeMos D1 mini R2 board.

## Changes and Limitations on Lua

* All parts of the Lua code that were changed are marked with a `// &&WM` comment
* The flags `LUA_32BITS` and `LUA_USE_LONGJMP` (C exception handling) were enabled
* The following libraries were excluded: `io`, `os`, `package`, `coroutine`
* The following functions were removed from C API: `luaL_fileresult`, `luaL_execresult`, `luaL_loadfile`, `luaL_loadfilex`, `luaL_dofile`, `luaB_loadfile`, `luaB_dofile`
* Lua output messages are redirected to the Serial interface, check `tinylua.h`, `tinylua.cpp` and `lauxlib.h` to change this behavior

## Instalation

Just clone this project as a `wemos_lua_base` folder (change the folder and the `ino` file to rename) and open it as a sketchbook on Arduino. The files `wemos_lua_base.ino`, `tinylua.h`, `tinylua.cpp` have the additions made to the code and a very basic test/example.

