/* unit_088808DC: 0x088808DC-0x08880A70 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

extern s32 D_08A62D84;
extern u8 func_0887FE3C(s32, s32);
extern u16 func_0887FDF4(s32, s32);
extern u16 func_0887FE24(s32, s32);
extern u16 func_0887FE0C(s32, s32);
extern void func_088802C4(s32, s32, s32);
extern void func_0887FD04(s32, s32);
extern void func_0887FD48(s32, s32);
extern void func_0887FD2C(s32, s32);

typedef struct {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
} Ids;

s32 func_088808DC(char *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    Ids *p;
    u8 changed = 0;

    if (func_0887FE3C(D_08A62D84, arg1) == 1) {
        changed = 1;
    } else {
        if (func_0887FDF4(D_08A62D84, arg1) != arg2) {
            changed = 1;
        } else {
            arg2 = 0xFFFF;
        }
        if (func_0887FE24(D_08A62D84, arg1) != arg3) {
            changed = 1;
        } else {
            arg3 = 0xFFFF;
        }
        if (func_0887FE0C(D_08A62D84, arg1) != arg4) {
            changed = 1;
        } else {
            arg4 = 0xFFFF;
        }
    }
    if (changed == 1) {
        func_088802C4(D_08A62D84, arg1, 0);
        if (arg2 != 0xFFFF) {
            func_0887FD04(D_08A62D84, arg1);
        }
        if (arg3 != 0xFFFF) {
            func_0887FD48(D_08A62D84, arg1);
        }
        if (arg4 != 0xFFFF) {
            func_0887FD2C(D_08A62D84, arg1);
        }
    }
    if (*(s32 *)(arg0 + 0x8B94) == 0) {
        p = (Ids *)(arg0 + 0x8B2C);
        p->unk6 = arg1;
        p->unk0 = arg2;
        p->unk2 = arg3;
        p->unk4 = arg4;
        *(s32 *)(arg0 + 0x8B94) = 2;
        return 1;
    }
    return 0;
}
