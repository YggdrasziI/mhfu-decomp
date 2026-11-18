/* unit_088429EC: 0x088429EC-0x08842BE4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly
 * (text_088415D0 and text_08842BE4).
 *
 * The sine is VFPU code: mwccpsp assembles VFPU mnemonics in an `asm { }`
 * block, with the operand and the result passed through stack slots.
 *
 * Optimized for speed: the float constants are built as immediates.
 *
 * .data: the initializer of the local s16[4][3] table (0x0893B5D4-0x0893B5EC).
 *
 * `ang = K * (float) ang;`: the redundant cast keeps the constant as the first
 * operand of the `mul.s` (`ang *= K` or `K * ang` swap them; `K * (float)
 * phase` loads the constant before the conversion).
 */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

extern char *D_08A631A0;
extern u16 D_0893B5B4[];
extern u16 D_0893B5B6[];
extern s16 D_0893B5B8[];
extern u16 D_0893B5BA[];
extern u16 D_0893B5BC[];

extern void func_0882B1CC(char *, u16, u16, s32, s32, s32, u8, u16);

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

void func_088429EC(char *arg0, s32 arg1) {
    u32 phase;
    float ang;
    u8 alpha;
    u16 x;
    s16 y;

    phase = (u16) ((*(s32 *)(D_08A631A0 + 0xF7A554) & 0x1F) << 11);
    ang = phase;
    ang = 9.58737992e-05f * (float) ang;
    alpha = (s8) (96.0f * sin_vfpu(ang)) + 0x9F;
    if (*(s8 *)(arg0 + 0x57B) != 0) {
        x = D_0893B5B4[arg1 * 5];
        if (*(u8 *)(*(char **)(arg0 + 0x530) + 0x1E8) == 9) {
            x += 0x38;
        }
        func_0882B1CC(arg0, x, D_0893B5B6[arg1 * 5], 0xFF, 0xFF, 0xFF, alpha, D_0893B5BC[arg1 * 5]);
    } else {
        s16 pos[4][3] = {{0xCC, 0xD0, 0xB8}, {0xC8, 0xC0, 0xBC}, {0xCC, 0xC3, 0xBC}, {0xC8, 0xBA, 0xBC}};
        s32 sel = *(s32 *)(D_08A631A0 + 0xF7A574);
        if (sel < 2) {
            y = D_0893B5B8[arg1 * 5];
        } else {
            y = pos[sel - 2][arg1];
        }
        func_0882B1CC(arg0, y, D_0893B5BA[arg1 * 5], 0xFF, 0xFF, 0xFF, alpha, D_0893B5BC[arg1 * 5]);
    }
}