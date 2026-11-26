/* unit_08825ADC: 0x08825ADC-0x08825D38 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;

extern u16 D_0893867C;
extern u16 D_0893867E;
extern u16 D_08938680;
extern u16 D_08938682;
extern u16 D_08938688;
extern s16 D_0893868A;
extern u8 D_0899D198[][24];
extern char *D_08A631A8;
extern char *D_089CC438;
extern u16 D_089AC864;
extern s32 D_09B22D70;
extern u16 *D_0893AF34[];

extern void func_0882DCA0(char *, u16, u16, u16, u16, s32);
extern void func_08819450(char *, u16, s32, s32, s32);
extern void func_0882E2C0(char *, u16, u16, u16, s32, s32, s32, s32);
extern s32 func_088303A0(char *, u8);
extern void func_08890E38(char *, s8);
extern void func_08890DE8(char *, s8, u8);
extern char *func_0885151C(char *, u16);
extern void func_088920A8(char *, s16, s16, char *, ...);
extern char *func_09A7B790(s32, u16);
extern void func_0882FC50(char *, u16 *, char *, s32);

void func_08825ADC(char *arg0, s32 kind, s32 id, s32 arg3) {
    u8 *rec;
    char *s;
    u8 k;
    s32 i;
    s32 j;

    k = kind;
    if (k < 8 && (i = id & 0xFFFF) != 0xFFFF) {
        if (k == 1 && i > 0x18) {
            func_0882DCA0(arg0, D_0893867C, D_0893867E, D_08938680, D_08938682, 0xFF);
            j = i - 0x18;
            func_08819450(arg0, j, (s16)(D_08938688 + 0x30), D_0893868A, arg3);
            rec = D_0899D198[j];
            func_0882E2C0(arg0, j, D_0893867C + 0x10, D_0893867E + 8, 0x20, 0x20, 1, 0xFF);
            func_08890E38(D_08A631A8, func_088303A0(arg0, rec[2]));
            func_08890DE8(D_08A631A8, 0xC, 0xC);
            s = func_0885151C(D_089CC438, D_089AC864);
            func_088920A8(D_08A631A8, D_0893867C + 0xE, D_0893867E + 0x28, s, rec[2] + 1);
            func_08890E38(D_08A631A8, 0);
        } else {
            switch (k) {
            case 0:
            default:
                func_0882FC50(arg0, &D_0893867C,
                              func_0885151C(D_089CC438, D_0893AF34[(u8)kind][(u16)id]), 0xFF);
                break;
            case 5:
            case 4:
                func_0882FC50(arg0, &D_0893867C,
                              func_09A7B790(D_09B22D70, D_0893AF34[(u8)kind][(u16)id]), 0xFF);
                break;
            }
        }
    }
}
