/* unit_088711C0: 0x088711C0-0x0887142C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef unsigned int u32;
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;

extern char *D_08A62C7C;
extern char *D_089CC438;
extern char *D_09A4F0D0;

extern s32 func_088564F8(char *);
extern void func_088DE22C(char *, u8, s32);
extern s32 *func_088697D4(char *, s32, s32, s8);

static inline s32 IsGroupA(char *obj, u16 id) {
    if (!(*(s32 *)(obj + 0x28) & 0x1000010)) {
        if (id == 0x29 || id == 0xC2 || id == 0x36 || id == 0x94 || id == 0x10 ||
            id == 0x97 || id == 0x01 || id == 0x6E || id == 0x5C || id == 0x65 ||
            id == 0xCD || id == 0xE3) {
            return 1;
        }
    }
    return 0;
}

static inline s32 IsGroupB(char *obj, u16 id) {
    if (*(s32 *)(obj + 0x28) & 0x10) {
        if (id == 0x15 || id == 0x8C || id == 0x97 || id == 0xA1 || id == 0x6E ||
            id == 0x62 || id == 0xF7) {
            return 1;
        }
    }
    return 0;
}

void func_088711C0(char *arg0, s32 arg1) {
    char *p;
    s32 n;
    s32 *list;
    s32 i;
    u16 id;

    p = D_08A62C7C;
    n = 0;
    if (*(s8 *)(p + 0x786) > 0) {
        n++;
    }
    if (*(s8 *)(p + 0x7B2) > 0 && *(s8 *)(p + 0x77C) != *(s8 *)(p + 0x7A8)) {
        n++;
    }
    id = arg1;
    if (id == func_088564F8(D_089CC438)) {
        func_088DE22C(D_09A4F0D0, 0x12, n);
        n++;
    }
    if (IsGroupA(arg0, id)) {
        func_088DE22C(D_09A4F0D0, 0xA, n);
        n++;
    }
    if (IsGroupB(arg0, id)) {
        func_088DE22C(D_09A4F0D0, 0x4A, n);
        n++;
    }
    list = func_088697D4(arg0, arg1, 0, *(s8 *)(arg0 + 0x20));
    if (list != 0) {
        for (i = 0; i < 4; i++, list++) {
            if (*list != -1) {
                func_088DE22C(D_09A4F0D0, *list, n);
                n++;
            }
        }
    }
}
