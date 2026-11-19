/* unit_088B6E14: 0x088B6E14-0x088B6E8C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088B6A08 and unit_088B6E8C.
 *
 * Tells whether no request slot has the 16-bit keys a and b.
 *
 * NonMatching: the image keeps the original code.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    s8 b[6];
} B6;

typedef struct {
    s8 b[8];
} Addr8;

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 pad[0x11];
} Id;

/* The 0x14-byte result given to callbacks: +0x8 an argument, +0xC a
 * status byte, +0x10 a 16-bit code. */
typedef struct {
    u8 pad0[8];
    s32 unk8;
    s8 unkC;
    u8 padD[3];
    u16 unk10;
    u8 pad12[2];
} Res;

typedef void (*ResFn)(Res *);

typedef float f32;

typedef struct {
    f32 a, b, c, d;
} F4;

/* The same result copied one member at a time through float registers. */
typedef struct {
    F4 p0;
    f32 p1;
} ResF;

typedef struct {
    u8 used;
    u8 retries;
    u8 pad2[2];
    ResFn cb;
    s32 arg;
    Id id;
    s32 timer;
    u8 handle[0x318];
} Slot;

typedef struct {
    void (*fn)(void);
    s32 unk4;
    s32 unk8;
    u8 padC[0x14];
    u8 unk20;
    u8 pad21[7];
} Ent28;

typedef struct {
    u8 pad0[4];
    ResFn cb;
    s32 arg;
    u8 pad0C[0x14];
    u8 unk20;
    u8 unk21;
    u8 unk22;
} State;

typedef struct {
    Addr8 addr;
    s16 timer;
    u8 retries;
    u8 padB;
} Peer;

extern char D_09A2851C[];

/* NonMatching, 74.20 %: the original loads the two keys interleaved
 * (+0x1C6E, +0x1C72, +0x1C6F, +0x1C73), tests the first with `bne` and the
 * second with `bnel`, masking the second twice; ours computes one key at a
 * time. Tried: temporaries in both orders, swapped compares, nested ifs,
 * s32 keys, an inline 16-bit read helper, Slot members. */
s32 func_088B6E14(u16 a, u16 b) {
    s32 i;
    char *p;
    u16 x;
    u16 y;

    i = 0;
    p = D_09A2851C;
    do {
        x = (u16) (*(u8 *) (p + 0x1C6E) << 8) | *(u8 *) (p + 0x1C6F);
        y = (u16) (*(u8 *) (p + 0x1C72) << 8) | *(u8 *) (p + 0x1C73);
        if (x == a && y == b) {
            return 0;
        }
        i++;
        p += sizeof(Slot);
    } while (i < 0x80);
    return 1;
}
