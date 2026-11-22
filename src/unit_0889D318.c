/* unit_0889D318: 0x0889D318-0x0889D3FC (ULES01213) */

#pragma optimize_for_size off

typedef unsigned char u8;
typedef signed char s8;
typedef int s32;

typedef struct {
    u8 id[0xB8];
    u8 unkB8[0x10];
} Entry;

typedef struct {
    char pad0[0x57C];
    Entry entries[4];
} Sys;

extern void memcpy(void *, void *, s32);
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

void func_0889D318(char *arg0, u8 *arg1) {
    Entry *e;

    e = find(arg0, func_0889C518(arg0));
    if (e != 0) {
        memcpy(e->unkB8, arg1, 6);
    }
}
