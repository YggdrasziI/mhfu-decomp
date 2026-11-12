/* unit_088B2BC0: 0x088B2BC0-0x088B2C20 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef int s32;

extern char D_09A29684;
extern char D_09A29688;
extern s8 D_09A299A9;
extern int func_0880C464(void *, s32, s32);
extern s32 func_088B2704(s32);

void func_088B2BC0(char *arg0) {
    char sp1C[0x14];

    *(u8 *)(arg0 + 0x22) = (u8) (*(u8 *)(arg0 + 0x22) + 1);
    *(s32 *)(arg0 + 0x14) = 3;
    D_09A299A9 = 0;
    func_0880C464(&D_09A29684, 0, 4);
    func_0880C464(&D_09A29688, 0, 0x320);
    func_088B2704((s32) sp1C);
}
