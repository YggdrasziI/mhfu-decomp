/* unit_08816BE4: 0x08816BE4-0x08816F24 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

extern char *D_089CC438;
extern s32 D_09A4F0C4;
extern char *D_08A62C7C;
extern f32 D_08938A7C[];
extern f32 D_0893887C[];
extern f32 D_08938880[];
extern char *func_088DCEBC(s32, u8);
extern void func_0883D274(char *);
extern s32 func_0886A35C(char *, s32);
extern void func_08829674(char *);
extern void func_088306DC(char *);

void func_08816BE4(char *p) {
    u8 idx;
    s32 k;
    f32 f;

    *(char **)(p + 0x530) = func_088DCEBC(D_09A4F0C4, *(u8 *)(D_089CC438 + 0x28));
    *(u8 *)(p + 0x52F) = 0;
    *(u8 *)(p + 0x52E) = 0;
    *(u8 *)(p + 0x52D) = 0;
    *(u8 *)(p + 0x52C) = 0;
    *(u32 *)(p + 0x528) &= ~0x2400;
    *(u8 *)(p + 0x57C) = 0;
    *(u8 *)(D_089CC438 + 0x10) = 0;
    *(u8 *)(p + 0x554) = 0;
    func_0883D274(p);
    *(u8 *)(p + 0x604) = 0;
    *(s32 *)(p + 0x600) = 0;
    *(u32 *)(p + 0x5E8) &= ~0x80;
    *(u32 *)(p + 0x5E8) &= ~2;
    *(s16 *)(p + 0x5FA) = 0;
    *(u8 *)(p + 0x607) = 0;
    *(u32 *)(p + 0x5E8) |= 0x10;
    *(u32 *)(p + 0x5E8) &= ~8;
    *(u8 *)(p + 0x57D) = 0;
    *(u32 *)(p + 0x5E8) &= ~4;
    *(u32 *)(p + 0x528) &= ~4;
    *(s16 *)(p + 0x590) = 0;
    *(u32 *)(p + 0x528) &= ~8;
    *(s32 *)(p + 0x5EC) = 0;
    *(s32 *)(p + 0x5F4) = -1;
    *(u8 *)(p + 0x5F0) = 0;
    if ((s32)((*(u32 *)(D_089CC438 + 0x6AF14) & 1) != 0) == 1) {
        *(s8 *)(p + 0x608) = *(s8 *)(D_089CC438 + 0x6ADE3);
        *(u8 *)(D_089CC438 + 0x422) = 0;
    } else {
        idx = *(u8 *)(D_089CC438 + 0x6AF10);
        f = D_08938A7C[idx];
        k = idx;
        k = k + k;
        *(f32 *)(p + 0x568) = f;
        *(f32 *)(p + 0x564) = f;
        *(f32 *)(p + 0x564) *= 1.0f / D_0893887C[k];
        *(f32 *)(p + 0x568) *= 1.0f / D_08938880[k];
        *(u8 *)(p + 0x576) = 0;
        *(u8 *)(p + 0x577) = 0;
        *(s16 *)(p + 0x548) = *(s16 *)(p + 0x53C) = *(s16 *)(p + 0x56C) = -1;
        *(s16 *)(p + 0x54A) = *(s16 *)(p + 0x53E) = *(s16 *)(p + 0x56E) = -1;
        *(s16 *)(p + 0x54C) = *(s16 *)(p + 0x540) = *(s16 *)(p + 0x570) = -1;
        *(s16 *)(p + 0x54E) = *(s16 *)(p + 0x542) = *(s16 *)(p + 0x572) = -1;
        *(u8 *)(p + 0x579) = 4;
        *(u8 *)(p + 0x57A) = 0;
        *(u32 *)(p + 0x528) &= ~1;
        *(u16 *)(p + 0x596) = *(u16 *)(*(char **)(p + 0x530) + 0x648);
        *(s16 *)(p + 0x59C) = *(u8 *)(*(char **)(p + 0x530) + 0x686);
        *(u8 *)(p + 0x5DC) = 0;
        *(u8 *)(p + 0x5DD) = 0;
        *(s8 *)(p + 0x5DF) = *(s8 *)(D_089CC438 + 0x6ADDF);
        *(s8 *)(p + 0x5E1) = *(s8 *)(D_089CC438 + 0x6ADE0);
        *(s8 *)(p + 0x5DE) = *(s8 *)(D_089CC438 + 0x6ADE1);
        *(s8 *)(p + 0x5E0) = *(s8 *)(D_089CC438 + 0x6ADE2);
        *(s8 *)(p + 0x5E2) = *(s8 *)(D_089CC438 + 0x6ADE4);
        *(s8 *)(p + 0x5E3) = *(s8 *)(D_089CC438 + 0x6ADE5);
        *(s32 *)(p + 0x558) = func_0886A35C(D_08A62C7C, 0);
        *(s32 *)(p + 0x55C) = func_0886A35C(D_08A62C7C, 1);
        func_08829674(p);
        *(u32 *)(p + 0x528) &= ~0x20;
        *(u8 *)(p + 0x11AE) = 0;
    }
    func_088306DC(p);
    *(u8 *)(p + 0x112C) = 0;
    *(u8 *)(p + 0x1138) = 0;
    *(u8 *)(p + 0x1144) = 0;
    *(u8 *)(p + 0x1150) = 0;
    *(u8 *)(p + 0x115C) = 0;
    *(u8 *)(p + 0x1168) = 0;
    *(s32 *)(p + 0x538) = 0;
    *(u8 *)(p + 0x11AC) = 0;
    *(u8 *)(p + 0x11AB) = 0;
    *(s32 *)(p + 0x1194) = 0;
}
