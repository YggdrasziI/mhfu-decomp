/* unit_0889D008: 0x0889D008-0x0889D0E0 (ULES01213) */

#pragma optimize_for_size off

typedef int s32;
typedef signed char s8;
typedef unsigned char u8;

typedef struct {
    u8 b[6];
} Id;

extern u8 *func_0889C518(char *);

static inline s32 cmp6(u8 *arg0, u8 *arg1) {
    Id *a = (Id *)arg0;
    Id *b = (Id *)arg1;
    s32 i;

    for (i = 0; i < 6; i++) {
        if (a->b[i] < b->b[i]) {
            return -1;
        }
        if (a->b[i] > b->b[i]) {
            return 1;
        }
    }
    return 0;
}

static inline char *find(char *p, u8 *key) {
    s32 j;

    for (j = 0; j < *(s8 *)(p + 0xEE3); j++) {
        if (cmp6(key, (u8 *)(p + j * 200 + 0x57C)) == 0) {
            return p + j * 200 + 0x57C;
        }
    }
    return 0;
}

void func_0889D008(char *arg0, u8 arg1) {
    char *e;

    e = find(arg0, func_0889C518(arg0));
    if (e != 0) {
        e[0xB3] = arg1;
    }
}
