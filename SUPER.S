; Adapted from super lab

	xdef	_on_super
	xdef	_off_super

;-- SUBROUTINE: --------------------------------------------------------
;
;   LONG on_super( LONG ssp )
;
;	PURPOSE:
;	* turns on supervisor mode, and returns old supervisor mode stack pointer
;
;	PARAMETERS:
;	* <LONG> ssp - providing zero will return the ssp before changing it
;
;

_on_super:
	move.l	d0,-(sp)
	clr.l	-(sp)
	move.w 	#$20,-(sp)
	trap	#1
	addq.l	#6,sp
	move.l	d0,old_ssp
	move.l	(sp)+,d0
	rts

;-- SUBROUTINE: --------------------------------------------------------
;
;   LONG off_super( LONG oldssp )
;
;	PURPOSE:
;	* turns off supervisor mode, and sets the ssp to the given value
;
;	PARAMETERS:
;	* <LONG> oldssp - the value the ssp will be set to
;
;

_off_super:
	move.l 	d0,-(sp)
	move.l	(old_ssp),-(sp)
	move.w	#$20,-(sp)
	trap	#1
	addq.l 	#6,sp
	move.l 	(sp)+,d0
	rts

old_ssp:	ds.l	1

