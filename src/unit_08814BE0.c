/* unit_08814BE0: 0x08814BE0-0x08814D84 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * NonMatching (99.84 %): the 0x28 store is written before the 0x24 store;
 * the original keeps the 0x24 store first and puts p + 0x30 in a2, not a1.
 */

typedef unsigned char u8;
typedef short s16;
typedef int s32;
typedef float f32;

extern f32 D_08933B04;
extern f32 D_08933B08;
extern f32 D_08933B10;
extern f32 D_08933B18;
extern f32 D_08933B24;
extern f32 D_08933B28;
extern f32 D_08933B30;
extern f32 D_08933B38;
extern f32 D_08933B44;
extern f32 D_08933B48;
extern f32 D_08933B50;
extern f32 D_08933B58;
extern f32 D_08933B64;
extern f32 D_08933B68;
extern f32 D_08933B70;
extern f32 D_08933B78;
extern f32 D_08933B84;
extern f32 D_08933B88;
extern f32 D_08933B90;
extern f32 D_08933B98;

void func_08814BE0(char *arg0) {
    char *p = *(char **)(arg0 + 0xAAC);

    *(s16 *)(p + 0x0) = 0x102;
    *(s16 *)(p + 0x2) = 0;
    *(s16 *)(p + 0x4) = 1;
    *(s16 *)(p + 0x6) = 1;
    *(s16 *)(p + 0x8) = 20000;
    *(s16 *)(p + 0xA) = 20000;
    *(s32 *)(p + 0xC) = 0;
    *(s32 *)(p + 0x10) = 0;
    *(s32 *)(p + 0x14) = 20000;
    *(s32 *)(p + 0x18) = 20000;
    *(s32 *)(p + 0x1C) = 0;
    *(s32 *)(p + 0x20) = 0;
    *(char **)(p + 0x28) = p + 0x30;
    *(s32 *)(p + 0x24) = 0;
    *(u8 *)(p + 0x30) = 0;
    *(u8 *)(p + 0x31) = 0;
    *(u8 *)(p + 0x32) = 0;
    *(u8 *)(p + 0x33) = 2;
    *(u8 *)(p + 0x34) = 0;
    *(u8 *)(p + 0x35) = 0;
    *(f32 *)(p + 0x38) = 400.0f;
    *(f32 *)(p + 0x3C) = 2400.0f;
    *(f32 *)(p + 0x40) = 1.0f;
    *(f32 *)(p + 0x44) = 0.75f;
    *(s32 *)(p + 0x48) = 0;
    *(s32 *)(p + 0x4C) = 0;
    *(f32 *)(p + 0x74) = D_08933B04;
    *(f32 *)(p + 0x78) = D_08933B08;
    *(f32 *)(p + 0x80) = D_08933B10;
    *(f32 *)(p + 0x88) = D_08933B18;
    *(f32 *)(p + 0x94) = D_08933B24;
    *(f32 *)(p + 0x98) = D_08933B28;
    *(f32 *)(p + 0xA0) = D_08933B30;
    *(f32 *)(p + 0xA8) = D_08933B38;
    *(f32 *)(p + 0xB4) = D_08933B44;
    *(f32 *)(p + 0xB8) = D_08933B48;
    *(f32 *)(p + 0xC0) = D_08933B50;
    *(f32 *)(p + 0xC8) = D_08933B58;
    *(f32 *)(p + 0xD4) = D_08933B64;
    *(f32 *)(p + 0xD8) = D_08933B68;
    *(f32 *)(p + 0xE0) = D_08933B70;
    *(f32 *)(p + 0xE8) = D_08933B78;
    *(f32 *)(p + 0xF4) = D_08933B84;
    *(f32 *)(p + 0xF8) = D_08933B88;
    *(f32 *)(p + 0x100) = D_08933B90;
    *(f32 *)(p + 0x108) = D_08933B98;
    *(s32 *)(p + 0x50) = 0x3F5F66F3;
    *(s32 *)(p + 0x54) = 0;
    *(s32 *)(p + 0x58) = 0;
    *(s16 *)(p + 0x5E) = 0;
    *(s16 *)(p + 0x5C) = 0;
    *(char **)(arg0 + 0xAAC) = p;
}
