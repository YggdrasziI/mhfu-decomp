/* unit_0885C124: 0x0885C124-0x0885C13C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;

extern char D_089A5B50;

u8 func_0885C124(s32 arg0, char *arg1) {
    return *(&D_089A5B50 + *(u8 *)(arg1 + 5));
}
