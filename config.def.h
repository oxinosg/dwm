/* See LICENSE file for copyright and license details. */

/* appearance */
static const char font[] = "IBM Plex Mono:size=14";
static const char *fonts[] = {
    "SourceCodePro:style=Regular:size=14",
    "Hack:size=14",
    "Hack Nerd Font:size=14",
    "JoyPixels:pixelsize=14:antialias=true:autohint=true",
    "mono:pixelsize=14:antialias=true:autohint=true",
    "Symbola:pixelsize=14:antialias=true:autohint=true"
};
static const char dmenufont[]       = "Hack:size=14";
static const char normbgcolor[]     = "#222222";
static const char normfgcolor[]     = "#bbbbbb";
// static const char titlefgcolor[]     = "#89b8c2";
static const char titlefgcolor[]     = "#222222";
// static const char titlebgcolor[]     = "#161821";
static const char titlebgcolor[]       = "#222222";
static const char titlebordercolor[] = "#161821";
static const char normbordercolor[] = "#444444";
static const char selbordercolor[]  = "#84a0c6";
static const char selbgcolor[]      = "#161821";
static const char selfgcolor[]      = "#eeeeee";
static const unsigned int borderpx  = 3;        /* border pixel of windows */
static const unsigned int gappx     = 12;       /* gap pixel between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int systraypinning = 1;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;        /* 0 means no systray */
static const int swallowfloating    = 0;        /* 1 means swallow floating windows by default */
static const Bool viewontag         = True;     /* Switch view on tag switch */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int focusonwheel       = 0;
static const unsigned int barsize    = 10;       /* size of the dwm bar */
static const unsigned int tagspacing = 10;        /* size of icon area */
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";
static const char col_cyan2[]       = "#0092cc";
static const char col_urgborder[]   = "#ff0000";

static const char *colors[][3]      = {
  /*               fg         bg         border   */
  [SchemeNorm] = { col_gray3, col_gray1, col_gray1 },
  [SchemeSel]  = { col_gray4, col_gray1, col_cyan2 },
	[SchemeUrg]  = { col_gray4, col_cyan,  col_urgborder  },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class     instance  title           tags mask  isfloating  isterminal  noswallow  monitor */
	{ "Gimp",    NULL,     NULL,           0,         1,          0,           0,        -1 },
	{ "Firefox", NULL,     NULL,           1 << 8,    0,          0,          -1,        -1 },
	{ "St",      NULL,     NULL,           0,         0,          1,           0,        -1 },
	{ NULL,      NULL,     "Event Tester", 0,         0,          0,           1,        -1 }, /* xev */
};

/* layout(s) */
static const float mfact     = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

#include "movestack.c"
#include "fibonacci.c"
#include "gaplessgrid.c"

static const Layout layouts[] = {
    /* symbol     arrange function */
    { "况",       tile },        /* first entry is default */
    { "冀",       col },
    { "[M]",      monocle },
    { "侀",       spiral },
    { "全",       gaplessgrid },
    { "><>",      NULL },        /* no layout function means floating behavior */
};

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/** Function to shift the current view to the left/right
 *
 * @param: "arg->i" stores the number of tags to shift right (positive value)
 *          or left (negative value)
 */
void
shiftview(const Arg *arg) {
  Arg shifted;

  if(arg->i > 0) // left circular shift

/* commands */
static char dmenumon[2]            = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[]      = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]       = { "st", NULL };
static const char scratchpadname[] = "scratchpad";
static const char *scratchpadcmd[] = { "st", "-t", scratchpadname, "-g", "120x34", NULL };

static Key keys[] = {
  /* modifier                     key            function        argument */
  { MODKEY,                       XK_b,          togglebar,      {0} },
  { MODKEY,                       XK_j,          focusstack,     {.i = +1 } },
  { MODKEY,                       XK_k,          focusstack,     {.i = -1 } },
  { MODKEY|ShiftMask,             XK_j,          movestack,      {.i = +1 } },
  { MODKEY|ShiftMask,             XK_k,          movestack,      {.i = -1 } },
  { MODKEY,                       XK_o,          incnmaster,     {.i = +1 } },
  { MODKEY,                       XK_i,          incnmaster,     {.i = -1 } },
  { MODKEY,                       XK_h,          setmfact,       {.f = -0.05} },
  { MODKEY,                       XK_l,          setmfact,       {.f = +0.05} },
  { MODKEY,                       XK_Return,     spawn,          {.v = termcmd } },
  { MODKEY,                       XK_grave,      togglescratch,  {.v = scratchpadcmd } },
  { MODKEY,                       XK_Tab,        view,           {0} },
  { MODKEY|ShiftMask,             XK_c,          killclient,     {0} },
  { MODKEY,                       XK_t,          setlayout,      {.v = &layouts[0]} },
  { MODKEY|ShiftMask,             XK_t,          setlayout,      {.v = &layouts[1]} },
  { MODKEY,                       XK_f,          setlayout,      {.v = &layouts[2]} },
  { MODKEY,                       XK_y,          setlayout,      {.v = &layouts[3]} },
  { MODKEY,                       XK_g,          setlayout,      {.v = &layouts[4]} },
  { MODKEY,                       XK_space,      setlayout,      {0} },
  { MODKEY|ControlMask,           XK_space,      zoom,           {0} },
  { MODKEY|ShiftMask,             XK_space,      togglefloating, {0} },
  { MODKEY,                       XK_s,          togglesticky,   {0} },
  { MODKEY,                       XK_0,          view,           {.ui = ~0 } },
  { MODKEY|ShiftMask,             XK_0,          tag,            {.ui = ~0 } },
  { MODKEY,                       XK_comma,      focusmon,       {.i = -1 } },
  { MODKEY,                       XK_period,     focusmon,       {.i = +1 } },
  { MODKEY|ShiftMask,             XK_comma,      tagmon,         {.i = -1 } },
  { MODKEY|ShiftMask,             XK_period,     tagmon,         {.i = +1 } },
  { MODKEY,                       XK_equal,      setgaps,        {.i = -5 } },
  { MODKEY,                       XK_minus,      setgaps,        {.i = +5 } },
  { MODKEY|ShiftMask,             XK_equal,      setgaps,        {.i = 0  } },
  TAGKEYS(                        XK_1,                          0)
  TAGKEYS(                        XK_2,                          1)
  TAGKEYS(                        XK_3,                          2)
  TAGKEYS(                        XK_4,                          3)
  TAGKEYS(                        XK_5,                          4)
  TAGKEYS(                        XK_6,                          5)
  TAGKEYS(                        XK_7,                          6)
  TAGKEYS(                        XK_8,                          7)
  TAGKEYS(                        XK_9,                          8)
  { MODKEY,                       XK_q,          killclient,     {0} },
  { MODKEY|ControlMask,           XK_q,          quit,           {0} },
  { MODKEY|ControlMask|ShiftMask, XK_q,          quit,           {1} },
  { MODKEY,                       XK_Page_Up,    shiftview,      { .i = -1 } },
  { MODKEY,                       XK_Page_Down,  shiftview,      { .i = 1 } },
  { MODKEY,                       XK_Up,         moveresize,     {.v = "0x -25y 0w 0h"} },
  { MODKEY,                       XK_Down,       moveresize,     {.v = "0x 25y 0w 0h"} },
  { MODKEY,                       XK_Left,       moveresize,     {.v = "-25x 0y 0w 0h"} },
  { MODKEY,                       XK_Right,      moveresize,     {.v = "25x 0y 0w 0h"} },
  { MODKEY|ShiftMask,             XK_Up,         moveresize,     {.v = "0x 0y 0w -25h"} },
  { MODKEY|ShiftMask,             XK_Down,       moveresize,     {.v = "0x 0y 0w 25h"} },
  { MODKEY|ShiftMask,             XK_Left,       moveresize,     {.v = "0x 0y -25w 0h"} },
  { MODKEY|ShiftMask,             XK_Right,      moveresize,     {.v = "0x 0y 25w 0h"} },
  { MODKEY|ControlMask,           XK_Up,         moveresizeedge, {.v = "t"} },
  { MODKEY|ControlMask,           XK_Down,       moveresizeedge, {.v = "b"} },
  { MODKEY|ControlMask,           XK_Left,       moveresizeedge, {.v = "l"} },
  { MODKEY|ControlMask,           XK_Right,      moveresizeedge, {.v = "r"} },
  { MODKEY|ControlMask|ShiftMask, XK_Up,         moveresizeedge, {.v = "T"} },
  { MODKEY|ControlMask|ShiftMask, XK_Down,       moveresizeedge, {.v = "B"} },
  { MODKEY|ControlMask|ShiftMask, XK_Left,       moveresizeedge, {.v = "L"} },
  { MODKEY|ControlMask|ShiftMask, XK_Right,      moveresizeedge, {.v = "R"} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

