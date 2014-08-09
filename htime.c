#include <stdio.h>
#include <sys/time.h>

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

static int getTime();

static int getTime(lua_State *L) {
    struct timeval time;
    gettimeofday(&time, NULL);
    double nano = time.tv_sec * 1000000 + time.tv_usec;
    double seconds = time.tv_sec;
    double usecs = time.tv_usec;
    lua_pushnumber(L, seconds);
    lua_pushnumber(L, usecs);
    lua_pushnumber(L, nano);

    return 3;
}

int luaopen_htime (lua_State *L) {
    static const luaL_Reg mylib [] = {
        {"time", getTime},
        {NULL, NULL}
    };

    lua_newtable(L);
#if LUA_VERSION_NUM > 501
    luaL_setfuncs(L, mylib, 0);
#else
    luaL_register(L, NULL, mylib);
#endif
    return 1;
}
