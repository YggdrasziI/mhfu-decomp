/* unit_08862768: 0x08862768-0x088627AC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08862768: address of an entry's data inside a block (hypothesis). */

typedef int s32;
typedef unsigned short u16;

extern char *func_0886272C(char *arg0, s32 arg1);

char *func_08862768(char *arg0, s32 arg1, s32 arg2) {
    char *entry = func_0886272C(arg0, arg1);
    return arg0 + *(s32 *)(arg0 + 0x28) + *(u16 *)(entry + 0x12) + arg2;
}
