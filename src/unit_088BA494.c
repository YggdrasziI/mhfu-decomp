/* unit_088BA494: 0x088BA494-0x088BA54C (ULES01213)
 *
 * Bounds (hypothesis): 2 small functions between code still in assembly.
 */

typedef unsigned short u16;
typedef int s32;

extern s32 D_089CBBEC;
extern s32 D_089CC438;
extern int func_08827918(s32, s32, s32, char *, s32, s32);
extern int func_08827AD4(s32, s32, s32, char *, s32, s32);
extern void *func_08851680(int, u16);

void func_088BA494(s32 arg0, s32 arg1, u16 arg2) {
    func_08827918(D_089CBBEC, arg0, arg1, func_08851680(D_089CC438, arg2), 0xE, 0x10);
}

void func_088BA4F0(s32 arg0, s32 arg1, u16 arg2) {
    func_08827AD4(D_089CBBEC, arg0, arg1, func_08851680(D_089CC438, arg2), 0xE, 0x10);
}
