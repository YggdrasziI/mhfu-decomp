/* unit_0885C580: 0x0885C580-0x0885C5BC (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned short u16;
typedef int s32;

extern char D_0899D198;
extern s32 D_089CC438;
extern u16 *func_08856884(s32);

char *func_0885C580(void) {
    return &D_0899D198 + (*func_08856884(D_089CC438) * 0x18);
}
