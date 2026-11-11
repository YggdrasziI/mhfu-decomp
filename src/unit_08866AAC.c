/* unit_08866AAC: 0x08866AAC-0x08866B5C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern s32 D_089CBBE0;
extern s32 D_09A0B540;
extern int func_08812144(s32, s32, s32, s32);
extern s32 func_08812610(s32, s32);
extern s32 func_08898694(s32, s32, s32);

void func_08866AAC(char *arg0, s32 arg1, s32 arg2) {
    *(s32 *)(arg0 + 0x80228) = arg1;
    *(s32 *)(arg0 + 0x80230) = func_08898694(D_09A0B540, 2, arg1);
    *(s32 *)(arg0 + 0x8022C) = 0;
    *(s32 *)(arg0 + 0x80234) = arg2;
    func_08812144(D_089CBBE0, 7, arg2, -1);
    *(s32 *)(arg0 + 0x8023C) = func_08812610(D_089CBBE0, 7);
    *(s32 *)(arg0 + 0x80238) = 0;
}
