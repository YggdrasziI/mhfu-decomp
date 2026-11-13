/* unit_0883D0EC: 0x0883D0EC-0x0883D184 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern int func_0883D290(char *);
extern s32 func_0883D3D4(char *);

void func_0883D0EC(char *arg0) {
    if ((*(s32 *)(arg0 + 0x5E8) & 0x80) && ((func_0883D3D4(arg0) & 0xFF) == 1)) {
        *(s32 *)(arg0 + 0x600) = 0x96;
        *(s32 *)(arg0 + 0x5E8) = (s32) (*(s32 *)(arg0 + 0x5E8) & ~0x80);
    }
    if (!(func_0883D3D4(arg0) & 0xFF)) {
        *(s32 *)(arg0 + 0x600) = 0;
    }
    if (*(s32 *)(arg0 + 0x600) > 0) {
        func_0883D290(arg0);
        *(s32 *)(arg0 + 0x600) = (s32) (*(s32 *)(arg0 + 0x600) - 1);
    }
}
