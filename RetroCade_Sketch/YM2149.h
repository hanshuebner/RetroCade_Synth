/*!
 *  @file		YM2149.h
 *  Project		YM2149 Library
 *	@brief		YM2149 Library for the ZPUino
 *	Version		1.0
 *  @author		Jack Gassett 
 *	@date		4/10/12
 *  License		GPL
 */

#ifndef LIB_YM2149_H_
#define LIB_YM2149_H_

#include <inttypes.h> 
#include <zpuino-types.h>
#include <zpuino.h>
#include "Arduino.h"


#define YM_ADDR_FREQ_A 0x00
#define YM_ADDR_FREQ_B 0x02
#define YM_ADDR_FREQ_C 0x04
#define YM_ADDR_NOISE 0x06
#define YM_ADDR_MIXER 0x07
#define YM_ADDR_LEVEL_A 0x08
#define YM_ADDR_LEVEL_B 0x09
#define YM_ADDR_LEVEL_C 0x0A
#define YM_ADDR_FREQ_E 0x0B
#define YM_ADDR_SHAPE_E 0x0D

#define YM2149BASE IO_SLOT(13)
#define YM2149REG(x) REGISTER(YM2149BASE,x)  

class YM2149
{
    static const int ym2149_note2MIDI[129];
  public:
    YM2149();
    void writeData(unsigned char address, unsigned char data);
    void setNote(byte voice, int note, boolean active);
    void setNoise(byte voice, byte freq, boolean active);
    void setVolume(byte voice, byte volume);
    void setEnvelope(byte voice, int freq, boolean active);
    void setEnvelopeCONT(boolean active);
    void setEnvelopeATT(boolean active);
    void setEnvelopeALT(boolean active);
    void setEnvelopeHOLD(boolean active);    
    void reset();
  private:
    struct YM_REG_MIXER_STRUCT{
        unsigned int EMPTY : 2;
        unsigned int NOISEC : 1; 
        unsigned int NOISEB : 1;
        unsigned int NOISEA : 1;
        unsigned int TONEC : 1; 
        unsigned int TONEB : 1;
        unsigned int TONEA : 1;
    } ;
    struct YM_REG_ENVSHAPE_STRUCT{
        unsigned int EMPTY : 4;
        unsigned int CONT : 1; 
        unsigned int ATT : 1;
        unsigned int ALT : 1;
        unsigned int HOLD : 1;      
    } ;
    struct YM_REG_LEVEL_STRUCT{
        unsigned int EMPTY : 3;
        unsigned int MODE : 1; 
        unsigned int LEVEL : 4;
    } ;
    struct ymframe {
    	unsigned char regval[14];
    };  
    YM_REG_MIXER_STRUCT YM_REG_MIXER;
    YM_REG_ENVSHAPE_STRUCT YM_REG_ENVSHAPE;
    YM_REG_LEVEL_STRUCT YM_REG_VA_LEVEL;
    YM_REG_LEVEL_STRUCT YM_REG_VB_LEVEL;
    YM_REG_LEVEL_STRUCT YM_REG_VC_LEVEL; 
};
#endif // LIB_YM2149_H_
