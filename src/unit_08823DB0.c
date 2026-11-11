/* unit_08823DB0: 0x08823DB0-0x08823DEC (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef short s16;
typedef int s32;

void func_08823DB0(char *arg0) {
    *(s8 *)(arg0 + 0x120A) = 0;
    *(s8 *)(arg0 + 0x120B) = 0;
    *(s8 *)(arg0 + 0x120E) = 0;
    *(s8 *)(arg0 + 0x120F) = 0;
    *(s32 *)(arg0 + 0x1214) = 0xE10;
    *(s8 *)(arg0 + 0x1218) = 0;
    *(s8 *)(arg0 + 0x5FE) = 6;
    *(s16 *)(arg0 + 0x5FC) = 4;
    *(s32 *)(arg0 + 0x5E8) = (s32) (*(s32 *)(arg0 + 0x5E8) | 4);
}
