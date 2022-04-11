			xdef		_clear_scr_asm
			xdef		_print_scr_asm

SCREEN_BYTES		equ		32000

;-- SUBROUTINE: --------------------------------------------------------
;
;   void clear_scr_asm( ULONG* )
;
;	PURPOSE:
;	* Clears the screen.
;
;	PARAMETERS:
;	* <ULONG * > base - The address of the video base.
;
;
;   RETRIEVED FROM AN EXAMPLE PROJECT:
;   * Noting the Mark is an assembly god
;   * Previous attempts at clearing functions where quite slow so I opted to implment Marks work

CS_BASE    equ     64      ; offset from SP, not A6

_clear_scr_asm: movem.l     d0-7/a0-6,-(sp)
                lea         zeros,a0
                movem.l     (a0)+,d1-7/a1-6
                movea.l     CS_BASE(sp),a0
                adda.l      #SCREEN_BYTES,a0
                move.w      #614,d0
fill_loop:      movem.l     d1-7/a1-6,-(a0)
                dbra        d0,fill_loop
                movem.l     d1-5,-(a0)
                movem.l     (sp)+,d0-7/a0-6
                rts

;-- SUBROUTINE: --------------------------------------------------------
;
;   void print_src_asm( UBYTE*, UDWORD* )
;
;	PURPOSE:
;	* Prints a screen-sized bitmap.
;
;	PARAMETERS:
;	* <UBYTE * > base - The address of a video base.
;	* <UBYTE * > screen - The address of a screen sized bitmap to
;	print.
;
;

PS_BASE 		equ		8
PS_SCREEN 		equ		12

_print_scr_asm:		link		a6,#0
			movem.l		d0/a0-1,-(sp)
			movea.l		PS_BASE(a6),a0
			movea.l		PS_SCREEN(a6),a1
			move.l		#0,d0

.loop			cmp		#SCREEN_BYTES/4,d0
			bcc		.done
			move.l 		(a1)+,(a0)+
			addq.l 		#1,d0
			bra		.loop

.done			movem.l		(sp)+,d0/a0-1
			unlk		a6
			rts

zeros:		ds.l		13
