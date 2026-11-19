/* unit_088B6A08: 0x088B6A08-0x088B6E14 (ULES01213)
 *
 * Bounds (hypothesis): 6 functions between unit_088B652C and unit_088B6E14 (NonMatching).
 *
 * Result callbacks, the handler table D_09A44BB4 / D_09A44C08 indexed by
 * event and the 0x80 0x33C-byte request slots at D_09A2851C + 0x1C60
 * (callback, argument, 0x14-byte identifier, timer, retries, handle).
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
extern Slot D_09A2A17C[];
extern char D_09A2A180[];
extern char D_09A2A184[];
extern ResFn D_09A44BB4[];
extern s32 D_09A44C08[];
extern void func_0880C464(void *, s32, s32);
extern s32 func_088AEFCC(s32);
extern s32 func_088AEFE4(s32);
extern u16 func_088AEFFC(void);
extern s32 func_088AF008(u16);

void func_088B6A80(s32 arg0);
s32 func_088B6D10(Res *arg0);

void func_088B6A08(u16 code, ResFn cb, s32 arg) {
    Res r;

    if (cb != 0) {
        func_0880C464(&r, 0, sizeof(r));
        if ((code & 0x8000) == 0) {
            r.unkC = 0;
        } else {
            r.unkC = -1;
        }
        r.unk10 = code;
        r.unk8 = arg;
        cb(&r);
    }
}

void func_088B6A80(s32 arg0) {
    Res r;

    if ((u16) arg0 < 0x15) {
        if (D_09A44BB4[(u16) arg0] != 0) {
            func_0880C464(&r, 0, sizeof(r));
            r.unkC = 1;
            r.unk8 = D_09A44C08[(u16) arg0];
            r.unk10 = arg0;
            D_09A44BB4[(u16) arg0](&r);
        }
    }
}

void func_088B6B14(s32 ev) {
    Res r;

    func_0880C464(&r, 0, sizeof(r));
    if (func_088AEFCC(0x10) == 0 || func_088AEFCC(1) == 0) {
        if (ev != 0) {
            func_088B6A80(ev);
        }
        return;
    }
    if (func_088AEFCC(2) != 0) {
        return;
    }
    if (func_088AEFE4(0) == 0) {
        r.unkC = 0;
        r.unk10 = 0;
    } else {
        r.unkC = -1;
        r.unk10 = func_088AEFFC();
    }
    func_088B6D10(&r);
}

s32 func_088B6BC4(void) {
    s32 n;
    s32 i;
    char *p;

    n = 0;
    i = 0;
    p = D_09A2851C;
    do {
        if (*(u8 *) (p + 0x1C60) == 0) {
            n++;
        }
        i++;
        p += sizeof(Slot);
    } while (i < 0x80);
    return n;
}

Slot *func_088B6BFC(Id *arg0, ResFn cb, s32 arg) {
    Id id;
    s32 i;
    char *p;
    Slot *s;
    Slot *e;

    id = *arg0;
    if (id.unk2 == 0) {
        return 0;
    }
    i = 0;
    p = D_09A2851C;
    do {
        s = (Slot *) (p + 0x1C60);
        if (s->used == 0) {
            e = (Slot *) (D_09A2851C + i * sizeof(Slot) + 0x1C60);
            func_0880C464(e, 0, sizeof(Slot));
            s->used = 1;
            s->cb = cb;
            s->id = id;
            s->arg = arg;
            s->timer = 0x96;
            return e;
        }
        i++;
        p += sizeof(Slot);
    } while (i < 0x80);
    return 0;
}

s32 func_088B6D10(Res *arg0) {
    ResF r;
    s32 i;
    char *p;

    r.p0 = ((ResF *) arg0)->p0;
    r.p1 = ((ResF *) arg0)->p1;
    i = 0;
    p = D_09A2851C;
    do {
        if (func_088AF008((u16) ((u16) (*(u8 *) (p + 0x1C72) << 8) | *(u8 *) (p + 0x1C73))) == 0) {
            D_09A2A17C[i].used = 0;
            if (*(ResFn *) (D_09A2A180 + i * sizeof(Slot)) != 0) {
                ((Res *) &r)->unk8 = *(s32 *) (D_09A2A184 + i * sizeof(Slot));
                (*(ResFn *) (D_09A2A180 + i * sizeof(Slot)))((Res *) &r);
            } else {
                func_0880C464(D_09A2851C + i * sizeof(Slot) + 0x1C60, 0, sizeof(Slot));
            }
            return i;
        }
        i++;
        p += sizeof(Slot);
    } while (i < 0x80);
    return -1;
}
