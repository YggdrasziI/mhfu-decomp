/* unit_08881114: 0x08881114-0x088812B4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u16 unk0[4];
    u16 unk8[4];
    u16 unk10[4];
    u16 unk18[4];
    u8 unk20[0xC];
    s32 unk2C;
    s32 unk30;
} Sub8B64;

typedef struct {
    char pad0[0x8B64];
    Sub8B64 unk8B64;
} Obj;

extern s32 D_08A62D84;
extern u8 func_0887FE3C(s32, s32);
extern u16 func_0887FDF4(s32, s32);
extern u16 func_0887FE24(s32, s32);
extern u16 func_0887FE0C(s32, s32);
extern void func_088802C4(s32, s32, s32);
extern void func_0887FD64(s32, s32);

void func_08881114(Obj *arg0, s32 arg1, u16 arg2, u16 arg3, u16 arg4, u8 arg5, s32 arg6) {
    Sub8B64 *base;
    u8 found;

    base = &arg0->unk8B64;
    found = 0;
    if (func_0887FE3C(D_08A62D84, arg1) == 1) {
        found = 1;
    } else {
        if (func_0887FDF4(D_08A62D84, arg1) != 0xFFFF) {
            found = 1;
        }
        if (func_0887FE24(D_08A62D84, arg1) != 0xFFFF) {
            found = 1;
        }
        if (func_0887FE0C(D_08A62D84, arg1) != 0xFFFF) {
            found = 1;
        }
    }
    if (found == 1) {
        func_088802C4(D_08A62D84, arg1, 0);
        func_0887FD64(D_08A62D84, arg1);
    }
    if (arg0->unk8B64.unk30 == 0) {
        base->unk0[arg6] = arg2;
        base->unk8[arg6] = arg3;
        base->unk10[arg6] = arg4;
        base->unk18[arg6] = arg1;
        base->unk20[arg6] = arg5;
    }
    if (arg0->unk8B64.unk30 == 0) {
        arg0->unk8B64.unk30 = 5;
        base->unk2C = arg6;
    }
}
