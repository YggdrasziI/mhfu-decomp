/* unit_088AE1D4: 0x088AE1D4-0x088AE1EC (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef int s32;

extern char D_09A28944;
extern void func_088ACCE8(char *, s32, s32);

void func_088AE1D4(char *arg0, s32 arg1, s32 arg2) {
    *(s8 *)(arg0 + 0x22) = *(u8 *)(arg0 + 0x22) + 0x1;
    func_088ACCE8(&D_09A28944, arg1, arg2);
}
