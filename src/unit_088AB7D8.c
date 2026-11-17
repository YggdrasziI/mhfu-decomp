/* unit_088AB7D8: 0x088AB7D8-0x088AB980 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088AB6D0 and a function still
 * in assembly. Its jump table (0x08932098-0x089320D0) is linked from this
 * unit.
 */

typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    char unk0[0x39];
    u8 unk39;
    u8 unk3A;
    char unk3B[5];
    u8 unk40;
    char unk41[0x20];
    u8 unk61;
    u16 unk62;
    u16 unk64;
    char unk66[0x26];
} Rec8C;

typedef struct {
    Rec8C unk0[8];
} Unk089CC438;

typedef struct {
    char unk0[0x56C];
    u16 unk56C[8];
} Unk089CBBEC;

extern Unk089CBBEC *D_089CBBEC;
extern Unk089CC438 *D_089CC438;
extern s32 D_08A62C7C;
extern char *D_09A4F06C;
extern void func_088702F0(s32, s32, char *);
extern void func_088AB500(u8 *arg0, u8 *arg1, char *arg2);
extern void func_088AB514(s32, s32, char *);

void func_088AB7D8(s32 arg0, s32 arg1, char *arg2) {
    u8 sp1F;
    u8 sp1E;

    func_088AB500(&sp1F, &sp1E, arg2);
    switch (sp1E) {
    case 1:
        return;
    case 2:
        D_089CC438->unk0[(u8) arg1].unk40 = *(u8 *)(arg2 + 0xC);
        D_089CC438->unk0[(u8) arg1].unk3A = *(u8 *)(arg2 + 0xD);
        D_089CC438->unk0[(u8) arg1].unk39 = *(u8 *)(arg2 + 4);
        D_089CC438->unk0[(u8) arg1].unk61 = *(u8 *)(arg2 + 5);
        D_089CC438->unk0[(u8) arg1].unk62 = *(u16 *)(arg2 + 8);
        D_089CC438->unk0[(u8) arg1].unk64 = *(u8 *)(arg2 + 6);
        if (*((u8 *) D_089CC438 + 0x28) != *((u8 *) D_089CC438 + 0x420)) {
            return;
        }
        break;
    case 4:
    case 11:
        if (sp1E == 11) {
            func_088AB514(arg0, 5, arg2 + 4);
        }
        break;
    case 6:
        func_088702F0(D_08A62C7C, arg1, arg2 + 4);
        break;
    case 9:
        D_089CBBEC->unk56C[(u8) arg1] = 0;
        break;
    case 0:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        break;
    case 13:
        *(u8 *)(D_09A4F06C + 0x98) |= 1 << (u8) arg1;
        break;
    }
}
