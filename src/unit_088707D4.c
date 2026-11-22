/* unit_088707D4: 0x088707D4-0x088709D4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

extern char *D_09C121B0;

extern char *func_0886DE78(char *, s32, s32);
extern void func_09AC9608(char *);
extern void func_09AC8630(char *, s32, s32);
extern void func_0886AEEC(char *, char *);
extern void func_0886AF2C(char *, u16);
extern void func_0886BD84(char *, u16);

typedef struct {
    char pad[0x1220];
    char *p[20];
} Tbl;

inline char *get(char *b, s32 i) {
    if (i < 0 || i >= 20) {
        return 0;
    }
    return ((Tbl *) b)->p[i];
}

inline u8 test(char *p) { return (*(u32 *) (p + 4) & 1) != 0; }

void func_088707D4(char *arg0, s16 *arg1) {
    char *s;
    char *p;
    u16 lvl;
    s16 flags;
    s32 i;
    s16 v;

    v = arg1[3];
    lvl = (u8) ((u16) v >> 8);
    s = func_0886DE78(arg0, arg1[2], v & 0xFF);
    if (s == 0) {
        return;
    }
    flags = *(s16 *) (s + 0x2E);
    if (!(flags & 6)) {
        return;
    }
    for (i = 0; i < 20; i++) {
        p = get(D_09C121B0, i);
        if (p == 0) {
            continue;
        }
        if (*(u16 *) (p + 0x1E6) != *(s8 *) (s + 0x34)) {
            continue;
        }
        if (*(s16 *) (p + 0x4AC) != *(u8 *) (s + 0x2C)) {
            continue;
        }
        if (*(u8 *) (p + 0x1E8) != *(s16 *) s) {
            return;
        }
        if (!test(p)) {
            return;
        }
        if (!(flags & 4)) {
            if (*(u8 *) (p + 0x1D4) >= 2) {
                return;
            }
            if (*(u8 *) (p + 0x298) == 5) {
                return;
            }
        } else {
            if (!(*(s8 *) (s + 4) > lvl)) {
                return;
            }
        }
        if (*(u8 *) (p + 0x1D4) >= 2 || *(u8 *) (p + 0x298) == 5) {
            func_09AC9608(p);
        }
        func_09AC8630(p, 5, 0);
        *(u8 *) (p + 0x230) = 0xFF;
        *(s16 *) (s + 0x2E) = 2;
        *(s16 *) (p + 0x2E4) = 0;
        func_0886AEEC(arg0, p);
        return;
    }
    if (*(s8 *) (s + 4) > lvl) {
        func_0886AF2C(arg0, *(u16 *) s);
        func_0886BD84(arg0, *(u16 *) s);
        (*(s8 *) (s + 4))--;
        if (*(s8 *) (s + 4) > 0) {
            *(s16 *) (s + 0x2E) = 2;
        } else {
            *(s16 *) (s + 0x2E) = 1;
            *(s8 *) (s + 0x34) = -1;
        }
    }
}
