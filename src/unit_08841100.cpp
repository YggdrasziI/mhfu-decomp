/* unit_08841100: 0x08841100-0x08841520 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly
 * (text_08840C24) and unit_08841520.
 *
 * C++: the flag test keeps its `sltu` (bool). The sines are VFPU code in an
 * `asm { }` block (notes/COMPILER.md, "VFPU in asm blocks"). Optimized for
 * speed: the division by 100 is a multiplication and the float constants
 * are built as immediates.
 *
 * `ang = K * (float) ang;`: the redundant cast keeps the constant as the first
 * operand of the `mul.s` (with a plain `ang` the compiler swaps them, with the
 * conversion inside the product it loads the constant first). The two
 * reads of D_08A631A0 + 0xF7A554 keep their `lui at` form only with block
 * locals for the phase.
 */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

extern "C" {

extern char *D_08A631A0;
extern u8 D_08938858[];
extern u8 D_08938860[][4];
extern u8 D_08938861[][4];
extern u8 D_08938862[][4];
extern u8 D_08938863[][4];

extern void func_08842D3C(char *);
extern int func_088428EC(char *);
extern s32 func_0882A9DC(char *, u16, u16, s32);
extern void func_0882C7B4(char *, u16, u16, s16, s16, u8, u8, u8, u8, s32, s32);
extern void func_0882AC18(char *, s32, s32, s32, s32, s32);
extern void func_0882D6F0(char *, u16, u16, u16, u16, s32, s32, s32);
extern void func_08842BE4(char *, s32);
extern void func_088429EC(char *, s32);
extern s32 func_09A6F9A8(char *);
extern void func_088415D0(char *);
extern s32 func_088DAB94(char *, s16);
extern void func_0882B94C(char *, s32, s32, s32, s32, s32, s32, s32);

static inline float sin_vfpu(float x) {
    float r;
    float *pr = &r;
    float *px = &x;
    asm {
        lv.s S000, 0(px)
        vcst.s S001, VFPU_2_PI
        vmul.s S000, S000, S001
        vsin.s S010, S000
        sv.s S010, 0(pr)
    }
    return r;
}

void func_08841100(char *arg0) {
    char *p;
    s16 v;
    s16 w;
    s32 alpha;
    s32 k;
    char *q;

    if (*(s32 *)(arg0 + 0x1194) & 0x10) {
        return;
    }
    p = *(char **)(arg0 + 0x530);
    switch (*(u8 *)(p + 0x1E8)) {
    case 10:
        func_08842D3C(arg0);
        return;
    case 1:
    case 5:
        func_088428EC(arg0);
        return;
    case 7:
        v = *(s16 *)(p + 0x1140);
        func_0882A9DC(arg0, 0x3E, 0x2C, 0x1A2);
        func_0882C7B4(arg0, 0xA2, 0x2C, 4, 6, 0xFF, 0xFF, 0xFF, 0xFF, 0x1A2, 1);
        func_0882AC18(arg0, 0x42, 0x2C, 0x60, 6, 0x1A3);
        if (v > 0) {
            w = v * 96 / 100;
            if (w > 0x60) {
                w = 0x60;
            }
            if (*(s16 *)(p + 0x610) != 0) {
                u32 phase;
                float ang;

                phase = (u16) ((*(s32 *)(D_08A631A0 + 0xF7A554) & 0x3F) << 10);
                ang = phase;
                ang = 9.58737992e-05f * (float) ang;
                alpha = (u8) (u32) (127.0f + 97.0f * sin_vfpu(ang));
            } else {
                alpha = 0x1E;
            }
            func_0882D6F0(arg0, 0x42, 0x2E, w, 2, 0xE0, alpha, alpha);
        }
        break;
    case 9:
        func_08842BE4(arg0, 2);
        q = *(char **)(arg0 + 0x530);
        if ((bool) (*(s32 *)(q + 0x410) & 8) == 1) {
            if (*(u8 *)(q + 0x67C) <= 0) {
                func_088429EC(arg0, 0);
            }
            if ((u8) func_09A6F9A8(p) == 1) {
                func_088429EC(arg0, 1);
            }
        }
        break;
    case 8:
        func_088415D0(arg0);
        break;
    }
    k = (u8) func_088DAB94(p, *(s16 *)(p + 0x10F2));
    func_0882A9DC(arg0, 0x3C, 0x20, D_08938858[k]);
    if (D_08938860[k][0] != 0) {
        u32 phase;
        float ang;
        float s;

        phase = (u16) ((*(s32 *)(D_08A631A0 + 0xF7A554) & 0x7F) << 9);
        ang = phase;
        ang = 9.58737992e-05f * (float) ang;
        s = sin_vfpu(ang);
        func_0882B94C(arg0, 0x3C, 0x1D, D_08938860[k][0], D_08938861[k][0], D_08938862[k][0],
                      (u8) (((s8) (64.0f * s) + 0x40) & D_08938863[k][0]), 9);
    }
}

}
