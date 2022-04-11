/*
Name:       Soren Bradley, Joe Spurway
Email:      sbrad910@mtroyal.ca
Course:     COMP 2659-001
Semester:   Winter 2022
Instructor: Paul Pospisil

Project: Puals Astro Golf Adventure (Paga)

File: RASTER.C

Purpose: Supports screen drawing operations with no OS support. 
			plotting is performed directly on the frame buffer.
			conditions - screen boundaries.
*/
#include "RASTER.H"
/**
 * clean_screan 
 * complete clears the screen
 * @param base
 */
void clean_screen(UINT32* base){
    clear_scr_asm(base);
}
/**
 * print_screen
 * prints a screen sized bitmap to the screenss
 * @param base
 * @param bitmap
 */
void print_screen(UINT8* base, UINT32* bitmap) {
    print_scr_asm(base,bitmap);
}
/**
 * @brief plot_bitmap_8
 * 			plots a 8 bit bitmap of known height at postion [x,y] 
 * 
 * @param base   - primary screen buffer
 * @param x      - x coordinate
 * @param y      - y corrdinate
 * @param bitmap - pointer to a bitmap array 
 * @param height - height of the img
 */
void plot_bitmap_8(UINT8 * base, int x, int y, const UINT8 * bitmap, UINT16 height) 
{
	UINT16 offset = (SCREEN_BYTES * y) + (x >> SHIFT_FOR_BYTE_SIZE);
	UINT16 r_off, l_off, w_val;
	UINT16 l_shift = (7 - (x & 7));
	UINT16 r_shift = (x & 7);	
	int i;
	for (i = 0; i < height; i++) {
		w_val = bitmap[i];
		l_off = w_val << l_shift + 1;
		r_off = w_val >> r_shift;
		if (r_off == w_val) {
			*(base + offset + SCREEN_BYTES * i) |= w_val;
		} else {
			*(base + offset + SCREEN_BYTES * i) |= r_off;
			*(base + offset + SCREEN_BYTES * i + 1) |= l_off;

		}
	}

}
/**
 * clear_bitmap_8 
 * clears 8 sized bitmap 
 * @param base
 * @param x
 * @param y
 * @param height
 */
void clear_bitmap_8(UINT8 * base, int x, int y, UINT16 height) 
{
	UINT16 offset = (SCREEN_BYTES * y) + (x >> SHIFT_FOR_BYTE_SIZE);
	UINT16 r_off, l_off, w_val;
	UINT16 l_shift = (7 - (x & 7));
	UINT16 r_shift = (x & 7);	
	int i;
	for (i = 0; i < height; i++) {
		w_val = 0x00;
		l_off = w_val << l_shift + 1;
		r_off = w_val >> r_shift;
		if (r_off == w_val) {
			*(base + offset + SCREEN_BYTES * i) = w_val;
		} else {
			*(base + offset + SCREEN_BYTES * i) = r_off;
			*(base + offset + SCREEN_BYTES * i + 1) = l_off;
		}
	}
}
/**
 * @brief plot_bitmap_16
 * 			plots a 16 bit bitmap of known height at postion [x,y] 
 * 
 * @param base   - primary screen buffer
 * @param x      - x coordinate
 * @param y      - y corrdinate
 * @param bitmap - pointer to a bitmap array 
 * @param height - height of the img
 */
void plot_bitmap_16(UINT16 * base, int x, int y, const UINT16 * bitmap, UINT16 height) 
{
	UINT16 offset = (SCREEN_WORDS * y) + (x >> SHIFT_FOR_WORD_SIZE);
	UINT16 r_off, l_off, w_val;
	UINT16 l_shift = (15 - (x & 15));
	UINT16 r_shift = (x & 15);	
	int i;
	for (i = 0; i < height; i++) {
		w_val = bitmap[i];
		l_off = w_val << l_shift + 1;
		r_off = w_val >> r_shift;
		if (r_off == w_val) {
			*(base + offset + SCREEN_WORDS * i) |= w_val;
		} else {
			*(base + offset + SCREEN_WORDS * i) |= r_off;
			*(base + offset + SCREEN_WORDS * i + 1) |= l_off;

		}
	}
}
/**
 * @brief plot_bitmap_16_unsafe
 * 			plots a 16 bit bitmap of known height at postion [x,y] plotting over any other bitmaps
 * 
 * @param base   - primary screen buffer
 * @param x      - x coordinate
 * @param y      - y corrdinate
 * @param bitmap - pointer to a bitmap array 
 * @param height - height of the img
 */
void plot_bitmap_16_unsafe(UINT16 * base, int x, int y, const UINT16 * bitmap, UINT16 height) 
{
	UINT16 offset = (SCREEN_WORDS * y) + (x >> SHIFT_FOR_WORD_SIZE);
	UINT16 r_off, l_off, w_val;
	UINT16 l_shift = (15 - (x & 15));
	UINT16 r_shift = (x & 15);	
	int i;
	for (i = 0; i < height; i++) {
		w_val = bitmap[i];
		l_off = w_val << l_shift + 1;
		r_off = w_val >> r_shift;
		if (r_off == w_val) {
			*(base + offset + SCREEN_WORDS * i) = w_val;
		} else {
			*(base + offset + SCREEN_WORDS * i) = r_off;
			*(base + offset + SCREEN_WORDS * i + 1) = l_off;

		}
	}
}
/**
 * @brief plot_bitmap_32
 * 			plots a 32 bit bitmap of known height at postion [x,y] 
 * 
 * @param base   - primary screen buffer
 * @param x      - x coordinate
 * @param y      - y corrdinate
 * @param bitmap - pointer to a bitmap array 
 * @param height - height of the img
 */
void plot_bitmap_32(UINT32* base, int x, int y, UINT32* bitmap, UINT16 height) {
	UINT16 offset = (SCREEN_LONGS * y) + (x >> SHIFT_FOR_LONGWORD_SIZE);
	UINT32  w_val;
	UINT16 l_shift = (31 - (x & 31));
	UINT16 r_shift = (x & 31);	
	int i;
	for (i = 0; i < height; i++) {
		w_val = bitmap[i];
		/**printf("r_shift value = %u x = l_shift values = %u  %d y = %d\n", r_shift, l_shift, x, y );
		 **/
		if (r_shift == 31) {
			*(base + offset + SCREEN_LONGS * i) |= w_val;
		} else {
			*(base + offset + SCREEN_LONGS * i) |= w_val >> r_shift;
			*(base + offset + SCREEN_LONGS * i + 1) |=  w_val << l_shift;

		}
	}
}
/**
 * plot_text 
 * plots an array of letter bitmaps starting at a x and y positions
 * @param base
 * @param x
 * @param y
 * @param bitmap
 * @param num_letters
 */
void plot_text(UINT8 * base, int x, int y, const UINT8 ** bitmap, UINT8 num_letters) 
{
	int j;
	for (j = 0; j< num_letters; j++) {
		plot_bitmap_8(base,x,y, (const UINT8*) &(bitmap + 2 * j), 8);
		x += 8;
	}
}
/**
 * plot_number
 * plots a single number at an x and y position based on the input number
 * @param base
 * @param x
 * @param y
 * @param bitmap
 * @param num
 */
void plot_number(UINT8 * base, int x, int y, const UINT8** bitmap, UINT8 num) 
{
    plot_bitmap_8(base,x,y,(const UINT8*) &(bitmap + 2 * num), 8);

}
