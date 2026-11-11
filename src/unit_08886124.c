/* unit_08886124: 0x08886124-0x0888617C (ULES01213)
 *
 * Bounds (hypothesis): 4 small functions between code still in assembly.
 */

typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

u16 func_08886124(char *arg0) {
    return *(u16 *)(arg0 + 0x20);
}

s32 func_0888612C(char *arg0) {
    return *(s32 *)(arg0 + 0x24);
}

void func_08886134(char *arg0) {
    s32 temp_a1;
    s32 temp_a1_2;

    temp_a1 = *(s32 *)(arg0 + 0x14);
    if (temp_a1 & 0x10) {
        *(s32 *)(arg0 + 0x14) = (s32) (temp_a1 ^ 0x10);
    }
    temp_a1_2 = *(s32 *)(arg0 + 0x14);
    if (temp_a1_2 & 0x20) {
        *(s32 *)(arg0 + 0x14) = (s32) (temp_a1_2 ^ 0x20);
    }
}

s32 func_0888616C(char *arg0) {
    return (u32) (*(s32 *)(arg0 + 4) - 8) < 2U;
}
