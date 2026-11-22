/* unit_0888FBD4: 0x0888FBD4-0x0888FCE4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef unsigned char u8;
typedef signed char s8;

extern char *D_089CBBE4;
extern char *D_089CC438;

extern "C" s32 func_09A6F6B0(char *);

typedef struct {
    char pad[0x91];
    s8 b91;
    s8 b92;
    u8 b93;
} Sub;

static inline bool check(char *obj) {
    if (*(u8 *)(obj + 0x298) != 2) {
        return false;
    }
    switch (*(u8 *)(obj + 0x299)) {
    case 2:
    case 5:
    case 7:
    case 14:
        return true;
    }
    return false;
}

extern "C" void func_0888FBD4(char *arg0) {
    char *obj = *(char **)(D_089CBBE4 + 0xA84);
    Sub *p = (Sub *)(arg0 + 0xA0);
    s32 t;
    s8 r;

    arg0[0x133] = 0;
    if ((bool)(*(s32 *)(D_089CC438 + 0x6AF14) & 1) == 0) {
        if ((u8)check(obj) == 1) {
            p->b93 = 1;
        }
    }
    if (p->b93 == 0) {
        t = func_09A6F6B0(obj);
    } else {
        t = -1;
    }
    r = t;
    if (r >= 0) {
        if (p->b91 < 0) {
            if (--p->b92 > 0) {
                r = -1;
            }
        }
    } else {
        p->b92 = 3;
    }
    p->b91 = r;
}
