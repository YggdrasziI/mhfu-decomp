/* unit_08812B1C: 0x08812B1C-0x08812B9C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef int s32;

extern char *D_089CC438;
extern s32 D_09A4F0C4;
extern void func_08812B9C(void *);
extern int func_08812BD0(char *);
extern void func_08814984(void *);
extern s32 func_088DCEBC(s32, u8);

void func_08812B1C(char *arg0) {
    *(s32 *)(arg0 + 0xB10) = 0;
    *(s8 *)(arg0 + 0xB3C) = 1;
    func_08812B9C(arg0);
    *(s32 *)(arg0 + 0xB10) = 0;
    *(s32 *)(arg0 + 0xA84) = func_088DCEBC(D_09A4F0C4, *(u8 *)(D_089CC438 + 0x28));
    *(s8 *)(arg0 + 0xB00) = 0;
    *(s8 *)(arg0 + 0xAE0) = 0;
    *(s8 *)(arg0 + 0xAC0) = 0;
    *(s8 *)(arg0 + 0xA81) = 0;
    *(s8 *)(arg0 + 0xA8A) = 0;
    *(s8 *)(arg0 + 0xA88) = 0;
    *(s32 *)(arg0 + 0xA7C) = 0;
    *(s8 *)(arg0 + 0xA80) = 0;
    func_08814984(arg0);
    func_08812BD0(arg0);
}
