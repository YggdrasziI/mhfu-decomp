/* unit_088A9DF4: 0x088A9DF4-0x088A9E28 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

s32 func_088A9CFC();
extern s32 D_09A1D6FC;

void func_088A9DF4(char *arg0) {
    *(s32 *)arg0 = func_088A9CFC();
    *(s32 *)(arg0 + 4) = (s32) D_09A1D6FC;
}
