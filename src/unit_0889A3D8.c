/* unit_0889A3D8: 0x0889A3D8-0x0889A554 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between neighbouring units.
 */

#pragma optimize_for_size off

typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    s32 unk0;
    s32 unk4;
    char *unk8;
    s32 unkC;
    s32 unk10;
} Msg;

typedef struct {
    u8 id[0x20];
    char data[0xA8];
} Entry;

typedef struct {
    char pad0[0x57C];
    Entry entries[4];
} Sys;

extern void memset(void *, s32, s32);
extern void memcpy(void *, void *, s32);
extern s32 func_088B0E2C(char *, void *);
extern void func_0889C75C(char *);
extern u8 *func_0889C518(char *);

static inline s32 cmp6(u8 *a, u8 *b) {
    s32 i;
    for (i = 0; i < 6; i++) {
        if (b[i] < a[i]) return -1;
        if (a[i] < b[i]) return 1;
    }
    return 0;
}

static inline Entry *find(char *s, u8 *id) {
    s32 i;
    for (i = 0; i < *(s8 *)(s + 0xEE3); i++) {
        if (cmp6(((Sys *)s)->entries[i].id, id) == 0) {
            return &((Sys *)s)->entries[i];
        }
    }
    return 0;
}

void func_0889A3D8(Msg *arg0) {
    Msg m;
    char *s;
    Entry *e;

    m = *arg0;
    s = m.unk8;
    *(s32 *)(s + 0x12C0) &= ~0x20;
    *(u8 *)(s + 0x1AF4) = (*(s8 *)&m.unkC == 0);
    *(s32 *)(s + 0x1AF8) = *(u16 *)&m.unk10;
    if (*(u8 *)(s + 0x1AF4)) {
        memset(s + 0x57C, 0, 0x320);
        func_088B0E2C(s + 0xEE3, s + 0x57C);
        func_0889C75C(s);
        e = find(s, func_0889C518(s));
        if (e != 0) {
            memcpy(e->data, s + 0x38, 0xA4);
        }
        *(u8 *)(s + 0x12D4) = 1;
    } else if (*(s32 *)(s + 0x1AF8) == 0x8003) {
        *(u8 *)(s + 0x1AFC) = 1;
    }
}
