/* unit_0883FDF4: 0x0883FDF4-0x08840338 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0883FDF4: 0x0883FDF4-0x08840338 (ULES01213)
 *
 * Speed setting (float constants built with lui/ori). The sine is VFPU code
 * in an `asm { }` block (sin_vfpu helper, as in unit_08841100.cpp).
 * `u16 r = <float expr>;` gives the doubled 0x4F000000 compare of the
 * float -> u16 conversion. The four globals of the first func_0882C11C call
 * are `const` so their loads are scheduled above the stack argument stores.
 */
#pragma optimize_for_size off
typedef int s32;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef float f32;

extern s32 D_089CBBE4;
extern s32 D_08A62D8C;
extern u16 D_0893B51C;
extern u16 D_0893B51E;
extern u16 D_0893B520;
extern u16 D_0893B522;
extern u16 D_0893B524;
extern u16 D_0893B526;
extern u16 D_0893B528;
extern u16 D_0893B52A;
extern s16 D_0893B52C[];
extern u16 D_0893B52E;
extern u16 D_0893B530;
extern u16 D_0893B532;
extern u16 D_0893B534;
extern u16 D_0893B536;
extern u16 D_0893B538;
extern u16 D_0893B53A;
extern u16 D_0893B53C;
extern u16 D_0893B53E;
extern u16 D_0893B540;
extern u16 D_0893B542;
extern u16 D_0893B544;
extern u16 D_0893B546;
extern u16 D_0893B548;
extern u16 D_0893B54A;
extern const u16 D_0893B54C;
extern const u16 D_0893B54E;
extern const s16 D_0893B550;
extern const s16 D_0893B552;
extern u16 D_0893B554;
extern u16 D_0893B556;
extern s16 D_0893B558;
extern s16 D_0893B55A;
extern u16 D_0893B55C;
extern u16 D_0893B55E;
extern s16 D_0893B560;
extern s16 D_0893B562;
extern u16 D_0893B564;
extern u16 D_0893B566;
extern s16 D_0893B568;
extern s16 D_0893B56A;

extern s32 func_08814048(s32, s32);
extern s8 func_08814080(s32, u8 *, u8 *, f32 *);
extern s32 func_0882A9DC(char *, u16, u16, s32);
extern void func_0882C7B4(char *, u16, u16, s16, s16, u8, u8, u8, u8, s32, s32);
extern void func_0882B624(char *, u16, u16, s32, s32, s32, s32, s32);
extern void func_0882C11C(char *, u16, u16, s16, s16, u8, u8, u8, u8, s32);
extern s32 func_0882AF70(char *, u16, u16, u16, u16, s32);
extern void func_08883988(s32, s32, s32, s32, s32, s32, s32, s32, s32);

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

void func_0883FDF4(char *arg0) {
    u8 b3f;
    u8 b3e;
    f32 f38;
    u16 x;
    s32 i;
    s8 st;
    u8 a;
    s16 k;

    if ((u8)func_08814048(D_089CBBE4, *(s32 *)(arg0 + 0x530)) == 0) {
        *(s8 *)(arg0 + 0x57B) = -1;
        return;
    }
    *(s8 *)(arg0 + 0x57B) = func_08814080(D_089CBBE4, &b3f, &b3e, &f38);
    if (b3e) {
        func_0882A9DC(arg0, D_0893B51C, D_0893B51E, 7);
        func_0882C7B4(arg0, D_0893B520, D_0893B51E, 12, 12, 255, 255, 255, 255, 7, 1);
        x = D_0893B522;
        for (i = 0; i < 5; i++) {
            func_0882A9DC(arg0, x, D_0893B51E, 8);
            x += D_0893B524;
        }
        {
            u16 r = D_0893B52A * f38 + D_0893B526;
            func_0882B624(arg0, r, D_0893B528, 0xC0, 0, 0, 0x9D, 0);
        }
    }
    if (b3f) {
        st = *(s8 *)(arg0 + 0x579);
        if (st < 4) {
            if (st == 0) {
                a = (u8)((s8)(s32)(94.0f * sin_vfpu(9.58738e-5f *
                        (f32)(u16)((*(u8 *)(arg0 + 0x57A) & 0x1F) << 11))) + 0xA0);
                func_0882C11C(arg0, D_0893B54C, D_0893B54E, D_0893B550, D_0893B552, 255, 255, 255, a, 0x2D);
                func_0882C11C(arg0, D_0893B554, D_0893B556, D_0893B558, D_0893B55A, 255, 255, 255, a, 0x2D);
                func_0882C11C(arg0, D_0893B55C, D_0893B55E, D_0893B560, D_0893B562, 255, 255, 255, a, 0x2D);
                func_0882C11C(arg0, D_0893B564, D_0893B566, D_0893B568, D_0893B56A, 255, 255, 255, a, 0x2D);
                *(u8 *)(arg0 + 0x57A) += 1;
            } else {
                {
                    s32 j;
                    s16 *q;
                    s16 *p;
                    k = 4 - st;
                    q = D_0893B52C;
                    j = 0;
                    p = D_0893B52C;
                    do {
                        s16 dx = (s16)((p[0x20] - q[0x10]) >> 2);
                        s16 dy;
                        s16 nx = (s16)(p[0x20] - k * dx);
                        dy = (s16)((p[0x21] - q[0x11]) >> 2);
                        func_0882AF70(arg0, (u16)nx, (u16)(s16)(p[0x21] - k * dy),
                                      q[0x12], q[0x13], 0x2D);
                        q += 4;
                        p += 2;
                        j++;
                    } while (j < 4);
                }
                *(u8 *)(arg0 + 0x57A) = 0;
            }
            if (*(s32 *)(arg0 + 0x528) & 1) {
                func_08883988(D_08A62D8C, 0, 0x20, 0, 0, 0, 0, 0, 0);
            }
        }
        func_0882AF70(arg0, *(u16 *)D_0893B52C, D_0893B52E, D_0893B530, D_0893B532, 0x2E);
        func_0882AF70(arg0, D_0893B534, D_0893B536, D_0893B538, D_0893B53A, 0x2E);
        func_0882AF70(arg0, D_0893B53C, D_0893B53E, D_0893B540, D_0893B542, 0x2E);
        func_0882AF70(arg0, D_0893B544, D_0893B546, D_0893B548, D_0893B54A, 0x2E);
    }
}
