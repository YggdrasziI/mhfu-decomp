/* unit_0889D608: 0x0889D608-0x0889D6EC (ULES01213)
 *
 * Finds the 200-byte record whose 6-byte id equals the one returned by
 * func_0889C518, then clears 6 bytes at +0xAD and the halfwords at +0xB4 and
 * +0xB6.
 */

#pragma optimize_for_size off

typedef int s32;
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 b[6];
} Id;

extern void memset(void *, s32, s32);
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

void func_0889D608(char *arg0) {
    char *e;
    char *q;

    e = find(arg0, func_0889C518(arg0));
    if (e != 0) {
        q = e + 0x20;
        memset(q + 0x8D, 0, 6);
        *(u16 *)(q + 0x94) = 0;
        *(u16 *)(q + 0x96) = 0;
    }
}
