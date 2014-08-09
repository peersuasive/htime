=====
htime
=====
--------------------------
get time with milliseconds
--------------------------


just a quick and dirty module to get milliseconds in lua scripts

requirements
============

- lua 5.1/luajit 2.X or lua 5.2 
- appropriate lua headers


build
=====

::

    make LUA52=[yes|no]


usage
=====

.. code:: lua

    local htime = require"htime"
    local s,ms = htime.time()
