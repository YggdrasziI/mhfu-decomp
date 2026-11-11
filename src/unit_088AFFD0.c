/* unit_088AFFD0: 0x088AFFD0-0x088B0010 (ULES01213)
 *
 * Bounds (hypothesis): 2 small functions between code still in assembly.
 */

typedef signed char s8;
typedef unsigned short u16;
typedef int s32;

void func_088AFFD0(char *arg0) {
    *(s8 *)(arg0 + 8) = (s8) ((s32) *(u16 *)(arg0 + 2) >> 8);
    *(s8 *)(arg0 + 9) = (s8) *(u16 *)(arg0 + 2);
}

void func_088AFFE8(char *arg0, s8 arg1) {
    *(s8 *)((char *)((arg0 + *(u16 *)(arg0 + 2))) + 0x18) = arg1;
    *(u16 *)arg0 = (u16) (*(u16 *)arg0 + 1);
    *(u16 *)(arg0 + 2) = (u16) (*(u16 *)(arg0 + 2) + 1);
}
