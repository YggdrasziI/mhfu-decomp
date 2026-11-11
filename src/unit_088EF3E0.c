/* unit_088EF3E0: 0x088EF3E0-0x088EF460 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern s32 D_09A52184;
extern s32 D_09A52188;
extern char *D_09A5218C;
extern char *D_09A52190;
extern char *D_09A52194;
extern char *D_09A52198;
extern char *D_09A5219C;
extern s32 D_09A521A0;
extern s32 D_09A521A4;
extern char func_088E6164;
extern char func_088EF378;
extern char func_088EF380;
extern char func_088EF3A8;
extern char func_088EF3D8;

void func_088EF3E0(char *arg0) {
    *(s32 **)(arg0 + 0x18) = &D_09A52184;
    D_09A5218C = &func_088EF378;
    D_09A52190 = &func_088EF380;
    D_09A52194 = &func_088EF3A8;
    D_09A52198 = &func_088E6164;
    D_09A5219C = &func_088EF3D8;
    D_09A52188 = D_09A521A4;
    D_09A52184 = D_09A521A0;
}
