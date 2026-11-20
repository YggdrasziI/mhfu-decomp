/* unit_088B6E8C: 0x088B6E8C-0x088B70E8 (ULES01213)
 *
 * Bounds (hypothesis): 4 functions between unit_088B6E14 (NonMatching) and unit_088B70E8
 *
 * (NonMatching).
 * Request slot timeouts (retry or fail with 0x8001), the 0xB 0x28-byte
 * timer entries at D_09A2851C + 0x1BA60, and the result of a state record.
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
extern void memset(void *, s32, s32);
extern s32 func_088B012C(void *);

void func_088B6E8C(void) {
    Res r;
    s32 i;
    char *p;

    i = 0;
    p = D_09A2851C;
    do {
        if (*(u8 *) (p + 0x1C60) != 0) {
            if (--*(s32 *) (p + 0x1C80) < 0) {
                *(s32 *) (p + 0x1C80) = 0x96;
                if (*(u8 *) (p + 0x1C61) != 0) {
                    (*(u8 *) (p + 0x1C61))--;
                    *(u8 *) (p + 0x1C99) = 1;
                    func_088B012C(p + 0x1C84);
                } else {
                    memset(&r, 0, sizeof(r));
                    *(u8 *) (p + 0x1C60) = 0;
                    r.unkC = -1;
                    r.unk10 = 0x8001;
                    if (*(ResFn *) (p + 0x1C64) != 0) {
                        r.unk8 = *(s32 *) (p + 0x1C68);
                        (*(ResFn *) (p + 0x1C64))(&r);
                    }
                    memset(p + 0x1C60, 0, sizeof(Slot));
                }
            }
        }
        i++;
        p += sizeof(Slot);
    } while (i < 0x80);
}

s32 func_088B6F64(u16 idx, void (*fn)(void), s32 arg2, s32 arg3) {
    Ent28 *e;

    e = (Ent28 *) (D_09A2851C + idx * sizeof(Ent28) + 0x1BA60);
    if (e->unk20 == 0) {
        memset(e, 0, sizeof(Ent28));
        e->unk20 = 1;
        e->unk4 = arg2;
        e->fn = fn;
        e->unk8 = arg3;
        return 0;
    }
    return -1;
}

void func_088B7004(void) {
    s32 i;
    char *p;

    i = 0;
    p = D_09A2851C;
    do {
        if (((Ent28 *) (p + 0x1BA60))->unk20 == 1) {
            if (((Ent28 *) (p + 0x1BA60))->fn != 0) {
                ((Ent28 *) (p + 0x1BA60))->fn();
            }
        }
        i++;
        p += sizeof(Ent28);
    } while (i < 0xB);
}

void func_088B7078(State *arg0, u8 arg1, u16 arg2) {
    Res r;

    memset(&r, 0, sizeof(r));
    arg0->unk20 = 0;
    arg0->unk21 = 0;
    arg0->unk22 = 0;
    r.unkC = arg1;
    r.unk10 = arg2;
    r.unk8 = arg0->arg;
    arg0->cb(&r);
}
