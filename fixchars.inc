/*
								MIT License

						Copyright (c) 2012 GameStar

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#tryinclude <open.mp>

#tryinclude <YSI_Coding\y_va>

#if !defined _INC_open_mp
	#error You must include open.mp.
#endif

#if !defined _INC_y_va
	#error You must include YSI_Coding\y_va.
#endif

#if defined fixchars_included
	#endinput
#endif
#define fixchars_included

stock Fixchar(c)
{
    switch (c) {
        // ß
        case 223: c = 150;

        // ä/Ä
        case 228: c = 154;
        case 196: c = 131;

        // á/Á
        case 225: c = 152;
        case 193: c = 128;

        // é/É
        case 233: c = 158;
        case 201: c = 135;

        // í/Í
        case 237: c = 162;
        case 205: c = 139;

        // ó/Ó
        case 243: c = 166;
        case 211: c = 143;

        // ő/Ő
        case 245: c = 167;
        case 213: c = 144;

        // ö/Ö
        case 246: c = 168;
        case 214: c = 145;

        // ú/Ú
        case 250: c = 170;
        case 218: c = 147;

        // ű/Ű
        case 251: c = 171;
        case 219: c = 148;

        // ü/Ü
        case 252: c = 172;
        case 220: c = 149;
    }

    return c;
}

/* -----------------------------------------------------------------------------------------------------------------*/

stock FIXCHARS_GameTextForPlayer(playerid, const text[], time, style, OPEN_MP_TAGS:...)
{
    for (new index, character; (character = getarg(1, index)); index++)
        setarg(1, index, Fixchar(character));

    return GameTextForPlayer(playerid, text, time, style, ___(4));
}

#if defined _ALS_GameTextForPlayer
    #undef GameTextForPlayer
#else
    #define _ALS_GameTextForPlayer
#endif
#define GameTextForPlayer FIXCHARS_GameTextForPlayer

/* -----------------------------------------------------------------------------------------------------------------*/

stock FIXCHARS_GameTextForAll(const text[], time, style, OPEN_MP_TAGS:...)
{
    for (new index, character; (character = getarg(0, index)); index++)
        setarg(0, index, Fixchar(character));

    return GameTextForAll(text, time, style, ___(3));
}

#if defined _ALS_GameTextForAll
    #undef GameTextForAll
#else
    #define _ALS_GameTextForAll
#endif
#define GameTextForAll FIXCHARS_GameTextForAll

/* -----------------------------------------------------------------------------------------------------------------*/

stock Text:FIXCHARS_TextDrawCreate(Float:x, Float:y, const text[], OPEN_MP_TAGS:...)
{
    for (new index, character; (character = getarg(2, index)); index++)
        setarg(2, index, Fixchar(character));

    return TextDrawCreate(x, y, text, ___(3));
}

#if defined _ALS_TextDrawCreate
    #undef TextDrawCreate
#else
    #define _ALS_TextDrawCreate
#endif
#define TextDrawCreate FIXCHARS_TextDrawCreate

/* -----------------------------------------------------------------------------------------------------------------*/

stock Menu:FIXCHARS_CreateMenu(const title[], columns, Float:x, Float:y, Float:col1width, Float:col2width = 0.0, OPEN_MP_TAGS:...)
{
    for (new index, character; (character = getarg(0, index)); index++)
        setarg(0, index, Fixchar(character));

    return CreateMenu(title, columns, x, y, col1width, col2width, ___(6));
}

#if defined _ALS_CreateMenu
    #undef CreateMenu
#else
    #define _ALS_CreateMenu
#endif
#define CreateMenu FIXCHARS_CreateMenu

/* -----------------------------------------------------------------------------------------------------------------*/

stock FIXCHARS_SetMenuColumnHeader(Menu:menuid, column, const columnheader[], OPEN_MP_TAGS:...)
{
    for (new index, character; (character = getarg(2, index)); index++)
        setarg(2, index, Fixchar(character));

    return SetMenuColumnHeader(menuid, column, columnheader, ___(3));
}

#if defined _ALS_SetMenuColumnHeader
    #undef SetMenuColumnHeader
#else
    #define _ALS_SetMenuColumnHeader
#endif
#define SetMenuColumnHeader FIXCHARS_SetMenuColumnHeader

/* -----------------------------------------------------------------------------------------------------------------*/

stock FIXCHARS_AddMenuItem(Menu:menuid, column, const menutext[], OPEN_MP_TAGS:...)
{
    for (new index, character; (character = getarg(2, index)); index++)
        setarg(2, index, Fixchar(character));

    return AddMenuItem(menuid, column, menutext, columnheader, ___(3));
}

#if defined _ALS_AddMenuItem
    #undef AddMenuItem
#else
    #define _ALS_AddMenuItem
#endif
#define AddMenuItem FIXCHARS_AddMenuItem

/* -----------------------------------------------------------------------------------------------------------------*/

stock FIXCHARS_TextDrawSetString(Text:text, const string[], OPEN_MP_TAGS:...)
{
    for (new index, character; (character = getarg(1, index)); index++)
        setarg(1, index, Fixchar(character));

    return TextDrawSetString(text, string, ___(2));
}

#if defined _ALS_TextDrawSetString
    #undef TextDrawSetString
#else
    #define _ALS_TextDrawSetString
#endif
#define TextDrawSetString FIXCHARS_TextDrawSetString

/* -----------------------------------------------------------------------------------------------------------------*/

#if defined CreatePlayerTextDraw
stock PlayerText:FIXCHARS_CreatePlayerTextDraw(playerid, Float:x, Float:y, const text[], OPEN_MP_TAGS:...)
{
    for (new index, character; (character = getarg(3, index)); index++)
        setarg(3, index, Fixchar(character));

    return CreatePlayerTextDraw(playerid, x, y, text, ___(4));
}

	#if defined _ALS_CreatePlayerTextDraw
    #undef CreatePlayerTextDraw
	#else
	    #define _ALS_CreatePlayerTextDraw
	#endif
	#define CreatePlayerTextDraw FIXCHARS_CreatePlayerTextDraw
#endif

/* -----------------------------------------------------------------------------------------------------------------*/

#if defined PlayerTextDrawSetString
stock FIXCHARS_PlayerTextDrawSetString(playerid, PlayerText:text, const string[], OPEN_MP_TAGS:...)
{
    for (new index, character; (character = getarg(2, index)); index++)
        setarg(2, index, Fixchar(character));

    return PlayerTextDrawSetString(playerid, text, string, ___(3));
}

	#if defined _ALS_PlayerTextDrawSetString
    #undef PlayerTextDrawSetString
	#else
	    #define _ALS_PlayerTextDrawSetString
	#endif
	#define PlayerTextDrawSetString FIXCHARS_PlayerTextDrawSetString
#endif