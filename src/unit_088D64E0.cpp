/* unit_088D64E0: 0x088D64E0-0x088D66F4 (ULES01213)
 *
 * Bounds (hypothesis): 2 functions between unit_088D6488 and func_088D66F4,
 * which is still in assembly (text_088D66F4).
 *
 * func_088D64E0 starts a move of the position at +0x200 to the one at +0x650
 * in `arg1` steps (step at +0x660, count at +0x670), or jumps there when
 * the distance is 800 or more. func_088D6594 adds to the 16-bit value at
 * +0x2E4 of the object whose id is the global one, kept within 0 and the
 * maximum at +0x41E, and tracks its highest value at +0x41C.
 *
 * C++: bool conversions, an inline test of the object id against the
 * global one. The distance is a VFPU `asm` block (notes/COMPILER.md, "VFPU
 * in asm blocks").
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct Vec {
    float x, y, z, w;
} __attribute__((aligned(16))) Vec;

extern "C" {

extern char *D_089CC438;

extern s32 func_0884FA5C(char *, s32);
extern s32 func_088D6A1C(char *, u8);
extern void func_09CB1C58(char *, s32, float);

static inline bool is_own(char *obj) {
    return *(u16 *)(obj + 0x1E6) == *(u8 *)(D_089CC438 + 0x28);
}

static inline float vec_dist(Vec &ra, Vec &rb) {
    float r;
    float *pr = &r;
    Vec *a = &ra;
    Vec *b = &rb;
    asm {
        lv.q C000, 0(a)
        lv.q C010, 0(b)
        vsub.t C000, C000, C010
        nop
        vdot.t S010, C000, C000
        vsqrt.s S010, S010
        sv.s S010, 0(pr)
    }
    return r;
}

void func_088D64E0(char *arg0, s32 arg1) {
    float n;

    if (vec_dist(*(Vec *)(arg0 + 0x200), *(Vec *)(arg0 + 0x650)) >= 800.0f) {
        *(s16 *)(arg0 + 0x670) = 0;
        *(float *)(arg0 + 0x200) = *(float *)(arg0 + 0x650);
        *(float *)(arg0 + 0x204) = *(float *)(arg0 + 0x654);
        *(float *)(arg0 + 0x208) = *(float *)(arg0 + 0x658);
    } else {
        n = arg1;
        *(s16 *)(arg0 + 0x670) = arg1;
        *(float *)(arg0 + 0x660) = (*(float *)(arg0 + 0x650) - *(float *)(arg0 + 0x200)) / n;
        *(float *)(arg0 + 0x664) = (*(float *)(arg0 + 0x654) - *(float *)(arg0 + 0x204)) / n;
        *(float *)(arg0 + 0x668) = (*(float *)(arg0 + 0x658) - *(float *)(arg0 + 0x208)) / n;
    }
}

s32 func_088D6594(char *arg0, s16 arg1) {
    if (is_own(arg0) == 0) {
        return 0;
    }
    if ((u8) func_0884FA5C(D_089CC438, 0) == 1) {
        if (arg1 < 0) {
            return 0;
        }
    }
    if (*(u8 *)(arg0 + 0x298) == 3) {
        return 0;
    }
    if ((u8) func_088D6A1C(arg0, 0xC8) == 1 || (u8) func_088D6A1C(arg0, 0xD3) == 1) {
        if (*(s16 *)(arg0 + 0x2E4) >= 0x40 && *(s16 *)(arg0 + 0x2E4) + arg1 <= 0) {
            *(s16 *)(arg0 + 0x2E4) = 1;
            *(s16 *)(arg0 + 0x41C) = 1;
            func_09CB1C58(arg0, 0x11, 1.0f);
            return 1;
        }
    }
    *(s16 *)(arg0 + 0x2E4) += arg1;
    if (*(s16 *)(arg0 + 0x2E4) <= 0) {
        *(s16 *)(arg0 + 0x2E4) = 0;
    }
    if (*(s16 *)(arg0 + 0x2E4) >= *(s16 *)(arg0 + 0x41E)) {
        *(s16 *)(arg0 + 0x2E4) = *(s16 *)(arg0 + 0x41E);
    }
    if (*(s16 *)(arg0 + 0x2E4) >= *(s16 *)(arg0 + 0x41C)) {
        *(s16 *)(arg0 + 0x41C) = *(s16 *)(arg0 + 0x2E4);
    }
    return 0;
}

}
