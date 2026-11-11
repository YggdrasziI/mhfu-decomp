/* unit_08876574: 0x08876574-0x088765C0 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef int s32;

extern s32 D_08A62D8C;
extern int func_08882C24(s32, s32, s32, s32);

void func_08876574(char *arg0) {
    func_08882C24(D_08A62D8C, 0, 4, 0x46);
    *(s8 *)(arg0 + 0xC1) = 1;
    *(s8 *)(arg0 + 0xC2) = 0;
    *(s8 *)(arg0 + 0xC3) = 4;
}
