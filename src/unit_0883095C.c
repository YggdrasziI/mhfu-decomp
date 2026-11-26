/* unit_0883095C: 0x0883095C-0x08830D3C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0883095C (ULES01213), 0x0883095C-0x08830D3C.
 *
 * The repeated call block (three copies in the original) is a static inline
 * helper; its name is not from the binary.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

extern char *D_089CC438;
extern s32 D_08A62D8C;
extern s32 D_08A631A8;
extern s8 D_089AA1D2;

extern s32 func_08892708(s32, s32, char *, s32, s32 *);
extern s32 func_088855D0(s32, s32);
extern void func_08883988(s32, s32, s32, s32, s32, s32, s32, s32, s32);

static inline void inline_0883095C(s32 se, s32 alt) {
    if ((s32)((*(s32 *)(D_089CC438 + 0x70000 - 0x50EC) & 1) != 0) == 0) {
        func_08883988(D_08A62D8C, func_088855D0(D_08A62D8C, 0x4A), se, D_089AA1D2, 0, 0, 0, 0, 0);
    } else {
        func_08883988(D_08A62D8C, 1, alt, 0, 0, 0, 0, 0, 0);
    }
}

s32 func_0883095C(char *arg0, s32 arg1, u32 arg2, s32 arg3, s32 arg4) {
    u32 rem;
    u32 n;
    s32 i;
    s32 r;
    u32 w;
    char buf[8];
    s32 tmp;

    if (*(u8 *)(arg0 + 0x604) != 0) {
        return -1;
    }
    if (arg3 == 3) {
        *(s8 *)(arg0 + 0x5F0) = 0x10;
        return 0;
    }
    if (arg3 == 4) {
        *(s8 *)(arg0 + 0x5F0) = 0x20;
        return 0;
    }
    if (*(u32 *)(arg0 + 0x5F4) > arg2 || *(s32 *)(arg0 + 0x5EC) != arg1) {
        *(s16 *)(arg0 + 0x5F2) = 0;
        *(s8 *)(arg0 + 0x5F8) = 0;
    }
    *(u32 *)(arg0 + 0x5F4) = arg2;
    *(s8 *)(arg0 + 0x5F0) = 1;
    rem = arg2;
    *(s32 *)(arg0 + 0x5EC) = arg1;
    n = 0;
    i = 0;
    while (1) {
        r = (s16)func_08892708(D_08A631A8, (s16)i, buf, arg1, &tmp);
        if (r == 4) {
            break;
        }
        i++;
        if (buf[0] == '\n') {
            continue;
        }
        n++;
        w = 3;
        if (r == 1) {
            u16 c = (buf[0] << 8) + *(u8 *)&buf[1];
            if (c == 0x8142 || c == 0x8148) {
                w = 15;
            } else if (c == 0x8141) {
                w = 8;
            }
        } else if (r == 0) {
            if (buf[0] == '.' || buf[0] == '?') {
                w = 15;
            }
        }
        if (rem < w) {
            if (*(s16 *)(arg0 + 0x5F2) < n) {
                inline_0883095C(0x1D, 0x84);
            }
            *(s16 *)(arg0 + 0x5F2) = n;
            return 1;
        }
        rem -= w;
    }
    if (*(s16 *)(arg0 + 0x5F2) < n) {
        inline_0883095C(0x1D, 0x84);
    }
    *(s16 *)(arg0 + 0x5F2) = n;
    switch (arg3) {
    case 1:
        *(s8 *)(arg0 + 0x5F0) |= 2;
        if (arg4 == 0) {
            *(s8 *)(arg0 + 0x5F0) |= 4;
        }
        break;
    case 2:
        *(s8 *)(arg0 + 0x5F0) |= 8;
        if (*(s8 *)(arg0 + 0x5F8) == 0) {
            (*(s8 *)(arg0 + 0x5F8))++;
            inline_0883095C(0x1F, 0x86);
        }
        break;
    }
    return 0;
}
