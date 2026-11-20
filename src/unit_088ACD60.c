/* unit_088ACD60: 0x088ACD60-0x088AD00C (ULES01213)
 *
 * Bounds (hypothesis): 4 functions between unit_088ACD38 and unit_088AD00C.
 *
 * Network state helpers around the callback table at 0x09A1DB78 (see
 * unit_088AC0E8): state accessor, reset (with the console's OpenPSID copied
 * to 0x09A1DBC4), exit callback and power callback.
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

typedef struct {
    void (*fn)(s32, s32, void *);
    void *arg;
} Handler;

typedef struct {
    char unk0[0x14];
    s32 unk14;
} State;

extern State D_09A1DB60;
extern s32 D_09A1DB74;
extern Handler D_09A1DB78[8];
extern s32 D_09A1DBB8;
extern u8 D_09A1DBBC;
extern u8 D_09A1DBBD;
extern s32 D_09A1DBC0;
extern char D_09A1DBC4[];

extern s32 sceOpenPSIDGetOpenPSID(void *);
extern s32 sceKernelExitGame(void);
extern void memset(void *, s32, s32);
extern void memcpy(void *, const void *, s32);

s32 func_088ACD60(void) {
    State *s = &D_09A1DB60;

    if (D_09A1DB74 != 0) {
        return s->unk14;
    }
    return 0;
}

void func_088ACD88(void) {
    u8 psid[16];

    D_09A1DBB8 = -1;
    memset(D_09A1DB78, 0, 0x40);
    D_09A1DBBD = 1;
    D_09A1DBBC = 1;
    sceOpenPSIDGetOpenPSID(psid);
    memset(D_09A1DBC4, 0, 0x80);
    memcpy(D_09A1DBC4, psid, 0x10);
    D_09A1DBC0 = 0x10;
}

s32 func_088ACE0C(void) {
    u32 i;
    Handler *h;

    for (i = 0, h = D_09A1DB78; i < 8; i++, h++) {
        if (h->fn != 0) {
            h->fn(0, 6, h->arg);
        }
    }
    sceKernelExitGame();
    return 0;
}

s32 func_088ACE74(s32 unused, s32 flags) {
    u32 i0;
    Handler *h0;
    Handler *h1;
    u32 i1;
    Handler *h2;
    u32 i2;
    Handler *h3;
    u32 i3;
    Handler *h4;
    u32 i4;

    if (flags & 0x80000) {
        for (i0 = 0, h0 = D_09A1DB78; i0 < 8; i0++, h0++) {
            if (h0->fn != 0) {
                h0->fn(0, 1, h0->arg);
            }
        }
    }
    if (flags & 0x10000) {
        for (i1 = 0, h1 = D_09A1DB78; i1 < 8; i1++, h1++) {
            if (h1->fn != 0) {
                h1->fn(0, 2, h1->arg);
            }
        }
    }
    if (flags & 0x20000) {
        for (i2 = 0, h2 = D_09A1DB78; i2 < 8; i2++, h2++) {
            if (h2->fn != 0) {
                h2->fn(0, 3, h2->arg);
            }
        }
    }
    if (flags & 0x40000) {
        for (i3 = 0, h3 = D_09A1DB78; i3 < 8; i3++, h3++) {
            if (h3->fn != 0) {
                h3->fn(0, 4, h3->arg);
            }
        }
    }
    if (flags & 0x100) {
        for (i4 = 0, h4 = D_09A1DB78; i4 < 8; i4++, h4++) {
            if (h4->fn != 0) {
                h4->fn(0, 5, h4->arg);
            }
        }
    }
    return 0;
}
