#pragma once

// Datel / JMS / C-LAB double-speed interface

#define MIDI_CONTROL  (*((volatile unsigned char *)0xde04))  // write-only
#define MIDI_STATUS   (*((volatile unsigned char *)0xde06))  // read-only
#define MIDI_TX       (*((volatile unsigned char *)0xde05))  // write-only
#define MIDI_RX       (*((volatile unsigned char *)0xde07))  // read-only

// Status bits (typical ACIA-style; adjust if needed):
// bit 0: RX data available
// bit 1: TX empty
#define MIDI_RX_READY   (MIDI_STATUS & 0x01)
#define MIDI_TX_EMPTY   (MIDI_STATUS & 0x02)

// Keep the old macro names, but map them to Datel

#define VOUT        { /* no direction control on Datel */ }
#define VIN         { /* no direction control on Datel */ }

#define VW(x)       (MIDI_TX = (x))
#define VR          (MIDI_RX)

#define VCMD(cmd)   \
    do {            \
        VW(0xfd);   \
        VW(cmd);    \
    } while (0)

#define VRESET      VCMD(0)
