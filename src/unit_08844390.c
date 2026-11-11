/* unit_08844390: 0x08844390-0x088443EC (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef int s32;

extern int func_088443EC(char *, s32);

void func_08844390(char *arg0, s32 arg1) {
    if ((func_088443EC(arg0, arg1) & 0xFF) && (*(u8 *)(arg0 + 0x52D) == 0) && (*(u8 *)(arg0 + 0x5DD) == 0) && (*(u8 *)(arg0 + 0x5DB) == 0)) {
        *(s8 *)(arg0 + 0x577) = 0x1A;
    }
}
