/* unit_088817E8: 0x088817E8-0x08881824 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern char D_089AC1A8;

void func_088817E8(char *arg0, s32 arg1, s32 arg2) {
    *(s32 *)(((arg1 * 4) + (&D_089AC1A8 + (*(s32 *)((char *)arg0 + 0x308BC0) )* 0x54))) = arg2;
}
