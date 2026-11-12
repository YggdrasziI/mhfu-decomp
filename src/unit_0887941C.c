/* unit_0887941C: 0x0887941C-0x0887959C (ULES01213)
 *
 * Bounds (hypothesis): 2 small functions between code still in assembly.
 */

typedef short s16;
typedef unsigned short u16;
typedef int s32;

extern char D_089A8870;
extern u16 D_089A88C8;
extern u16 D_089A88CA;
extern u16 D_089A88CC;
extern u16 D_089A88CE;
extern u16 D_089A88D0;
extern u16 D_089A88D2;
extern u16 D_089A88D4;
extern u16 D_089A88D6;
extern u16 D_089A88D8;
extern u16 D_089A88DA;
extern u16 D_089A88DC;
extern u16 D_089A88DE;
extern u16 D_089A88E0;
extern u16 D_089A88E2;
extern u16 D_089A88E4;
extern u16 D_089A88E6;
extern u16 D_089A88E8;
extern u16 D_089A88EA;
extern u16 D_089A88EC;
extern u16 D_089A88EE;
extern s32 D_089CBBEC;
extern s32 D_08A631A8;
extern int func_0882DCA0(s32, u16, u16, u16, u16, s32);
extern int func_08832548(s32, s32);
extern s32 func_08890F70(s32, s32);
extern int func_088920A8(s32, s16, s32, char *, s32);

void func_0887941C(s32 arg0, s32 arg1, s32 arg2) {
    func_088920A8(D_08A631A8, (s16) (0xF0 - ((s32) (func_08890F70(D_08A631A8, arg2) * 8) >> 1)), arg1, &D_089A8870, arg2);
}

void func_08879488(void) {
    func_08832548(D_089CBBEC, 0);
    func_0882DCA0(D_089CBBEC, D_089A88D0, D_089A88D2, D_089A88D4, D_089A88D6, 0xFF);
    func_0882DCA0(D_089CBBEC, D_089A88C8, D_089A88CA, D_089A88CC, D_089A88CE, 0xFF);
    func_0882DCA0(D_089CBBEC, D_089A88D8, D_089A88DA, D_089A88DC, D_089A88DE, 0xFF);
    func_0882DCA0(D_089CBBEC, D_089A88E0, D_089A88E2, D_089A88E4, D_089A88E6, 0xFF);
    func_0882DCA0(D_089CBBEC, D_089A88E8, D_089A88EA, D_089A88EC, D_089A88EE, 0xFF);
}
