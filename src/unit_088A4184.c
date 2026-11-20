/* unit_088A4184: 0x088A4184-0x088A4248 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef short s16;
typedef int s32;

extern s32 D_09A0E3B0;
extern s32 D_09A0E3B4;
extern s32 D_09A0E3B8;
extern s32 D_09A0E3BC;
extern s32 D_09A0E3C0;
extern s32 D_09A0E3C4;
extern s32 D_09A0E3C8;
extern s32 D_09A0E3CC;
extern int memset(s32 *, s32, s32);
extern void func_088A412C(void);
extern int func_088A4344(s32 *);

void func_088A4184(void) {
    s32 var_s1;
    char *var_s0;

    func_088A412C();
    memset(&D_09A0E3CC, 0, 0x580);
    var_s1 = 0;
    var_s0 = (char *) (&D_09A0E3CC);
    do {
        *(s16 *)(var_s0 + 6) = var_s1;
        *(s32 *)(var_s0 + 8) = (s32) (1 << var_s1);
        func_088A4344((int *) (var_s0));
        var_s1 += 1;
        var_s0 += 0x2C;
    } while (var_s1 < 0x20);
    memset(&D_09A0E3B0, 0, 0x1C);
    D_09A0E3B0 = -1;
    D_09A0E3B4 = 0;
    D_09A0E3B8 = 0;
    D_09A0E3BC = 0;
    D_09A0E3C0 = 0;
    D_09A0E3C4 = 1;
    D_09A0E3C8 = 0;
}
