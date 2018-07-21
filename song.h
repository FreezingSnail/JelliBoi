#ifndef SONG_H
#define SONG_H

#define Song const uint8_t PROGMEM

Song music[] = {
0x0b,      // Number of tracks
0x00, 0x00,   // Address of track 0
0x18, 0x00,   // Address of track 1
0x19, 0x00,   // Address of track 2
0x1a, 0x00,   // Address of track 3
0x20, 0x00,   // Address of track 4
0x2a, 0x00,   // Address of track 5
0x30, 0x00,   // Address of track 6
0x3d, 0x00,   // Address of track 7
0x47, 0x00,   // Address of track 8
0x54, 0x00,   // Address of track 9
0x61, 0x00,   // Address of track 10
0x00,     // Channel 0 entry track
0x01,     // Channel 1 entry track
0x02,     // Channel 2 entry track
0x03,     // Channel 3 entry track
//"Track channel 0"
0x40, 100,    // FX: SET VOLUME: volume = 100
0x9D, 24,   // FX: SET TEMPO: tempo = 24
0xFC, 6,    // GOTO track 6
0xFC, 8,    // GOTO track 8
0xFC, 6,    // GOTO track 6
0xFC, 8,    // GOTO track 8
0xFC, 10,   // GOTO track 10
0xFC, 6,    // GOTO track 6
0xFD, 1, 9,   // REPEAT: count = 1 + 1 / track = 9
0xFC, 8,    // GOTO track 8
0xFC, 10,   // GOTO track 10
0x9F,     // FX: STOP CURRENT CHANNEL
//"Track channel 1"
0x9F,     // FX: STOP CURRENT CHANNEL
//"Track channel 2"
0x9F,     // FX: STOP CURRENT CHANNEL
//"Track channel 3"
0x40, 1,    // FX: SET VOLUME: volume = 1
0xFD, 9, 7,   // REPEAT: count = 9 + 1 / track = 7
0x9F,     // FX: STOP CURRENT CHANNEL
//"Track shake"
0x49, 4 + 0,    // FX: RETRIG NOISE: point = 1 (*4) / speed = 0 (fastest)
0x40, 32,   // FX: SET VOLUME: volume = 32
0x41, -8,   // FX: VOLUME SLIDE ON: steps = -8
0x9F + 4,   // DELAY: ticks = 4
0x4A,     // FX: RETRIG: off
0x43,     // FX: VOLUME SLIDE OFF
0xFE,     // RETURN
//"Track tick"
0x40, 32,   // FX: SET VOLUME: volume = 32
0x9F + 1,   // DELAY: ticks = 1
0x40, 0,    // FX: SET VOLUME: volume = 0
0xFE,     // RETURN
//"Track drum"
0x00 + 1,   // NOTE ON: note = 1
0x9F + 3,   // DELAY: ticks = 3
0x00 + 0,   // NOTE ON: note = 0
0x9F + 5,   // DELAY: ticks = 5
0x00 + 3,   // NOTE ON: note = 3
0x9F + 3,   // DELAY: ticks = 3
0x00 + 0,   // NOTE ON: note = 0
0x9F + 5,   // DELAY: ticks = 5
0x00 + 5,   // NOTE ON: note = 5
0x9F + 3,   // DELAY: ticks = 3
0x00 + 0,   // NOTE ON: note = 0
0x9F + 5,   // DELAY: ticks = 5
0xFE,     // RETURN
//"Track drum2"
0xFC, 4,    // GOTO track 4
0x9F + 4,   // DELAY: ticks = 4
0xFC, 5,    // GOTO track 5
0x9F + 6,   // DELAY: ticks = 6
0xFC, 4,    // GOTO track 4
0x9F + 5,   // DELAY: ticks = 5
0xFE,     // RETURN
//"Track Track 3"
0x00 + 13,    // NOTE ON: note = 13
0x9F + 3,   // DELAY: ticks = 3
0x00 + 0,   // NOTE ON: note = 0
0x9F + 5,   // DELAY: ticks = 5
0x00 + 15,    // NOTE ON: note = 15
0x9F + 3,   // DELAY: ticks = 3
0x00 + 0,   // NOTE ON: note = 0
0x9F + 5,   // DELAY: ticks = 5
0x00 + 17,    // NOTE ON: note = 17
0x9F + 3,   // DELAY: ticks = 3
0x00 + 0,   // NOTE ON: note = 0
0x9F + 5,   // DELAY: ticks = 5
0xFE,     // RETURN
//"Track Track 4"
0x00 + 17,    // NOTE ON: note = 17
0x9F + 3,   // DELAY: ticks = 3
0x00 + 0,   // NOTE ON: note = 0
0x9F + 5,   // DELAY: ticks = 5
0x00 + 15,    // NOTE ON: note = 15
0x9F + 3,   // DELAY: ticks = 3
0x00 + 0,   // NOTE ON: note = 0
0x9F + 5,   // DELAY: ticks = 5
0x00 + 13,    // NOTE ON: note = 13
0x9F + 3,   // DELAY: ticks = 3
0x00 + 0,   // NOTE ON: note = 0
0x9F + 5,   // DELAY: ticks = 5
0xFE,     // RETURN
//"Track Track 5"
0x00 + 29,    // NOTE ON: note = 29
0x9F + 3,   // DELAY: ticks = 3
0x00 + 0,   // NOTE ON: note = 0
0x9F + 5,   // DELAY: ticks = 5
0x00 + 27,    // NOTE ON: note = 27
0x9F + 3,   // DELAY: ticks = 3
0x00 + 0,   // NOTE ON: note = 0
0x9F + 5,   // DELAY: ticks = 5
0x00 + 25,    // NOTE ON: note = 25
0x9F + 3,   // DELAY: ticks = 3
0x00 + 0,   // NOTE ON: note = 0
0x9F + 5,   // DELAY: ticks = 5
0xFE,     // RETURN

};



#endif
