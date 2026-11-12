/* unit_08825E78: 0x08825E78-0x08825EE8 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef short s16;
typedef int s32;

extern s32 D_08A62D8C;
extern s16 func_08826734(s32, s32);
extern int func_08883988(s32, s32, s32, s32, s32, s32, s32, s32, s32);

void func_08825E78(char *arg0) {
    *(u8 *)(arg0 + 0x585) = (u8) (*(u8 *)(arg0 + 0x585) - 1);
    func_08883988(D_08A62D8C, 0, 0x14, 0, 0, 0, 0, 0, 0);
    *(s16 *)(arg0 + 0x5FC) = (s16) (func_08826734((s32) arg0, (s32) *(u8 *)(arg0 + 0x586)) + 0x18);
}
