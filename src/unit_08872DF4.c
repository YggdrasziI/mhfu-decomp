/* unit_08872DF4: 0x08872DF4-0x08872E2C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;

typedef struct {
    u8 val : 7;
    u8 flag : 1;
} Bits;

void func_08872DF4(s32 arg0, s32 arg1, s32 arg2) {
    Bits *b = (Bits *)((char *)(arg0 + arg1) + 0x75C);
    b->flag = 1;
    b->val = arg2;
}
