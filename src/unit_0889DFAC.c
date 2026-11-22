/* unit_0889DFAC: 0x0889DFAC-0x0889E1BC (ULES01213) */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned char u8;
typedef signed char s8;

extern s32 func_0880BFF0(void *, void *, s32);
extern u8 *func_0889C518(char *);

static inline char *find1(char *arg0) {
    u8 *key;
    s32 i;
    s32 j;
    s32 r;
    u8 *ent;

    key = func_0889C518(arg0);
    for (i = 0; i < *(s8 *)(arg0 + 0xEE3); i++) {
        ent = (u8 *)(arg0 + i * 200 + 0x57C);
        for (j = 0; j < 6; j++) {
            if (key[j] < ent[j]) {
                r = -1;
                goto done;
            }
            if (ent[j] < key[j]) {
                r = 1;
                goto done;
            }
        }
        r = 0;
    done:
        if (r == 0) {
            return arg0 + i * 200 + 0x57C;
        }
    }
    return 0;
}

static inline char *find2(char *arg0) {
    char *e;
    s32 i2;
    char *found;

    found = find1(arg0);
    if (found == 0) {
        return 0;
    }
    for (i2 = 0; i2 < *(s8 *)(arg0 + 0xEE3); i2++) {
        e = arg0 + (u8)i2 * 200 + 0x57C;
        if (func_0880BFF0(found + 0xB8, e, 6) == 0) {
            return e;
        }
    }
    return 0;
}

static inline s32 isK(u8 k) {
    return (k == 3) | (k == 4) | (k == 5);
}

s32 func_0889DFAC(char *arg0, s32 arg1) {
    char *e;

    e = find2(arg0);
    if (isK(*(u8 *)(arg0 + 0x12D5)) && e != 0 && isK((arg0 + 0x63B)[(u8)(s8)arg1 * 200]) && func_0880BFF0(e, arg0 + (u8)arg1 * 200 + 0x634, 6) == 0) {
        return 1;
    }
    return 0;
}
