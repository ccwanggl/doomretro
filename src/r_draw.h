/*
==============================================================================

                                 DOOM Retro
           The classic, refined DOOM source port. For Windows PC.

==============================================================================

    Copyright © 1993-2025 by id Software LLC, a ZeniMax Media company.
    Copyright © 2013-2025 by Brad Harding <mailto:brad@doomretro.com>.

    This file is a part of DOOM Retro.

    DOOM Retro is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by the
    Free Software Foundation, either version 3 of the license, or (at your
    option) any later version.

    DOOM Retro is distributed in the hope that it will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
    General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with DOOM Retro. If not, see <https://www.gnu.org/licenses/>.

    DOOM is a registered trademark of id Software LLC, a ZeniMax Media
    company, in the US and/or other countries, and is used without
    permission. All other trademarks are the property of their respective
    holders. DOOM Retro is in no way affiliated with nor endorsed by
    id Software.

==============================================================================
*/

#pragma once

#include "m_random.h"

#define FUZZ1(a, b)             fuzzrange[M_Fuzz1RandomInt(a, b) + 1]
#define FUZZ2(a, b)             fuzzrange[M_Fuzz2RandomInt(a, b) + 1]
#define BIGFUZZYPIXEL(a, b)     *dest = *(dest + 1) = *(dest + SCREENWIDTH) = *(dest + SCREENWIDTH + 1) = \
                                    fullcolormap[(a) * 256 + dest[b]]
#define HALFBIGFUZZYPIXEL(a, b) *dest = *(dest + 1) = fullcolormap[(a) * 256 + dest[b]]

#define NOTEXTURECOLOR          nearestcolors[LIGHTGRAY1]

extern lighttable_t     *dc_colormap[2];
extern lighttable_t     *dc_nextcolormap[2];
extern lighttable_t     *dc_sectorcolormap;
extern int              dc_x;
extern int              dc_yl;
extern int              dc_yh;
extern int              dc_z;
extern fixed_t          dc_iscale;
extern fixed_t          dc_texturemid;
extern fixed_t          dc_texheight;
extern fixed_t          dc_texturefrac;
extern byte             dc_solidbloodcolor;
extern byte             *dc_bloodcolor;
extern byte             *dc_brightmap;
extern int              dc_floorclip;
extern int              dc_ceilingclip;
extern int              dc_numposts;
extern byte             dc_black;
extern byte             *dc_black33;
extern byte             *dc_black40;

// first pixel in a column
extern byte             *dc_source;

extern int              fuzz1pos;
extern int              fuzz2pos;
extern int              fuzzrange[3];
extern int              fuzz1table[MAXSCREENAREA];
extern int              fuzz2table[MAXSCREENAREA];

// The span blitting interface.
// Hook in assembler or system specific BLT here.
void R_DrawColumn(void);
void R_DrawColumnWithBrightmap(void);
void R_DrawLowResDitheredColumn(void);
void R_DrawDitheredColumn(void);
void R_DrawCorrectedColumn(void);
void R_DrawCorrectedLowResDitheredColumn(void);
void R_DrawCorrectedDitheredColumn(void);
void R_DrawSolidColorColumn(void);
void R_DrawWallColumn(void);
void R_DrawLowResDitheredWallColumn(void);
void R_DrawDitheredWallColumn(void);
void R_DrawWallColumnWithBrightmap(void);
void R_DrawLowResDitheredColumnWithBrightmap(void);
void R_DrawDitheredColumnWithBrightmap(void);
void R_DrawLowResDitheredWallColumnWithBrightmap(void);
void R_DrawDitheredWallColumnWithBrightmap(void);
void R_DrawLowResDitheredSolidColorColumn(void);
void R_DrawDitheredSolidColorColumn(void);
void R_DrawSkyColumn(void);
void R_DrawFlippedSkyColumn(void);
void R_DrawTranslucentColumn(void);
void R_DrawTranslucent50Column(void);
void R_DrawLowResDitheredTranslucent50Column(void);
void R_DrawDitheredTranslucent50Column(void);
void R_DrawTranslucent50ColumnWithBrightmap(void);
void R_DrawDitheredTranslucent50ColumnWithBrightmap(void);
void R_DrawLowResDitheredTranslucent50ColumnWithBrightmap(void);
void R_DrawCorrectedTranslucent50Column(void);
void R_DrawTranslucent50SolidColorColumn(void);
void R_DrawLowResDitheredTranslucent50SolidColorColumn(void);
void R_DrawDitheredTranslucent50SolidColorColumn(void);
void R_DrawTranslucent33Column(void);
void R_DrawTranslucentGreenColumn(void);
void R_DrawTranslucentRedColumn(void);
void R_DrawTranslucentRedWhiteColumn1(void);
void R_DrawTranslucentRedWhiteColumn2(void);
void R_DrawTranslucentRedWhite50Column(void);
void R_DrawTranslucentBlueColumn(void);
void R_DrawTranslucentGreen33Column(void);
void R_DrawTranslucentRed33Column(void);
void R_DrawTranslucentBlue25Column(void);
void R_DrawPlayerSpriteColumn(void);
void R_DrawShadowColumn(void);
void R_DrawSolidShadowColumn(void);
void R_DrawTranslucentBloodColumn(void);
void R_DrawBloodSplatColumn(void);
void R_DrawSolidBloodSplatColumn(void);

// The spectre/invisibility effect.
void R_DrawFuzzColumn(void);
void R_DrawFuzzColumns(void);
void R_DrawFuzzyShadowColumn(void);

// Draw with color translation tables,
//  for player sprite rendering,
//  green/red/blue/indigo shirts.
void R_DrawTranslatedColumn(void);
void R_DrawDitherLowTranslatedColumn(void);
void R_DrawDitherTranslatedColumn(void);

void R_VideoErase(unsigned int offset, int count);

extern int          ds_x1;
extern int          ds_x2;
extern int          ds_y;
extern int          ds_z;

extern lighttable_t *ds_colormap[2];
extern lighttable_t *ds_sectorcolormap;

extern fixed_t      ds_xfrac;
extern fixed_t      ds_yfrac;
extern fixed_t      ds_xstep;
extern fixed_t      ds_ystep;

// start of a 64x64 tile image
extern byte         *ds_source;

extern byte         translationtables[256 * 3];
extern byte         *dc_translation;

// Span blitting for rows, floor/ceiling.
// No Spectre effect needed.
void R_DrawSpan(void);
void R_DrawLowResDitheredSpan(void);
void R_DrawDitheredSpan(void);
void R_DrawSolidColorSpan(void);
void R_DrawLowResDitheredSolidColorSpan(void);
void R_DrawDitheredSolidColorSpan(void);

void R_InitBuffer(void);

// Initialize color translation tables,
//  for player rendering etc.
void R_InitTranslationTables(void);

void R_FillBezel(void);

// Rendering function.
void R_FillBackScreen(void);

// If the view size is not fullscreen, draws a border around it.
void R_DrawViewBorder(void);
