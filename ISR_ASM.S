MFP_ISRB    equ         $FFFA11


            xdef        _vblisr
            xdef        _ikbdisr
            xdef        _setipl
            
            xref        _handle_sync
            xref        _read_key
            
            

;-- SUBROUTINE: --------------------------------------------------------
;
;   void vblisr()
;
;	PURPOSE:
;	* Replaces the vertical blank isr with a jsr to the handle sync function
;       in the game
;

_vblisr:    movem.l     d0-d2/a0-a2,-(sp)
            jsr         _handle_sync
            movem.l     (sp)+,d0-d2/a0-a2
            rte

;-- SUBROUTINE: --------------------------------------------------------
;
;   void ikbdisr()
;
;	PURPOSE:
;	* Replaces the ikbd isr with custom function, this function is contained
;      in ikbd.c and handles the reading of the keymaps from the ikbd and mouse input
;       via a FSM.
;   * Handles clearing the isrb register on the MFP to indicate that the interupt is over
;

_ikbdisr:   movem.l     d0-d2/a0-a2,-(sp)
            jsr         _read_key
            movem.l     (sp)+,d0-d2/a0-a2
            bclr.b      #6,MFP_ISRB         ;clear the one bit to it that the isr is done
            rte
            
;-- SUBROUTINE: --------------------------------------------------------
;
;   WORD setipl( WORD mask )
;
;	PURPOSE:
;	* changes the IPL to the provided value and will return the old IPL
;
;	PARAMETERS:
;	* <WORD> mask - The value the IPL will be set too
;
;   NOTE:
;   * This function does nothing to check if it is being called from supervisor mode
;       this could lead to problems if it is called in user mode. BIG PROBLEMS RUN IN USER MODE
;


_setipl:    move.w  sr,d0
            move.w  d0,-(sp)

            lsr.w   #8,d0
            and.w   #$0007,d0
            
            andi.w  #$F8FF,(sp)
            move.w  d1,-(sp)
            move.w  8(sp),d1
            lsl.w   #8,d1
            and.w   #$0700,d1
            or.w    d1,2(sp)
            move.w  (sp)+,d1

            rte




