/* unit_088C12BC: 0x088C12BC-0x088C1344 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef short s16;
typedef int s32;
typedef float f32;

extern f32 D_089B4E60;
extern char D_089B4E70;
extern char D_089B4EA0;
extern s32 D_089CBBE4;
extern int func_088158D8(s32, char *, char *, f32);
extern int func_08815D64(s32, char *, char *, f32);

void func_088C12BC(s32 arg0, s16 arg1) {
    s32 temp_v1;
    s32 temp_v1_2;

    if (arg1 != 2) {
        temp_v1 = arg1 * 0x10;
        func_088158D8(D_089CBBE4, &D_089B4E70 + temp_v1, &D_089B4EA0 + temp_v1, D_089B4E60);
        return;
    }
    temp_v1_2 = arg1 * 0x10;
    func_08815D64(D_089CBBE4, &D_089B4E70 + temp_v1_2, &D_089B4EA0 + temp_v1_2, D_089B4E60);
}
