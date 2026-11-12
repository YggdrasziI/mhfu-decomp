/* unit_088BA5BC: 0x088BA5BC-0x088BA664 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef int s32;

extern char *D_089CBBEC;
extern s32 D_08A631A8;
extern void func_08825DA8(void *);
extern void func_0882DCA0(s32, s32, s32, s32, s32, s32);
extern void func_08890DE8(void *, s8, u8);
extern int func_08890E08(s32, s32);

void func_088BA5BC(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    char *temp_s0;

    temp_s0 = D_089CBBEC;
    *(s8 *)(temp_s0 + 0x534) = 0xB;
    func_08890E08(D_08A631A8, 2);
    func_08825DA8(temp_s0);
    func_08890DE8((char *) D_08A631A8, 0xE, 0xEU);
    func_0882DCA0((s32) D_089CBBEC, arg0 & 0xFFFF, arg1 & 0xFFFF, arg2 & 0xFFFF, arg3 & 0xFFFF, 0xFF);
}
