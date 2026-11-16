/* Per-peer table at 0x09A11EF0 and send buffer at 0x09A11EE4, used by the
 * functions of 0x088A73B8-0x088A7DC0. Layout from the code; names are
 * descriptive, not the original ones. */

#ifndef UNK_PEER_H
#define UNK_PEER_H

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct {
    s32 state;
    float unk4;
    float unk8;
    char addr[0x10];
    s32 unk1C;
} Peer;

typedef struct {
    s32 pos;
    s32 cap;
    char *buf;
} SendBuf;

typedef struct {
    char unk0[8];
    s32 unk8[4];
    s32 unk18;
    char unk1C[6];
    u8 count;
    u8 self;
    char addr[4][0x10];
    char unk64[0x14];
    float unk78;
    char unk7C[0x30];
    s32 unkAC[4];
    u32 unkBC[4];
    char unkCC[0x48];
    u8 unk114[4];
    u16 unk118[4];
} Session;

extern Peer D_09A11EF0[4];
extern SendBuf D_09A11EE4;

#endif
