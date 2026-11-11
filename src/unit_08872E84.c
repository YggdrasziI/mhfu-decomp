/* unit_08872E84: 0x08872E84-0x08872ED4 (ULES01213)
 *
 * Bounds (hypothesis): 3 small functions between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;

u8 func_08872E84(s32 arg0, s32 arg1) {
    return *(u8 *)((char *)((arg1 + arg0)) + 0x75C);
}

s32 func_08872E90(s32 arg0, s32 arg1) {
    return *(u8 *)((char *)((arg0 + arg1)) + 0x75C) & 0x7F;
}

void func_08872EA0(char *arg0, char *arg1) {
    *(u8 *)(arg0 + 0x75C) = (u8) *(u8 *)arg1;
    *(u8 *)(arg0 + 0x75D) = (u8) *(u8 *)(arg1 + 1);
    *(u8 *)(arg0 + 0x75E) = (u8) *(u8 *)(arg1 + 2);
    *(u8 *)(arg0 + 0x75F) = (u8) *(u8 *)(arg1 + 3);
    *(u8 *)(arg0 + 0x760) = (u8) *(u8 *)(arg1 + 4);
    *(u8 *)(arg0 + 0x761) = (u8) *(u8 *)(arg1 + 5);
}
