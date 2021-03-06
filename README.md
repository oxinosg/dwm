dwm - dynamic window manager
============================
dwm is an extremely fast, small, and dynamic window manager for X.

add setgapsex to dwmc

Patches applied
---------------
 - [aspectresize](https://dwm.suckless.org/patches/aspectresize/) - Resize the window with its aspect ratio remain constant
 - [attachaside](https://dwm.suckless.org/patches/attachaside/) - Make new clients get attached and focused in the stacking area instead of always becoming the new master.
 - [canfocusfloating](https://dwm.suckless.org/patches/canfocusfloating/) - Allows disabling focus on floating clients
 - [columngaps](https://dwm.suckless.org/patches/columngaps/) - Like tile layout, except provides for vertical instead of horizontal master windows.
 - [dwmc](https://dwm.suckless.org/patches/dwmc/) - Simple client to communicate with dwm.
 - [fakefullscreen](https://dwm.suckless.org/patches/fakefullscreen/) - Only allow clients to "fullscreen" into space currently given to them.
 - [fibonacci](https://dwm.suckless.org/patches/fibonacci/) - This patch adds two new layouts (spiral and dwindle) that arranges all windows in Fibonacci tiles.
 - [float border color](https://dwm.suckless.org/patches/float_border_color/) - Simple client to communicate with dwm.
 - [focusonclick](https://dwm.suckless.org/patches/focusonclick/) - Switch focus only by mouse click.
 - [hideborder](https://dwm.suckless.org/patches/hideborder/) - Patch that turns border color of active client to the background color
 - [gaplessgrid](https://dwm.suckless.org/patches/gaplessgrid/) - Layout for dwm, which arranges the windows in a grid
 - [hidevacanttags](https://dwm.suckless.org/patches/hide_vacant_tags/) - This patch prevents dwm from drawing tags with no clients on the bar.
 - [moveresizedge](https://dwm.suckless.org/patches/moveresize/) - This change allows you to move and resize dwm's clients using keyboard bindings.
 - [movestack](https://dwm.suckless.org/patches/movestack/) - This plugin allows you to move clients around in the stack and swap them with the master.
 - [nmaxmaster](https://dwm.suckless.org/patches/nmaxmaster/) - Adds limit to number of clients
 - [noborder](https://dwm.suckless.org/patches/noborder/) - Remove the border when there is only one window visible.
 - [pertag](https://dwm.suckless.org/patches/pertag/) - This patch keeps layout, mwfact, barpos and nmaster per tag.
 - [restartsig](https://dwm.suckless.org/patches/restartsig/) - dwm can now be restarted.
 - [save_floats](https://dwm.suckless.org/patches/save_floats/) - This patch saves size and position of every floating window before it is forced into tiled mode. If the window is made floating again, the old dimensions will be restored.
 - [scratchpad](https://dwm.suckless.org/patches/scratchpad/) - The scratchpad patch allows you to spawn or restore a floating terminal window. It is usually useful to have one to do some short typing.
 - [statusallmons](https://dwm.suckless.org/patches/statusallmons/) - This patch draws and updates the statusbar on all monitors.
 - [sticky](https://dwm.suckless.org/patches/sticky/) - Allows to make a client 'sticky'. A sticky client is visible on all tags.
 - [swallow](https://dwm.suckless.org/patches/swallow/) - This patch adds "window swallowing" to dwm
 - [systray](https://dwm.suckless.org/patches/systray/) - Simple system tray implementation
 - [tile](https://dwm.suckless.org/patches/ru_gaps/) - This patch adds gaps like tilegap that are resizeable at runtime.
 - [urgent border](https://dwm.suckless.org/patches/urgentborder/) This patch makes borders of "urgent" windows a different color.
 - [viewontag](https://dwm.suckless.org/patches/viewontag/) - Follow a window to the tag it is being moved to.
 - [warp](https://dwm.suckless.org/patches/warp/) - This patch warps the mouse cursor to the center of the currently focused window or screen when the mouse cursor is (a) on a different screen or (b) on top of a different window.
 - [zoomswap](https://dwm.suckless.org/patches/zoomswap/) - This patch changes the behavior of zoom, to keep all other windows as they are

Requirements
------------
In order to build dwm you need the Xlib header files.


Installation
------------
Edit config.mk to match your local setup (dwm is installed into
the /usr/local namespace by default).

Afterwards enter the following command to build and install dwm (if
necessary as root):

    make clean install


Running dwm
-----------
Add the following line to your .xinitrc to start dwm using startx:

    exec dwm

In order to connect dwm to a specific display, make sure that
the DISPLAY environment variable is set correctly, e.g.:

    DISPLAY=foo.bar:1 exec dwm

(This will start dwm on display :1 of the host foo.bar.)

In order to display status info in the bar, you can do something
like this in your .xinitrc:

    while xsetroot -name "`date` `uptime | sed 's/.*,//'`"
    do
    	sleep 1
    done &
    exec dwm


Configuration
-------------
The configuration of dwm is done by creating a custom config.h
and (re)compiling the source code.
