/* unit_0889D244: 0x0889D244-0x0889D318 (ULES01213) */

#pragma optimize_for_size off

typedef unsigned char u8;
typedef signed char s8;
typedef int s32;

typedef struct {
    u8 id[0xBE];
    u8 unkBE;
    char pad[0x9];
} Entry;

typedef struct {
    char pad0[0x57C];
    Entry entries[4];
} Sys;

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

void func_0889D244(char *arg0, u8 arg1) {
    Entry *e;

    *(u8 *)(arg0 + 0x12D6) = arg1;
    e = find(arg0, func_0889C518(arg0));
    if (e != 0) {
        e->unkBE = *(u8 *)(arg0 + 0x12D6);
    }
}
