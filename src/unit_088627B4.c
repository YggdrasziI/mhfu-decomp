/* unit_088627B4: 0x088627B4-0x08862800 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_088627B4 */

typedef unsigned short u16;
typedef int s32;

extern char *func_0886272C(char *arg0, s32 arg1);

char *func_088627B4(char *arg0, s32 arg1, s32 arg2) {
    char *entry = func_0886272C(arg0, arg1);
    return arg0 + *(s32 *)(arg0 + 0x24) + (*(u16 *)(entry + 0x16) * 16) + (arg2 * 16);
}
