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
    char unk1C[4];
    u8 unk20;
    u8 unk21;
    u8 count;
    u8 self;
    char addr[4][0x10];
    char unk64[4];
    u8 unk68[4];
    char unk6C[0xC];
    float unk78;
    char unk7C[0x14];
    s32 unk90;
    char unk94[0x10];
    s32 unkA4;
    s32 unkA8;
    s32 unkAC[4];
    u32 unkBC[4];
    char unkCC[0xC];
    char unkD8[2];
    s16 unkDA;
    char unkDC[4];
    float unkE0[4];
    char unkF0[0x20];
    u8 unk110[4];
    u8 unk114[4];
    u16 unk118[4];
    char unk120[0x14];
    float unk134;
    char unk138[8];
    s32 (*unk140)(s32, s32, s32);
    s32 unk144;
    void (*unk148)(s32, s32);
    s32 unk14C;
    void (*unk150)(s32, s32);
    s32 unk154;
} Session;

typedef struct {
    s32 len;
    s16 cap;
    char *buf;
} RecvBuf;

typedef struct {
    s32 pos;
    s32 cap;
    char *buf;
} Store;

typedef struct {
    u8 len;
    u8 type;
    u8 from;
    u8 seq;
    u16 n;
} Header;

typedef struct {
    u8 len;
    u8 type;
    u8 from;
    u8 seq;
    u16 n;
    char data[0xFA];
} Packet;

extern RecvBuf D_09A11ED8;
extern Store D_09A1D590;
extern Packet D_09A11F70;
extern Peer D_09A11EF0[4];
extern SendBuf D_09A11EE4;

#endif
