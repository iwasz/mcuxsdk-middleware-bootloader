**Principles for Plugin boot application design**

The Boot ROM needs to jump between Plugin boot image and the normal boot image that is loaded by the plugin boot application. To avoid any impact on the ROM boot flow, here are some recommended principles for plugin boot application design.

1.  The plugin boot application must not use the memory that is currently reserved for ROM use
2.  The plugin boot application should use minimum stack spaces to avoid the possibility of stack overflow caused by plugin boot application
3.  The plugin boot application must consider Watchdog service, if the WDOG enable bit is enabled in the Fuse block


