/*
Name:       Soren Bradley, Joe Spurway
Email:      sbrad910@mtroyal.ca
Course:     COMP 2659-001
Semester:   Winter 2022
Instructor: Paul Pospisil

Project: Puals Astro Golf Adventure (Paga)

File: VIDEO.C

Purpose: Aims to replace Physbase and SetScreen, and handles interfacing with the framebuffer
*/
#include "VIDEO.H"
/**
 * getVideoBase
 * Retrieves the starting address of the frame buffer from the video base register
 *
 * @return address of the start of the frame buffer
 */
UINT32* getVideoBase()
{
    UINT8* videoBaseHighRegister = (UINT8*) HIGH_REGISTER;
    UINT8* videoBaseMidRegister = (UINT8*) MID_REGISTER;
    UINT8 highByte;
    UINT8 midByte;
    UINT32 videoBase;
    long oldSsp;

    oldSsp = on_super(0);
    highByte = *videoBaseHighRegister;
    midByte = *videoBaseMidRegister;
    off_super(oldSsp);

    videoBase = ( (UINT32) highByte << SHIFT_BY_WORD);
    videoBase |= ( (UINT32) midByte << SHIFT_BY_BYTE);

    return (UINT32*) videoBase;
}

/**
 * setVideoBase
 * sets the address of the frame buffer of the video base register to the provided address
 * @param newVideoBase The address that will become the start of the frame buffer
 */
void setVideoBase(UINT32* newVideoBase)
{
    UINT16 topMidWord;
    UINT32 videoBase = (UINT32) newVideoBase;
    long oldSsp;

    videoBase = videoBase >> SHIFT_BY_BYTE;
    topMidWord = (UINT16) videoBase;

    oldSsp = on_super(0);
    setVBAsm(topMidWord);
    off_super(oldSsp);
}