/* unit_088592A8: 0x088592A8-0x088592E4 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern s32 D_089CBBE0;
extern s32 func_08812610(s32, s32);
extern int sceDisplaySetFrameBuf(s32, s32, s32, s32);

void func_088592A8(char *arg0) {
    sceDisplaySetFrameBuf(func_08812610(D_089CBBE0, *(s32 *)(arg0 + 4) != 0), 0x200, 1, 1);
}
