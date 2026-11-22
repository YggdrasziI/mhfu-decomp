/* unit_08872AAC: 0x08872AAC-0x08872B2C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    u8 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
    u16 unk8;
    u16 unkA;
} Msg;

extern "C" {
extern char *D_089CC438;
extern s32 D_089CBBE4;
extern s32 D_09A1DAEC;
extern void func_08813D40(s32);
extern void func_088AB514(s32, s32, Msg *);
}

static inline bool is_own(char *obj) {
    return *(u16 *)(obj + 0x1E6) == *(u8 *)(D_089CC438 + 0x28);
}

extern "C" {
void func_08872AAC(char *arg0, char *arg1) {
    Msg msg;

    *(u8 *)(D_089CC438 + 0x418) = 1;
    *(s32 *)(arg0 + 0x678) = 0x4650;
    if (is_own(arg1) == 1) {
        func_08813D40(D_089CBBE4);
        msg.unk0 = 0x13;
        msg.unk2 = 0;
        msg.unk4 = 0;
        msg.unk6 = 0;
        func_088AB514(D_09A1DAEC, 6, &msg);
    }
}
}
