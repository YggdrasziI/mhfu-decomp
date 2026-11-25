/* unit_08841AB4: 0x08841AB4-0x088421C4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08841AB4 (ULES01213)
 *
 * C++: the flag tests keep their `sltu` (bool). Optimized for speed: the
 * entry table index is strength-reduced in the search loop.
 *
 * The flag at 0x11E4 is bit 32 of a 64-bit word at 0x11E0: the `negu zero;
 * subu; or; sltu` sequence is a 64-bit `!= 0` (the low half folds to zero).
 * func_0882B624 takes u8 colour components (the table loads move after the
 * sum). The block index is an s32 local masked `(u16)` once in the
 * wrap-around loop.
 */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef long long s64;
typedef unsigned long long u64;

extern "C" {

extern u8 D_0893ABAC[][4];
extern u16 D_0893ABEC[];
extern u16 D_0893AE68[];
extern u16 D_0893B594;
extern u16 D_0893B598;
extern u16 D_0893B59A;
extern u16 D_0893B59C;
extern u16 D_0893B59E;
extern u16 D_0893B5A0;
extern u16 D_0893B5A2;
extern u16 D_0893B5A4;
extern u16 D_0893B5A6;
extern u16 D_0893B5A8;
extern char *D_08A631A0;
extern char *D_08A631A8;
extern char *D_089CC438;
extern char *D_089CBBEC;
extern char *D_09C121B0;

extern void func_08842504(char *, u16, u16, u16, s32, s32, s32, s32);
extern void func_088423E0(char *, u16, u16, u16, s32, s32, s32, s32);
extern void func_0882B624(char *, u16, u16, u8, u8, u8, s32, s32);
extern void func_0882D6F0(char *, u16, u16, u16, s32, s32, s32, s32);
extern void func_08890E38(char *, s8);
extern void func_08890DFC(char *, s16, s16);
extern void func_08890DE8(char *, s8, u8);
extern void func_088266CC(char *, char *);
extern int func_0889134C(char *, char *, ...);
extern s32 func_0882A9DC(char *, u16, u16, s32);
extern void func_088421C4(char *, char *, u16, u16);

static inline char *get_entry(char *base, s32 i) {
    if (i < 0 || i >= 20) {
        return 0;
    }
    return *(char **)(base + 0x1220 + i * 4);
}

void func_08841AB4(char *arg0, char *arg1, u16 arg2, u16 arg3) {
    u8 *col;
    s32 i;
    s32 found;
    char *e;
    s32 m;
    s16 *t;
    s32 n;
    s32 j;
    s32 idx;
    s16 v;

    col = D_0893ABAC[*(u16 *)(arg1 + 0x1E6) & 3];
    if (*(u8 *)(arg1 + 0x1E8) == 0xC && (bool)(*(u64 *)(arg1 + 0x11E0) & 0x100000000LL) != 0 &&
        *(s16 *)(arg1 + 0x2E4) < 0x33 && *(u8 *)(arg1 + 0x15CF) == 0) {
        if (*(s32 *)(D_08A631A0 + 0xF7A554) & 4) {
            func_08842504(arg0, arg2, arg3, D_0893B594, 0x60, 0x60, 0x60, 0xFF);
        } else {
            func_088423E0(arg0, arg2, arg3, D_0893B594, 0xFF, 0xFF, 0xFF, 0xFF);
        }
    } else {
        func_088423E0(arg0, arg2, arg3, D_0893B594, 0xFF, 0xFF, 0xFF, 0xFF);
    }
    if (*(u8 *)(arg1 + 0x1E8) != 0xC) {
        func_0882B624(arg0, arg2 + D_0893B598, arg3, col[0], col[1], col[2],
                      D_0893AE68[*(u8 *)(arg1 + 0x1E8)], 0);
    } else {
        func_0882B624(arg0, arg2 + D_0893B598, arg3, col[0], col[1], col[2], 0x1F3, 0);
    }
    if (*(u16 *)(arg1 + 0x1E6) != *(u8 *)(D_089CC438 + 0x28) && *(u8 *)(arg1 + 0x1E8) != 0xC) {
        s16 a = *(s16 *)(arg1 + 0x41E);
        s16 b = *(s16 *)(arg1 + 0x2E4);
        float r = (float)b / (float)a;
        s16 w = (s16)((float)(u32)D_0893B5A2 * r);
        if (b > 0 && w == 0) {
            w = 1;
        }
        func_0882D6F0(arg0, arg2 + D_0893B59E, arg3 + D_0893B5A0, w, 2, 0x30, 0xFF, 0x30);
    }
    func_08890E38(D_08A631A8, 0);
    func_08890DFC(D_08A631A8, arg2 + D_0893B59A, arg3 + D_0893B59C);
    if (*(u8 *)(arg1 + 0x1E8) != 0xC) {
        func_08890DE8(D_08A631A8, 0x10, 0xE);
        func_088266CC(arg0, arg1);
    } else {
        if (*(u8 *)(arg1 + 0x15CF) == 1) {
            func_08890E38(D_08A631A8, 10);
        }
        func_0889134C(D_08A631A8, D_089CC438 + 0x6A210);
    }
    func_08890DE8(D_08A631A8, 0xE, 0xE);
    found = 0;
    if (*(u8 *)(arg1 + 0x566) != 0) {
        found = 1;
    } else if (*(u8 *)(arg1 + 0x1E8) != 0xC || *(s8 *)(arg1 + 0x15CE) == 0) {
        for (i = 0; i < 20; i++) {
            e = get_entry(D_09C121B0, i);
            if (e == 0) {
                continue;
            }
            if ((bool)(*(s32 *)(e + 4) & 1) == 0) {
                continue;
            }
            if (*(u16 *)(e + 0x29A) != *(u16 *)(arg1 + 0x29A)) {
                continue;
            }
            if (*(u8 *)(e + 0x1E8) == 0xF || *(u8 *)(e + 0x1E8) == 0x2D) {
                continue;
            }
            if ((bool)(*(s32 *)(e + 0x638) & 4) == 1 && *(u16 *)(e + 0x50A) == 1 &&
                *(u16 *)(e + 0x50C) == 0 && *(u16 *)(arg1 + 0x1E6) == *(u16 *)(e + 0x50E) &&
                *(u8 *)(e + 0x4B9) == 1) {
                found = 1;
                break;
            }
            if (*(u8 *)(e + 0x4BA) & (1 << *(u16 *)(arg1 + 0x1E6))) {
                found = 1;
                break;
            }
        }
    }
    if (found > 0) {
        func_0882A9DC(arg0, arg2 + D_0893B5A4, arg3 + D_0893B5A6, 0x19);
    }
    if (*(u8 *)(arg1 + 0x1E8) == 0xC) {
        switch (*(s8 *)(arg1 + 0x15CE)) {
        case 1:
            func_0882A9DC(D_089CBBEC, arg2 + D_0893B5A4, arg3 + D_0893B5A6, 0x1EC);
            break;
        case 2:
            func_0882A9DC(D_089CBBEC, arg2 + D_0893B5A4, arg3 + D_0893B5A6, 0x1ED);
            break;
        }
    }
    m = *(u16 *)(arg1 + 0x424);
    if (m & 0x1FFF) {
        idx = *(u16 *)(arg1 + 0x1E6);
        t = (s16 *)((char *)(idx * 2) + (s32)arg0 + 0x53C);
        v = *t;
        if (v < 0) {
            for (j = 0; j < 13; j++) {
                if (m & (1 << j)) {
                    *(u8 *)((char *)idx + (s32)arg0 + 0x544) = j;
                    *(s16 *)((char *)(*(u16 *)(arg1 + 0x1E6) * 2) + (s32)arg0 + 0x53C) = 20;
                    break;
                }
            }
        } else {
            if ((m & (1 << *(u8 *)((char *)idx + (s32)arg0 + 0x544))) && v > 0) {
                *t = v - 1;
            } else {
                n = 13;
                do {
                    *(u8 *)(arg0 + (u16)idx + 0x544) += 1;
                    if (*(u8 *)(arg0 + *(u16 *)(arg1 + 0x1E6) + 0x544) >= 13) {
                        *(u8 *)(arg0 + *(u16 *)(arg1 + 0x1E6) + 0x544) = 0;
                    }
                    idx = *(u16 *)(arg1 + 0x1E6);
                    if (m & (1 << *(u8 *)(arg0 + idx + 0x544))) {
                        *(s16 *)((char *)(idx * 2) + (s32)arg0 + 0x53C) = 20;
                        break;
                    }
                } while (--n > 0);
            }
        }
        func_0882A9DC(arg0, arg2 + D_0893B5A8, arg3 + D_0893B5A6,
                      D_0893ABEC[*(u8 *)((char *)*(u16 *)(arg1 + 0x1E6) + (s32)arg0 + 0x544)]);
    } else {
        *(s16 *)((char *)(*(u16 *)(arg1 + 0x1E6) * 2) + (s32)arg0 + 0x53C) = -1;
    }
    func_088421C4(arg0, arg1, arg2, arg3);
}
}
