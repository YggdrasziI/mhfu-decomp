/* unit_088B4184: 0x088B4184-0x088B41B4 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;

extern s32 func_088B4950(s32);

void func_088B4184(char *arg0) {
    char sp1C[0x14];

    *(u8 *)(arg0 + 0x22) = (u8) (*(u8 *)(arg0 + 0x22) + 1);
    *(s32 *)(arg0 + 0xC) = 0x5A;
    func_088B4950((s32) sp1C);
}
