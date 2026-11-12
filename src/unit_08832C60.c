/* unit_08832C60: 0x08832C60-0x08832CE4 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

extern char D_0893878C;
extern u16 D_089ACAD8;
extern s32 D_089CC438;
extern char *D_08A631A8;
extern s32 func_0882A9DC(s32, s32, s32, s32);
extern void *func_0885151C(int, u16);
extern void func_08890DE8(void *, s8, u8);
extern int func_088915B0(char *, s16, s16, s32, char *);

void func_08832C60(s32 arg0, s32 arg1) {
    char *temp_s0;

    temp_s0 = &D_0893878C + ((arg1 & 0xFF) * 8);
    func_0882A9DC(arg0, (s32) *(u16 *)temp_s0, (s32) *(u16 *)(temp_s0 + 2), 0x38);
    func_08890DE8(D_08A631A8, 0xE, 0xEU);
    func_088915B0(D_08A631A8, *(s16 *)(temp_s0 + 4), *(s16 *)(temp_s0 + 6), 0, func_0885151C(D_089CC438, D_089ACAD8));
}
