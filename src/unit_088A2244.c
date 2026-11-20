/* unit_088A2244: 0x088A2244-0x088A232C (ULES01213)
 *
 * Bounds (hypothesis): 1 function before unit_088A232C.
 * Its jump table (0x08931F38-0x08931F50) is linked from this unit.
 */

typedef int s32;
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;

extern void func_088979B4(s32, s32, s32);
extern int memset(char *, s32, s32);
extern int func_08897A08(s32, s32);
extern void func_08897AE0(s32, s32, s32, char *);
extern void func_088A1798(void *);
extern void func_088A2410(void *);

typedef struct {
    char unk0[0x24];
    s32 unk24;
    s32 unk28;
    char unk2C[0x28];
    s32 unk54;
    s32 unk58;
    s32 unk5C;
    char unk60[0x34];
    s32 unk94;
    char *unk98[2];
} T;

void func_088A2244(T *arg0) {
    switch (arg0->unk54) {
    case 3:
        func_088979B4(arg0->unk24, 0, 0);
        memset(arg0->unk98[arg0->unk28], 0, arg0->unk94);
        func_08897A08(arg0->unk24, 0x40);
        func_08897AE0(arg0->unk24, 0, 0, arg0->unk98[arg0->unk28]);
        func_08897AE0(arg0->unk24, 0, 0, 0);
    case 1:
    case 2:
    case 4:
        func_088A1798(arg0);
        arg0->unk54 = 5;
    case 0:
    case 5:
        arg0->unk54 = 0;
        break;
    default:
        arg0->unk5C = arg0->unk54;
        arg0->unk58 = 1;
        arg0->unk54 = 6;
        func_088A2410(arg0);
        break;
    }
}
