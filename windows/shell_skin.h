/*****************************************************************************
 * Free42 -- an HP-42S calculator simulator
 * Copyright (C) 2004-2006  Thomas Okken
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License, version 2,
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *****************************************************************************/

#ifndef SHELL_SKIN_H
#define SHELL_SKIN_H 1

#include <windows.h>

void skin_load(char *skinname, const char *basedir, long *width, long *height);

typedef struct {
	unsigned char r, g, b, pad;
} SkinColor;

#define IMGTYPE_MONO 1
#define IMGTYPE_GRAY 2
#define IMGTYPE_COLORMAPPED 3
#define IMGTYPE_TRUECOLOR 4

#define KEYMAP_MAX_MACRO_LENGTH 16
typedef struct {
    bool ctrl;
	bool alt;
    bool shift; 
    int keycode;
    unsigned char macro[KEYMAP_MAX_MACRO_LENGTH];
} keymap_entry;

keymap_entry *parse_keymap_entry(char *line, int lineno);

int skin_getchar();
void skin_rewind();
int skin_init_image(int type, int ncolors, const SkinColor *colors,
					int width, int height);
void skin_put_pixels(unsigned const char *data);
void skin_finish_image();

void skin_repaint(HDC hdc, HDC memdc);
void skin_repaint_annunciator(HDC hdc, HDC memdc, int which, int state);
void skin_find_key(int x, int y, int *skey, int *ckey);
int skin_find_skey(int ckey);
unsigned char *skin_find_macro(int ckey);
unsigned char *skin_keymap_lookup(int keycode, bool ctrl, bool alt, bool shift);
void skin_repaint_key(HDC hdc, HDC memdc, int key, int state);
void skin_display_blitter(HDC hdc, const char *bits, int bytesperline, int x, int y,
						  int width, int height);
void skin_repaint_display(HDC hdc, HDC memdc);

#endif
