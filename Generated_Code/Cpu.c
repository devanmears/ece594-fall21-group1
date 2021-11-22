/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : Cpu.c
**     Project     : ECE 594 Project_Group 1
**     Processor   : MCF51EM256CLL
**     Component   : MCF51EM256_100
**     Version     : Component 01.006, Driver 01.12, CPU db: 3.00.060
**     Datasheet   : MCF51EM256RM Revision 8 4/2010
**     Compiler    : CodeWarrior ColdFireV1 C Compiler
**     Date/Time   : 2021-11-22, 10:16, # CodeGen: 43
**     Abstract    :
**         This component "MCF51EM256_100" contains initialization of the
**         CPU and provides basic methods and events for CPU core
**         settings.
**     Settings    :
**
**     Contents    :
**         EnableInt  - void Cpu_EnableInt(void);
**         DisableInt - void Cpu_DisableInt(void);
**
**     Copyright : 1997 - 2014 Freescale Semiconductor, Inc. 
**     All Rights Reserved.
**     
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**     
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**     
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**     
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**     
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**     
**     http: www.freescale.com
**     mail: support@freescale.com
** ###################################################################*/
/*!
** @file Cpu.c
** @version 01.12
** @brief
**         This component "MCF51EM256_100" contains initialization of the
**         CPU and provides basic methods and events for CPU core
**         settings.
*/         
/*!
**  @addtogroup Cpu_module Cpu module documentation
**  @{
*/         

/* MODULE Cpu. */
#include "Input.h"
#include "TI1.h"
#include "Bit1.h"
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Events.h"
#include "Cpu.h"

/* Global variables */
volatile far word SR_reg;              /* Current CCR register */
volatile byte SR_lock;

/*Definition of global shadow variables*/
byte Shadow_PTA;


/*
** ===================================================================
**     Method      :  Cpu_VrtcInterrupt (component MCF51EM256_100)
**
**     Description :
**         This ISR services the Independent Real Time Clock interrupt to 
**         clear tamper detection flag after POR.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
ISR(Cpu_VrtcInterrupt)
{
  /* Clear the tamper interrupt flag */
  /* IRTC_CTRL: WE=0 */
  clrReg16Bits(IRTC_CTRL, 0x03U);       
  /* IRTC_CTRL: WE=1 */
  clrSetReg16Bits(IRTC_CTRL, 0x02U, 0x01U); 
  /* IRTC_CTRL: WE=3 */
  setReg16Bits(IRTC_CTRL, 0x03U);       
  /* IRTC_CTRL: WE=2 */
  clrSetReg16Bits(IRTC_CTRL, 0x01U, 0x02U); 
  /* IRTC_ISR: SAM7=0,SAM6=0,SAM5=0,SAM4=0,SAM3=0,SAM2=0,SAM1=0,SAM0=0,2HZ=0,1HZ=0,MIN=0,HR=0,DAY=0,ALM=0,STW=0,TMPR=1 */
  setReg16(IRTC_ISR, 0x01U);            
}

/*
** ===================================================================
**     Method      :  Cpu_Cpu_Interrupt (component MCF51EM256_100)
**
**     Description :
**         This ISR services an unused interrupt/exception vector.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
ISR(Cpu_Interrupt)
{
  /* This code can be changed using the CPU component property "Build Options / Unhandled int code" */
  /* asm (HALT) */
}


/*
** ===================================================================
**     Method      :  Cpu_DisableInt (component MCF51EM256_100)
**     Description :
**         Disables maskable interrupts
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void Cpu_DisableInt(void)

**      This method is implemented as macro in the header module. **
*/

/*
** ===================================================================
**     Method      :  Cpu_EnableInt (component MCF51EM256_100)
**     Description :
**         Enables maskable interrupts
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void Cpu_EnableInt(void)

**      This method is implemented as macro in the header module. **
*/

/*
** ===================================================================
**     Method      :  __initialize_hardware (component MCF51EM256_100)
**
**     Description :
**         Configure the basic system functions (timing, etc.).
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

/*** !!! Here you can place your own code using property "User data declarations" on the build options tab of the CPU component. !!! ***/


void __initialize_hardware(void)
{

  /*** !!! Here you can place your own code using property "User code before PE initialization" on the build options tab of the CPU component. !!! ***/

  /* ### MCF51EM256_100 "Cpu" init code ... */
  /*  PE initialization code after reset */
  /* Common initialization of the write once registers */
  /* SOPT1: ??=0,??=0,STOPE=0,WAITE=1,COPT=0,COPCLKS=0,COPW=0 */
  setReg8(SOPT1, 0x10U);                
  /* SPMSC1: LVDF=0,LVDACK=0,LVDIE=0,LVDRE=1,LVDSE=1,LVDE=1,BGBDS=0,BGBE=0 */
  setReg8(SPMSC1, 0x1CU);               
  /* SPMSC2: LPR=0,LPRS=0,LPWUI=0,??=0,PPDF=0,PPDACK=0,PPDE=1,PPDC=0 */
  setReg8(SPMSC2, 0x02U);               
  /* SPMSC3: LVDV=0,LVWV=0,LVWIE=0 */
  clrReg8Bits(SPMSC3, 0x38U);           
  /* Initialization of CPU registers */
  /*lint -save  -e950 Disable MISRA rule (1.1) checking. */
  asm {
    /* VBR: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,ADDRESS=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0 */
    clr.l d0
    movec d0,VBR
    /* CPUCR: ARD=0,IRD=0,IAE=0,IME=0,BWD=0,??=0,FSD=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0 */
    clr.l d0
    movec d0,CPUCR
  }
  /*lint -restore Enable MISRA rule (1.1) checking. */
  /*  System clock initialization */
  /*lint -save  -e923 Disable MISRA rule (11.3) checking. */
  if (*(unsigned char*)0x03FFU != 0xFFU) { /* Test if the device trim value is stored on the specified address */
    ICSTRM = *(unsigned char*)0x03FFU; /* Initialize ICSTRM register from a non volatile memory */
    ICSSC = (unsigned char)((*(unsigned char*)0x03FEU) & (unsigned char)0x01U); /* Initialize ICSSC register from a non volatile memory */
  }
  /*lint -restore Enable MISRA rule (11.3) checking. */
  /* CCSCTRL: SEL=0 */
  clrReg8Bits(CCSCTRL, 0x01U);         /* Select XOSC2 clock input */ 
  /* ICSC1: CLKS=0,RDIV=0,IREFS=1,IRCLKEN=1,IREFSTEN=0 */
  setReg8(ICSC1, 0x06U);               /* Initialization of the ICS control register 1 */ 
  /* ICSC2: BDIV=1,RANGE=0,HGO=0,LP=0,EREFS=0,ERCLKEN=0,EREFSTEN=0 */
  setReg8(ICSC2, 0x40U);               /* Initialization of the ICS control register 2 */ 
  while(ICSSC_IREFST == 0U) {          /* Wait until the source of reference clock is internal clock */
  }
  /* ICSSC: DRST_DRS=0,DMX32=0 */
  clrReg8Bits(ICSSC, 0xE0U);           /* Initialization of the ICS status and control */ 
  while((ICSSC & 0xC0U) != 0x00U) {    /* Wait until the FLL switches to Low range DCO mode */
  }

  /*** End of PE initialization code after reset ***/

  /*** !!! Here you can place your own code using property "User code after PE initialization" on the build options tab of the CPU component. !!! ***/

}

/*
** ===================================================================
**     Method      :  PE_low_level_init (component MCF51EM256_100)
**
**     Description :
**         Initializes components and provides common register 
**         initialization. The method is called automatically as a part 
**         of the application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void PE_low_level_init(void)
{
  /* SCGC1: ADC4=1,ADC3=1,ADC2=1,ADC1=1,IIC=1,SCI3=1,SCI2=1,SCI1=1 */
  setReg8(SCGC1, 0xFFU);                
  /* SCGC2: CMP2=1,CMP1=1,VREF=1,IRQ=1,LCD=1,SPI3=1,SPI2=1,SPI1=1 */
  setReg8(SCGC2, 0xFFU);                
  /* SCGC3: KBI2=1,KBI1=1,PTF=1,PTE=1,PTD=1,PTC=1,PTB=1,PTA=1 */
  setReg8(SCGC3, 0xFFU);                
  /* SCGC4: ??=1,PM=1,CRC=1,TPM=1,PDB=1,MTIM3=1,MTIM2=1,MTIM1=1 */
  setReg8(SCGC4, 0xFFU);                
  /* SCGC5: ??=1,??=1,??=1,??=1,??=1,??=1,FTSR2=1,FTSR1=1 */
  setReg8(SCGC5, 0xFFU);                
  /* Common initialization of the CPU registers */
  /* PTBPE: PTBPE7=0,PTBPE6=0,PTBPE3=0,PTBPE1=0 */
  clrReg8Bits(PTBPE, 0xCAU);            
  /* PTBDD: PTBDD7=0,PTBDD6=0,PTBDD3=0,PTBDD1=0 */
  clrReg8Bits(PTBDD, 0xCAU);            
  /* PTBPF1: B7=1,B6=1 */
  clrSetReg8Bits(PTBPF1, 0xA0U, 0x50U); 
  /* PTBPF2: B3=1,B1=1 */
  clrSetReg8Bits(PTBPF2, 0x88U, 0x44U); 
  /* PTAD: PTAD5=0 */
  clrReg8Bits(PTAD, 0x20U);             
  /* PTAPE: PTAPE5=0 */
  clrReg8Bits(PTAPE, 0x20U);            
  /* PTADD: PTADD5=1 */
  setReg8Bits(PTADD, 0x20U);            
  /* PTAPF1: A5=0 */
  clrReg8Bits(PTAPF1, 0x0CU);           
  /* PTASE: PTASE7=0,PTASE6=0,PTASE5=0,PTASE4=0,PTASE3=0,PTASE2=0,PTASE1=0,PTASE0=0 */
  setReg8(PTASE, 0x00U);                
  /* PTBSE: PTBSE7=0,PTBSE6=0,PTBSE5=0,PTBSE4=0,PTBSE3=0,PTBSE2=0,PTBSE1=0,PTBSE0=0 */
  setReg8(PTBSE, 0x00U);                
  /* PTCSE: PTCSE7=0,PTCSE6=0,PTCSE5=0,PTCSE4=0,PTCSE3=0,PTCSE2=0,PTCSE1=0,PTCSE0=0 */
  setReg8(PTCSE, 0x00U);                
  /* PTDSE: PTDSE7=0,PTDSE6=0,PTDSE5=0,PTDSE4=0,PTDSE3=0,PTDSE2=0,PTDSE1=0,PTDSE0=0 */
  setReg8(PTDSE, 0x00U);                
  /* PTESE: PTESE7=0,PTESE6=0,PTESE5=0,PTESE4=0,PTESE3=0,PTESE2=0,PTESE1=0,PTESE0=0 */
  setReg8(PTESE, 0x00U);                
  /* PTFSE: PTFSE7=0,PTFSE6=0,PTFSE5=0,PTFSE4=0,PTFSE3=0,PTFSE2=0,PTFSE1=0,PTFSE0=0 */
  setReg8(PTFSE, 0x00U);                
  /* PTADS: PTADS7=1,PTADS6=1,PTADS5=1,PTADS4=1,PTADS3=1,PTADS2=1,PTADS1=1,PTADS0=1 */
  setReg8(PTADS, 0xFFU);                
  /* PTBDS: PTBDS7=1,PTBDS6=1,PTBDS5=1,PTBDS4=1,PTBDS3=1,PTBDS2=1,PTBDS1=1,PTBDS0=1 */
  setReg8(PTBDS, 0xFFU);                
  /* PTCDS: PTCDS7=1,PTCDS6=1,PTCDS5=1,PTCDS4=1,PTCDS3=1,PTCDS2=1,PTCDS1=1,PTCDS0=1 */
  setReg8(PTCDS, 0xFFU);                
  /* PTDDS: PTDDS7=1,PTDDS6=1,PTDDS5=1,PTDDS4=1,PTDDS3=1,PTDDS2=1,PTDDS1=1,PTDDS0=1 */
  setReg8(PTDDS, 0xFFU);                
  /* PTEDS: PTEDS7=1,PTEDS6=1,PTEDS5=1,PTEDS4=1,PTEDS3=1,PTEDS2=1,PTEDS1=1,PTEDS0=1 */
  setReg8(PTEDS, 0xFFU);                
  /* PTFDS: PTFDS7=1,PTFDS6=1,PTFDS5=1,PTFDS4=1,PTFDS3=1,PTFDS2=1,PTFDS1=1,PTFDS0=1 */
  setReg8(PTFDS, 0xFFU);                
  /* PTAIFE: PTAIFE7=0,PTAIFE6=0,PTAIFE5=0,PTAIFE4=0,PTAIFE3=0,PTAIFE2=0,PTAIFE1=0,PTAIFE0=0 */
  setReg8(PTAIFE, 0x00U);               
  /* PTBIFE: PTBIFE7=0,PTBIFE6=0,PTBIFE5=0,PTBIFE4=0,PTBIFE3=0,PTBIFE2=0,PTBIFE1=0,PTBIFE0=0 */
  setReg8(PTBIFE, 0x00U);               
  /* PTCIFE: PTCIFE7=0,PTCIFE6=0,PTCIFE5=0,PTCIFE4=0,PTCIFE3=0,PTCIFE1=0,PTCIFE0=0 */
  clrReg8Bits(PTCIFE, 0xFBU);           
  /* PTDIFE: PTDIFE7=0,PTDIFE6=0,PTDIFE5=0,PTDIFE4=0,PTDIFE3=0,PTDIFE2=0,PTDIFE1=0,PTDIFE0=0 */
  setReg8(PTDIFE, 0x00U);               
  /* PTEIFE: PTEIFE7=0,PTEIFE6=0,PTEIFE5=0,PTEIFE4=0,PTEIFE3=0,PTEIFE2=0,PTEIFE1=0,PTEIFE0=0 */
  setReg8(PTEIFE, 0x00U);               
  /* PTFIFE: PTFIFE7=0,PTFIFE6=0,PTFIFE5=0,PTFIFE4=0,PTFIFE3=0,PTFIFE2=0,PTFIFE1=0,PTFIFE0=0 */
  setReg8(PTFIFE, 0x00U);               
  /* PTCPF2: C2=0 */
  clrReg8Bits(PTCPF2, 0x30U);           
  /* SIMCO: CS=0 */
  clrReg8Bits(SIMCO, 0x0FU);            
  /* IRTC_CTRL: WE=0 */
  clrReg16Bits(IRTC_CTRL, 0x03U);      /* Disable IRTC module protection */ 
  /* IRTC_CTRL: WE=1 */
  clrSetReg16Bits(IRTC_CTRL, 0x02U, 0x01U); 
  /* IRTC_CTRL: WE=3 */
  setReg16Bits(IRTC_CTRL, 0x03U);       
  /* IRTC_CTRL: WE=2 */
  clrSetReg16Bits(IRTC_CTRL, 0x01U, 0x02U); 
  /* IRTC_IER: SAM7=0,SAM6=0,SAM5=0,SAM4=0,SAM3=0,SAM2=0,SAM1=0,SAM0=0,2HZ=0,1HZ=0,MIN=0,HR=0,DAY=0,ALM=0,STW=0,TMPR=0 */
  setReg16(IRTC_IER, 0x00U);           /* Disable tamper detect interrupt */ 
  /* ### Shared modules init code ... */
  Input_Init();
  /* ### TimerInt "TI1" init code ... */
  TI1_Init();
  /* ### BitIO "Bit1" init code ... */
  Shadow_PTA &= 0xDFU;                 /* Initialize pin shadow variable bit */
  /* INTC_WCR: ENB=1,??=0,??=0,??=0,??=0,MASK=0 */
  setReg8(INTC_WCR, 0x80U);             
  SR_lock = 0x00;
  /* Set initial interrupt priority 0 */
  asm {
    move.w SR,D0;
    andi.l #0xF8FF,D0;
    move.w D0,SR;
  }
}

/* Initialization of the CPU registers in FLASH */
/* NV1PROT: FPS6=1,FPS5=1,FPS4=1,FPS3=1,FPS2=1,FPS1=1,FPS0=1,FPOPEN=1 */
static unsigned char NV1PROT_INIT @0x0000040D = 0xFFU;
/* NV2PROT: FPS6=1,FPS5=1,FPS4=1,FPS3=1,FPS2=1,FPS1=1,FPS0=1,FPOPEN=1 */
static unsigned char NV2PROT_INIT @0x0002040D = 0xFFU;
/* NV1OPT: KEYEN1=0,KEYEN0=1,??=1,??=1,??=1,??=1,SEC1=1,SEC0=1 */
static unsigned char NV1OPT_INIT @0x0000040F = 0x7FU;
/* NV2OPT: KEYEN1=0,KEYEN0=1,??=1,??=1,??=1,??=1,SEC1=1,SEC0=1 */
static unsigned char NV2OPT_INIT @0x0002040F = 0x7FU;
/* END Cpu. */

/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.09]
**     for the Freescale ColdFireV1 series of microcontrollers.
**
** ###################################################################
*/
