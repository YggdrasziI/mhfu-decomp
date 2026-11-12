/* unit_08834400: 0x08834400-0x0883448C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef short s16;
typedef int s32;

extern char *D_089CC438;
extern s32 D_08A62D8C;
extern s32 *D_09B22D70;
extern void func_0883448C(void *);
extern int func_08883988(s32, s32, s32, s32, s32, s32, s32, s32, s32);

void func_08834400(char *arg0) {
    if (*D_09B22D70 != 0xC) {
        *(s8 *)(D_089CC438 + 0x10) = 1;
        *D_09B22D70 = 0xC;
        func_0883448C(arg0);
        *(s8 *)(arg0 + 0x111D) = 1;
        *(s16 *)(arg0 + 0x111E) = 0;
        func_08883988(D_08A62D8C, 0, 0x11, 0, 0, 0, 0, 0, 0);
    }
}
