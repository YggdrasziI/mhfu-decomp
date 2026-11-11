/* unit_088EF2C8: 0x088EF2C8-0x088EF348 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef short s16;
typedef int s32;

extern s32 D_09A4F0D4;
extern char *D_09A4F0D8;
extern s32 D_09A4F0DC;
extern char *D_09A4F0E0;
extern s32 D_09A4F0E4;
extern s16 D_09A4F0E8;
extern s16 D_09A4F0EA;
extern char D_09A4F0FC;
extern char D_09B795C0;
extern int func_088AD1EC(s32 *);

s32 func_088EF2C8(void) {
    D_09A4F0D4 = 0x10;
    D_09A4F0D8 = &D_09B795C0;
    D_09A4F0DC = 0x10000;
    D_09A4F0E0 = &D_09A4F0FC;
    D_09A4F0E4 = 0x400;
    D_09A4F0E8 = 1;
    D_09A4F0EA = 3;
    func_088AD1EC(&D_09A4F0D4);
    return 0x10000;
}
