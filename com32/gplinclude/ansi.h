/* ----------------------------------------------------------------------- *
 *
 *   Copyright 2009 Erwan Velu - All Rights Reserved
 *
 *   Permission is hereby granted, free of charge, to any person
 *   obtaining a copy of this software and associated documentation
 *   files (the "Software"), to deal in the Software without
 *   restriction, including without limitation the rights to use,
 *   copy, modify, merge, publish, distribute, sublicense, and/or
 *   sell copies of the Software, and to permit persons to whom
 *   the Software is furnished to do so, subject to the following
 *   conditions:
 *
 *   The above copyright notice and this permission notice shall
 *   be included in all copies or substantial portions of the Software.
 *
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 *   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 *   OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 *   NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 *   HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 *   WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 *   FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 *   OTHER DEALINGS IN THE SOFTWARE.
 *
 * -----------------------------------------------------------------------
 */

#ifndef DEFINE_LIB_ANSI_H
#define DEFINE_LIB_ANSI_H

#define CSI "\e["

void display_cursor(bool status);
void clear_end_of_line(void);
void move_cursor_left(int count);
void move_cursor_right(int count);
void clear_line(void);
void clear_beginning_of_line(void);
void move_cursor_to_column(int count);
void move_cursor_to_next_line();
void disable_utf8();
void set_g1_special_char();
void set_us_g0_charset();
void clear_entire_screen();
void set_cursor_blink(bool status);
void move_cursor_to_next_line(void);
void disable_utf8(void);
void set_g1_special_char(void);
void set_us_g0_charset(void);
void clear_entire_screen(void);

static inline void beep(void)
{
	fputs("\007", stdout);
}

/* Print a string */
void csprint(const char *, const char);

/* Print one character, one or more times */
void cprint(const char, const char, unsigned int);

/* Print one character, once */
static inline void putch(const char x, char attr)
{
	cprint(x, attr, 1);
}

/*
 * cls - clear and initialize the entire screen
 *
 * Note: when initializing xterm, one has to specify that
 * G1 points to the alternate character set (this is not true
 * by default). Without the initial printf "\033)0", line drawing
 * characters won't be displayed.
 */
static inline void cls(void)
{
	fputs("\033e\033%@\033)0\033(B\1#0\033[?25l\033[2J", stdout);
}

static inline void cursoroff(void)
{
  display_cursor(false);
}

static inline void cursoron(void)
{
  display_cursor(true);
}

/* Scroll up display screen by one line */
static inline void scrollup(void)
{
	printf(CSI "S");
}

static inline void gotoxy(const char row, const char col)
{
	printf(CSI "%d;%dH", row + 1, col + 1);
}

#endif
