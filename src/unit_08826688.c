/* unit_08826688: 0x08826688-0x088266CC (ULES01213)
 *
 * Bounds (hypothesis): 1 field reset, between unrelated code.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;

void func_08826688(char *p) {
    *(u8 *)(p + 0x5B8) = 0;
    *(u8 *)(p + 0x586) = 0;
    *(u8 *)(p + 0x5B9) = 0;
    *(u8 *)(p + 0x5B1) = 0xFF;
    *(u8 *)(p + 0x5B0) = 0xFF;
    *(u16 *)(p + 0x5AE) = 0xFFFF;
    *(u16 *)(p + 0x5AC) = 0xFFFF;
    *(s16 *)(p + 0x5B4) = -1;
    *(int *)(p + 0x5A8) = 0;
    *(u32 *)(p + 0x528) &= ~4;
}
