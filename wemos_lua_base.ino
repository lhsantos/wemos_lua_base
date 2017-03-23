#ifdef ESP8266
  #include <pgmspace.h>
#else
  #include <avr/pgmspace.h>
#endif
#include <string.h>

#include "lua.hpp"


lua_State *g_lua;

static int lua_run_string(const char* s)
{
  luaL_loadstring(g_lua, s);
  if (LUA_OK != lua_pcall(g_lua, 0, LUA_MULTRET, 0))
  {
    const char *str = luaL_checkstring(g_lua, 1);
    Serial.print("wemos-lua: ");
    Serial.println(str);
  }
}

static int lua_print(lua_State *lua)
{
  const char *str = luaL_checkstring(lua, 1);
  Serial.print("wemos-lua: ");
  Serial.println(str);
  return 0;
}



// the setup function runs once when you press reset or power the board
void setup()
{
  Serial.begin(115200);
  
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);

  // lua
  g_lua = luaL_newstate();
  if (g_lua)
  {
    Serial.println("lua state created");
    luaL_openlibs(g_lua);
    Serial.println("lua libraries successfully loaded");
    lua_pushcfunction(g_lua, lua_print);
    lua_setglobal(g_lua, "wemos_print");
    lua_run_string("print('hello from lua! ' .. (6.0 * 7))\nwemos_print('hello from wemos!')");
    lua_run_string("print('this is an error! ' + (6.0 * 7))");
  }
  else
  {
    Serial.println("lua state creation failed");
  }
}

// the loop function runs over and over again forever
void loop()
{
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}
