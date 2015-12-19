/**************************************************************************//**
 * @file Graphics.c
 * @brief Graphic files for the UI and etc
 * @author Tuomas Tinus, Jimi Järvelin
 * @version 0.5
 ******************************************************************************/

#include "stdint.h"
#include "Graphics.h"

const uint16_t LoadingBackground [] = { 0xfffc, 0xff, 0xf800, 0x3fff, 0x0, 0xfff0, 0xfffc, 0xff, 0xf800, 0x3fff,
		 0x0, 0xfff8, 0xfff8, 0xff, 0xf800, 0x3fff, 0x0, 0xfff8, 0xfff8, 0x1ff,
		 0xf800, 0x1fff, 0x0, 0xfffc, 0xfff0, 0x1ff, 0xf800, 0x1fff, 0x0, 0xfffc,
		 0xfff0, 0x1ff, 0xf800, 0x1fff, 0x0, 0xfffe, 0xffe0, 0x3ff, 0xf800, 0xfff,
		 0x0, 0xffff, 0xffc0, 0x3ff, 0xf800, 0xfff, 0x0, 0xffff, 0xffc0, 0x3ff,
		 0xf800, 0xfff, 0x8000, 0xffff, 0xff80, 0x3ff, 0xf800, 0xfff, 0x8000, 0xffff,
		 0xff80, 0x7ff, 0xf800, 0x7ff, 0xc000, 0xffff, 0xff00, 0x7ff, 0xf800, 0x7ff,
		 0xc000, 0xffff, 0xff00, 0x7ff, 0xf800, 0x7ff, 0xe000, 0xffff, 0xfe00, 0x7ff,
		 0xf800, 0x7ff, 0xf000, 0xffff, 0xfc00, 0xfff, 0xf800, 0x3ff, 0xf000, 0xffff,
		 0xfc00, 0xfff, 0xf800, 0x3ff, 0xf800, 0xffff, 0xf800, 0xfff, 0xf800, 0x3ff,
		 0xf800, 0xffff, 0xf800, 0xfff, 0xf800, 0x3ff, 0xfc00, 0xffff, 0xf000, 0x1fff,
		 0xf800, 0x1ff, 0xfe00, 0xffff, 0xf000, 0x1fff, 0xf800, 0x1ff, 0xfe00, 0xffff,
		 0xe000, 0x1fff, 0xf800, 0x1ff, 0xff00, 0x7fff, 0xc000, 0x3fff, 0xf800, 0x1ff,
		 0xff00, 0x1fff, 0xc000, 0x3fff, 0xf800, 0xff, 0xff80, 0x1fff, 0x8000, 0x3fff,
		 0xf800, 0xff, 0xff80, 0x7ff, 0x8000, 0x3fff, 0xf800, 0xff, 0xffc0, 0x7ff,
		 0x0, 0x7fff, 0xf800, 0x7f, 0xffe0, 0x3ff, 0x0, 0x7ffe, 0xf800, 0x7f,
		 0xffe0, 0xff, 0x0, 0x7ffe, 0xf800, 0x7f, 0xfff0, 0x7f, 0x0, 0x7ffc,
		 0xf800, 0x7f, 0xfff0, 0x3f, 0x1, 0xfffc, 0xf800, 0x3f, 0xfff8, 0x1f,
		 0x3, 0xfff8, 0xf800, 0x3f, 0xfff8, 0x1f, 0x7, 0xfff8, 0xf800, 0x7ff,
		 0xfffc, 0x7, 0xf, 0xfff0, 0xff01, 0xffff, 0xfffe, 0x3, 0x1f, 0xffe0,
		 0xffc1, 0xffff, 0xffff, 0x3, 0x3f, 0xffe0, 0xffe1, 0xffff, 0xffff, 0x0,
		 0x7f, 0xffc0, 0xfff1, 0xffff, 0xffff, 0x0, 0xff, 0xffc0, 0xfff9, 0xffff,
		 0x7fff, 0x0, 0x1ff, 0xff80, 0xffff, 0xffff, 0x3fff, 0x0, 0x3ff, 0xff80,
		 0xffff, 0xffff, 0xfff, 0x0, 0x7ff, 0xff00, 0xffff, 0xffff, 0x7ff, 0x0,
		 0xfff, 0xfe00, 0xffff, 0xffff, 0x7ff, 0x0, 0x1fff, 0xfe00, 0xffff, 0xffff,
		 0x1ff, 0x8000, 0x3fff, 0xfc00, 0xffff, 0xffff, 0x1ff, 0xe000, 0x7fff, 0xfc00,
		 0xf07f, 0xffff, 0x1ff, 0xf000, 0xffff, 0xf800, 0xf07f, 0xffff, 0x1ff, 0xfc00,
		 0xffff, 0xf801, 0xf03f, 0xffff, 0x3ff, 0xff00, 0xffff, 0xf003, 0xf03f, 0xffff,
		 0x3ff, 0xffc0, 0xffff, 0xe007, 0xf00f, 0xffff, 0x3ff, 0xffe0, 0xfffc, 0xe00f,
		 0xf, 0xc000, 0x3ff, 0xfff8, 0xfff0, 0xc01f, 0xf, 0x0, 0x300, 0xfffe,
		 0xffc0, 0xc03f, 0xff, 0x0, 0x8000, 0xffff, 0xff80, 0xc07f, 0xffff, 0xffff,
		 0xc000, 0xffff, 0xfe00, 0xc0ff, 0x3fff, 0xf800, 0xf1ff, 0xffff, 0xf800, 0xe1ff,
		 0x3ffc, 0xc000, 0xfd3f, 0xffff, 0xf000, 0x63ff, 0x3ff8, 0xe000, 0xfe3f, 0xffff,
		 0xc000, 0x67ff, 0x3ff8, 0xf800, 0xfe3f, 0xffff, 0x0, 0xefff, 0x7ff8, 0xfe00,
		 0xfe3f, 0xffff, 0x0, 0xfffc, 0xf3fd, 0xff80, 0xff3f, 0xffff, 0x0, 0xfff8,
		 0xf3ff, 0xffe3, 0xffff, 0x3fff, 0x0, 0xffe0, 0xe3ff, 0xffff, 0xffff, 0x3ff,
		 0x1, 0xff80, 0xc1ff, 0xffff, 0xffff, 0x3f, 0x1f, 0xfe00, 0xc1ff, 0xffff,
		 0xffff, 0x3, 0xff, 0xfe00, 0x1ff, 0xffff, 0x3fff, 0x0, 0xfff, 0xfe00,
		 0x3ff, 0xffff, 0x7ff, 0x0, 0xffff, 0xff00, 0x83ff, 0xffff, 0xff, 0x0,
		 0xffff, 0xff07, 0xe7ff, 0xffff, 0x1c3, 0x0, 0xffff, 0xffff, 0xffff, 0xffff,
		 0x1c0, 0x0, 0xffff, 0xffff, 0xffff, 0x3fff, 0x180, 0x0, 0xffff, 0xffff,
		 0xfff7, 0x1fff, 0xc0, 0x0, 0xffff, 0xffff, 0xffff, 0x7ff, 0xfc, 0x0,
		 0xffff, 0xffff, 0xffff, 0x1ff, 0xff, 0x0, 0xffff, 0xffff, 0xffff, 0xf07f,
		 0x1ff, 0x0, 0x0, 0xff00, 0xffff, 0xfe7f, 0xffff, 0xffff, 0x0, 0xfe00,
		 0xffff, 0xffff, 0xffff, 0xffff, 0x0, 0xf800, 0xffff, 0xffff, 0xffff, 0xffff,
		 0x0, 0xc000, 0xffff, 0xffff, 0xffff, 0xffff, 0x0, 0xe00, 0xffff, 0xffff,
		 0xffff, 0xffff, 0x0, 0xfe0, 0xffff, 0xffff, 0xffff, 0xffff, 0x0, 0xffc,
		 0xfffe, 0xffff, 0xffff, 0xffff, 0xc000, 0xfff, 0xfff8, 0xffff, 0xffe7, 0xffff,
		 0xfc00, 0x1fff, 0xffe0, 0xffff, 0xffe7, 0xffff, 0xffc0, 0xffff, 0xff80, 0xffff,
		 0x8fe7, 0xffff, 0xfffc, 0xffff, 0xff03, 0xffff, 0xfe3, 0xfffc, 0xffff, 0xffff,
		 0xfe0f, 0xfe7f, 0xfe1, 0xffc0, 0xffff, 0xffbf, 0xfe1f, 0xf83f, 0x1c60, 0xfc00,
		 0xffff, 0xff3f, 0xfc7f, 0x781f, 0x7c00, 0xe000, 0xffff, 0xfe7f, 0xf8ff, 0x381f,
		 0xfc00, 0x1, 0xffff, 0xfe7f, 0xfbff, 0x1c1f, 0xfc30, 0x7, 0xffff, 0xfcff,
		 0xffff, 0x1e7f, 0xfff8, 0xf, 0xffff, 0xf8ff, 0xffff, 0x1fff, 0xfffc, 0x3f,
		 0xffff, 0xf9ff, 0xffff, 0xffff, 0xffff, 0x7f, 0xffff, 0xf9ff, 0xffff, 0xffff,
		 0xff7f, 0xff, 0xffff, 0xf3ff, 0xffff, 0xffff, 0xff7f, 0x1ff, 0xffff, 0xf3ff,
		 0xffff, 0xffff, 0xfeff, 0x1ff, 0xffff, 0xf3ff, 0xffff, 0xffff, 0xfeff, 0x3ff,
		 0xffff, 0xf3ff, 0xffff, 0xffff, 0xfdff, 0x7ff,};
