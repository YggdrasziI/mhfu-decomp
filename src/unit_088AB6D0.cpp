/* unit_088AB6D0: 0x088AB6D0-0x088AB7D8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between two functions still in assembly.
 * Its jump table (0x08932074-0x08932098) is linked from this unit.
 *
 * C++: the code only matches when compiled as C++ (bool test, structures
 * copied member by member).
 */

typedef int s32;
typedef signed char s8;
typedef unsigned char u8;

typedef struct {
    u8 unk0;
    u8 unk1;
    struct {
        float x;
        float y;
    } unk4;
} MsgA;

typedef struct {
    u8 unk0;
    u8 unk1;
    s8 unk2[6];
} MsgB;

typedef struct {
    s32 unk0;
    union {
        MsgA a;
        MsgB b;
    } u;
} Msg;

extern "C" {

extern char *D_08A631A0;
extern void func_088AB4DC(s32, s32, s32, s32, Msg *);

void func_088AB6D0(s32 arg0, s32 arg1, void *arg2) {
    Msg msg;
    s32 size;

    if ((bool) (*(s32 *)(D_08A631A0 + 0xF7A57C) & 1) == 0) {
        return;
    }
    switch ((u8) arg1) {
    case 1:
        size = 0xC;
        msg.u.a = *(MsgA *) arg2;
        break;
    case 2:
        size = 0xC;
        msg.u.a = *(MsgA *) arg2;
        break;
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
        size = 8;
        msg.u.b = *(MsgB *) arg2;
        break;
    case 0:
        break;
    }
    func_088AB4DC(7, arg1, size, 0, &msg);
}

}
