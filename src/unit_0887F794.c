/* unit_0887F794: 0x0887F794-0x0887F7F8 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef short s16;
typedef int s32;

extern char *D_08A62D84;
extern void func_0887FBF8(char *);
extern int func_08880378(char *);

char *func_0887F794(char *arg0) {
    D_08A62D84 = arg0;
    func_0887FBF8(arg0);
    func_08880378(arg0);
    *(s32 *)arg0 = 0;
    *(s32 *)(arg0 + 4) = 0;
    *(s32 *)(arg0 + 8) = -1;
    *(s32 *)(arg0 + 0x10) = -1;
    *(s8 *)(arg0 + 0x14) = 0;
    *(s8 *)(arg0 + 0x158) = 0;
    *(s16 *)(arg0 + 0x174) = 0;
    *(s16 *)(arg0 + 0x176) = 0;
    *(s16 *)(arg0 + 0x178) = 0;
    *(s16 *)(arg0 + 0x17A) = 0;
    return arg0;
}
