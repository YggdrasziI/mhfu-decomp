/* unit_088D72A4: 0x088D72A4-0x088D773C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088D722C and unit_088D773C.
 *
 * NonMatching, 97.8 %. Adds `arg2` to the count of the pair whose id is
 * `arg1` (pairs of func_08856884; 0x18-byte records at D_0899D198, maximum
 * count in byte 3) and returns what happened: 0 new pair, 1 count changed,
 * 2 clamped to the maximum, 3 already at the maximum, 4 pair emptied, 5 no
 * free pair. The 16-bit return type is a hypothesis (no extension of the
 * result, which shares its variable with the maximum).
 *
 * Gaps: saved registers (original: result s0, arg2 s1, arg1 s2, arg0 s3,
 * masked arg1 s4, index s5; ours: index s0, masked arg1 s1, result s2, arg2
 * s3, arg1 s4, arg0 s5), and the load of +0x648 placed after the load of
 * D_08A62C50 instead of before. Tried: all declaration orders (no effect),
 * one index per loop, block-scoped indices, `s16` / `u32` index, a local
 * copy of the id, a separate variable for the maximum, the result
 * initialised at its declaration, inline helpers for the pair and the
 * lookup, merged early tests, `!` test.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct Pair {
    u16 unk0;
    s16 unk2;
} Pair;

extern "C" {

extern char *D_089CC438;
extern char *D_08A62C50;
extern u8 D_0899D198[];
extern u8 D_0899D19B[];

extern Pair *func_08856884(char *, s32);
extern s32 func_088568AC(char *, u16);
extern void func_0885ACA0(char *, u16);
extern u8 *func_0885C580(char *, u16);
extern s32 func_088D7AD8(char *, u16, s32);
extern void func_088D8000(char *);
extern s32 func_088D81FC(char *, u16, s32);
extern void func_088D839C(char *, s16);

static inline bool is_own(char *obj) {
    return *(u16 *)(obj + 0x1E6) == *(u8 *)(D_089CC438 + 0x28);
}

s16 func_088D72A4(char *arg0, u16 arg1, s16 arg2, u8 arg3) {
    s16 ret;
    s32 i;
    s32 off;
    u8 *max;

    if (is_own(arg0) == 0) {
        return 0;
    }
    if (arg1 >= 0x4ED) {
        return 0;
    }
    if (arg1 == 0x80) {
        return 0;
    }
    off = arg1 * 0x18;
    max = &D_0899D19B[off];
    if (*max == 0xFF) {
        arg2 = 0xFF;
    }
    if ((s16) func_088568AC(D_089CC438, arg1) == 0) {
        ret = 5;
        i = 0;
        do {
            if (func_08856884(D_089CC438, i)->unk0 == 0) {
                if (arg2 > 0) {
                    ret = *max;
                    func_08856884(D_089CC438, i)->unk0 = arg1;
                    if (ret < arg2) {
                        arg2 = ret;
                    }
                    func_08856884(D_089CC438, i)->unk2 = arg2;
                    if (arg3 == 0) {
                        func_0885ACA0(D_08A62C50, arg1);
                    }
                    if (D_0899D198[off] == 2) {
                        if (i == *(u16 *)(arg0 + 0x686)) {
                            *(u16 *)(arg0 + 0x686) = func_088D7AD8(arg0, i, 2);
                            func_088D8000(arg0);
                            *(s16 *)(arg0 + 0x642) = *(s16 *)(arg0 + 0x646);
                            *(u8 *)(arg0 + 0x645) = *(u8 *)(arg0 + 0x67D);
                            *(u8 *)(arg0 + 0x644) = 0;
                        } else if (*(u8 *)(arg0 + 0x1E8) == 1 || *(u8 *)(arg0 + 0x1E8) == 5) {
                            if (*(u16 *)(arg0 + 0x686) == 0xFF) {
                                *(u16 *)(arg0 + 0x686) = func_088D7AD8(arg0, 0, 2);
                                func_088D8000(arg0);
                            } else if (func_0885C580(D_08A62C50, *(u16 *)(arg0 + 0x686))[0] != 2) {
                                *(u16 *)(arg0 + 0x686) = func_088D7AD8(arg0, *(u16 *)(arg0 + 0x686), 0);
                                func_088D8000(arg0);
                            }
                        }
                    }
                    ret = 0;
                    if (func_0885C580(D_08A62C50, *(u16 *)(arg0 + 0x648))[1] == 1) {
                        break;
                    }
                    *(u16 *)(arg0 + 0x648) = func_088D81FC(arg0, *(u16 *)(arg0 + 0x648), 0);
                    break;
                }
            }
            i++;
        } while (i < 0x18);
    } else {
        i = 0;
        do {
            if (arg1 == func_08856884(D_089CC438, i)->unk0) {
                ret = *max;
                if (arg2 > 0 && func_08856884(D_089CC438, i)->unk2 >= ret) {
                    func_08856884(D_089CC438, i)->unk2 = ret;
                    if (arg3 == 0) {
                        func_0885ACA0(D_08A62C50, arg1);
                    }
                    ret = 3;
                } else {
                    if (arg2 < 0 && *max == 0xFF) {
                        ret = 1;
                        break;
                    }
                    func_08856884(D_089CC438, i)->unk2 += arg2;
                    if (func_08856884(D_089CC438, i)->unk2 <= 0) {
                        func_088D839C(arg0, i);
                        func_08856884(D_089CC438, i)->unk0 = 0;
                        func_08856884(D_089CC438, i)->unk2 = 0;
                        ret = 4;
                    } else {
                        if (func_08856884(D_089CC438, i)->unk2 > ret) {
                            func_08856884(D_089CC438, i)->unk2 = ret;
                            ret = 2;
                        } else {
                            ret = 1;
                        }
                        if (arg3 == 0) {
                            func_0885ACA0(D_08A62C50, arg1);
                        }
                    }
                }
                if (D_0899D198[off] == 2) {
                    if (i == *(u16 *)(arg0 + 0x686)) {
                        *(s16 *)(arg0 + 0x642) = *(s16 *)(arg0 + 0x646) = func_08856884(D_089CC438, *(u16 *)(arg0 + 0x686))->unk2;
                        if (*(s16 *)(arg0 + 0x646) < *(u8 *)(arg0 + 0x67C)) {
                            *(u8 *)(arg0 + 0x67C) = *(s16 *)(arg0 + 0x646);
                            *(u8 *)(arg0 + 0x644) = *(u8 *)(arg0 + 0x67C);
                        }
                    }
                }
                break;
            }
            i++;
        } while (i < 0x18);
    }
    return ret;
}

}
