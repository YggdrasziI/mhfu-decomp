/* unit_088BFBEC: 0x088BFBEC-0x088BFCF0 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef int s32;

extern char D_089B4DC4;
extern char D_089B4DD4;
extern int func_0880C464(void *, s32, s32);
extern int func_0880ED70(void *, void *);
extern int sceUtilitySavedataInitStart(void *);

void func_088BFBEC(char *arg0) {
    func_0880C464(arg0 + 0x18, 0, 0x600);
    func_0880C464(arg0 + 0xAEC, 0, 0x24);
    func_0880C464(arg0 + 0xB10, 0, 0x12C0);
    func_0880C464(arg0 + 0x4990, 0, 0x48);
    *(s32 *)(arg0 + 0x18) = 0x600;
    *(s32 *)(arg0 + 0x1C) = 1;
    *(s32 *)(arg0 + 0x20) = 1;
    *(s32 *)(arg0 + 0x24) = 0x32;
    *(s32 *)(arg0 + 0x28) = 0x34;
    *(s32 *)(arg0 + 0x2C) = 0x33;
    *(s32 *)(arg0 + 0x30) = 0x29;
    *(s32 *)(arg0 + 0x48) = 0xC;
    func_0880ED70(arg0 + 0x54, &D_089B4DD4);
    func_0880ED70(arg0 + 0x64, &D_089B4DC4);
    *(s32 *)(arg0 + 0x604) = 0;
    *(s32 *)(arg0 + 0x608) = 0;
    *(char **)(arg0 + 0x610) = (char *) (arg0 + 0xAEC);
    *(s32 *)(arg0 + 0xAEC) = 0;
    *(s32 *)(arg0 + 0xAF0) = 0xC8;
    *(s32 *)(arg0 + 0xAF4) = 3;
    *(s32 *)(arg0 + 0xB04) = 0;
    *(char **)(arg0 + 0xB08) = (char *) (arg0 + 0xB10);
    *(char **)(arg0 + 0xB0C) = (char *) (arg0 + 0x4990);
    sceUtilitySavedataInitStart(arg0 + 0x18);
    *(s8 *)(arg0 + 0x970) = 1;
}
