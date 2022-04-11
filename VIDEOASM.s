        xdef    _setVBAsm

;-- SUBROUTINE: --------------------------------------------------------
;
;   <ULONG> setVideoBase( <ULONG *> video_base )
;
;	PURPOSE:
;	* sets the video base register
;
;	PARAMETERS:
;	* <ULONG *> videobase - the new video base
;
;   NOTE:
;   * Needs to be called in supervisor mode
;

_setVBAsm:
        link    a6,#0
        move.l  #$00FF8201,a0
        move.w  8(a6),d0
        movep.w d0,(a0)

        unlk    a6
        rts

