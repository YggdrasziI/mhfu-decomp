/* unit_08872E48: 0x08872E48-0x08872E84 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;

typedef struct {
    unsigned char value : 7;
    unsigned char flag : 1;
} Bits;

void func_08872E48(s32 arg0, s32 arg1) {
    Bits *b = (Bits *)((char *)(arg0 + arg1) + 0x75C);
    b->flag = 0;
    b->value = 0x7F;
}
