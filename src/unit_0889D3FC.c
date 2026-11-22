/* unit_0889D3FC: 0x0889D3FC-0x0889D504 (ULES01213) */

#pragma optimize_for_size off

typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef int s32;

typedef struct {
    u8 id[0x20];
    char data[0xA8];
} Entry;

typedef struct {
    char pad0[0x57C];
    Entry entries[4];
} Sys;

extern u8 *func_0889C518(char *);
extern void memcpy(void *, void *, s32);

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

void func_0889D3FC(char *arg0, void *arg1, s16 arg2, s16 arg3) {
    Entry *e;
    char *p;

    e = find(arg0, func_0889C518(arg0));
    if (e != 0) {
        p = (char *)e + 0x20;
        memcpy(p + 0x8D, arg1, 6);
        *(s16 *)(p + 0x94) = arg2;
        *(s16 *)(p + 0x96) = arg3;
    }
}
