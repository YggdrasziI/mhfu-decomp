/* unit_088AB514: 0x088AB514-0x088AB6D0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088AB500 and unit_088AB6D0.
 * Its jump table (0x0893203C-0x08932074) is linked from this unit.
 *
 * C++: bool test, structures copied member by member.
 */

typedef int s32;
typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;

typedef struct {
    s8 unk0;
    s8 unk1;
    s8 unk2;
    s8 unk3;
    s8 unk4;
    s8 unk5;
    s8 unk6;
    s8 unk7;
} Bytes8;

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u16 unk4;
    s16 unk6;
    u8 unk8;
    s8 unk9;
    char unkA[8];
    Bytes8 unk12;
} MsgA;

typedef struct {
    u8 unk0;
    u16 unk2;
    s16 unk4;
    s16 unk6;
    u16 unk8;
    s16 unkA;
} MsgB;

typedef struct {
    s32 unk0;
    union {
        MsgA a;
        MsgB b;
    } u;
} Msg;

typedef struct {
    char unk0[0x39];
    u8 unk39;
    s8 unk3A;
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

extern "C" {

extern Unk089CC438 *D_089CC438;
extern char *D_08A631A0;
extern void func_088AB4DC(s32, s32, s32, s32, Msg *);

void func_088AB514(char *arg0, s32 arg1, void *arg2) {
    Msg msg;
    s32 size;
    u8 idx;

    if ((bool) (*(s32 *)(D_08A631A0 + 0xF7A57C) & 1) == 0) {
        return;
    }
    switch ((u8) arg1) {
    case 1:
        size = 1;
        msg.u.a.unk0 = 4;
        break;
    case 2:
        idx = *((u8 *) D_089CC438 + 0x28);
        msg.u.a.unk0 = D_089CC438->unk0[idx].unk39;
        msg.u.a.unk1 = D_089CC438->unk0[idx].unk61;
        msg.u.a.unk4 = D_089CC438->unk0[idx].unk62;
        msg.u.a.unk2 = D_089CC438->unk0[idx].unk64;
        msg.u.a.unk8 = D_089CC438->unk0[idx].unk40;
        msg.u.a.unk9 = D_089CC438->unk0[idx].unk3A;
        msg.u.a.unk12 = *(Bytes8 *)(arg0 + 0x12);
    case 3:
        size = 8;
        msg.u.a.unk0 = *((u8 *) D_089CC438 + 0x378) + 1;
        msg.u.a.unk6 = ((s16 *)(arg0 + 0xA))[idx];
        *(u16 *)(arg0 + 8) = 0;
        break;
    case 4:
    case 11:
        msg.u.a.unk0 = *(u8 *) arg2;
        size = 1;
        break;
    case 5:
        size = 8;
        break;
    case 6:
        size = 0xC;
        msg.u.b = *(MsgB *) arg2;
        break;
    case 8:
        size = 1;
        break;
    case 9:
        size = 1;
        break;
    case 12:
        size = 1;
        break;
    case 13:
        size = 1;
        break;
    case 0:
    case 7:
    case 10:
        break;
    }
    func_088AB4DC(0xA, arg1, size, 0, &msg);
}

}
