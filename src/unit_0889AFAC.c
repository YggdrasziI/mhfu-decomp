/* unit_0889AFAC: 0x0889AFAC-0x0889B160 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between neighbouring units.
 */

#pragma optimize_for_size off

typedef unsigned char u8;
typedef signed char s8;
typedef int s32;
typedef float f32;

typedef struct { f32 a, b; } F2;
typedef struct { f32 a, b, c; } F3;
typedef struct { F3 p0; F2 p1; } C3_2;

typedef struct {
    u8 id[0x20];
    char data[0xA8];
} Entry;

typedef struct {
    char pad0[0x57C];
    Entry entries[4];
} Sys;

extern char *D_089CBBEC;
extern s32 func_088B0EFC(void *);
extern void func_0883D184(char *, void *, s32);
extern void func_0889CC34(char *, void *);

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

void func_0889AFAC(char *arg0) {
    C3_2 cp1C;
    u8 key[8];
    char *s;

    cp1C.p0 = ((C3_2 *)arg0)->p0;
    cp1C.p1 = ((C3_2 *)arg0)->p1;
    s = *(char **)&cp1C.p0.c;
    func_088B0EFC(key);
    if (find(s, key) != 0) {
        func_0883D184(D_089CBBEC, &find(s, key)->id[8], 3);
    }
    func_0889CC34(s, key);
}
