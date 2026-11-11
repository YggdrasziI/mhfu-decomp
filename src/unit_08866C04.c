/* unit_08866C04: 0x08866C04-0x08866CB8 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern s32 D_089CBBE0;
extern s32 D_09A0B540;
extern int func_08812144(s32, s32, s32, s32);
extern s32 func_08812610(s32, s32);
extern s32 func_08898694(s32, s32, s32);

void func_08866C04(char *arg0, s32 arg1, s32 arg2) {
    if (arg1 > 0) {
        *(s32 *)(arg0 + 0x80240) = arg1;
        *(s32 *)(arg0 + 0x80248) = func_08898694(D_09A0B540, 3, arg1);
        *(s32 *)(arg0 + 0x80244) = 0;
    }
    *(s32 *)(arg0 + 0x8024C) = arg2;
    func_08812144(D_089CBBE0, 8, arg2, -1);
    *(s32 *)(arg0 + 0x80254) = func_08812610(D_089CBBE0, 8);
    *(s32 *)(arg0 + 0x80250) = 0;
}
