/* unit_088A34E4: 0x088A34E4-0x088A3554 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern s32 D_09A0DA74;
extern s32 D_09A0DA88;
extern int func_08897A08(s32, s32);
extern int func_08897A78(s32, s32, s32);
extern int func_08897B48(s32, s32);

void func_088A34E4(s32 arg0) {
    if (D_09A0DA88 == 1) {
        func_08897A08(D_09A0DA74, 0x100);
        func_08897A78(D_09A0DA74, 0x8000, 0x8000);
        func_08897B48(D_09A0DA74, 0);
    }
    D_09A0DA88 -= 1;
}
