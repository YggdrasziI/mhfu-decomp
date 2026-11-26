/* unit_0882619C: 0x0882619C-0x088262B0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * Copy propagation is off: the sub-record address (+0x5BC) is kept in a
 * saved register across the call instead of being folded into the load.
 */

#pragma opt_propagation off

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;

typedef struct {
    u8 pad[8];
    u8 b8;
} Sub5BC;

extern s32 D_08A62C50;
extern s32 D_08A62C68;
extern void func_088264F4(char *, u16);
extern u8 func_0885B718(s32, char *, s32, s32);

void func_0882619C(char *arg0, u16 arg1) {
    if (*(char **)(arg0 + 0x5A8) != 0) {
        Sub5BC *sub;
        u8 old;

        sub = (Sub5BC *)(arg0 + 0x5BC);
        old = *(u8 *)(arg0 + 0x5C4);

        func_088264F4(arg0, arg1);
        if (old != sub->b8) {
            *(u16 *)(arg0 + 0x1208) = arg1 & 0xA0;
        }
        *(s32 *)(arg0 + 0x5E8) |= 4;
        *(s32 *)(arg0 + 0x528) |= 0x800;
        *(u8 *)(arg0 + 0x5FE) = 1;
        if (*(u16 *)(arg0 + 0x1208) != 0) {
            if ((D_08A62C68 & *(u16 *)(arg0 + 0x1208)) != 0) {
                *(s16 *)(arg0 + 0x5FC) = 0x18;
            } else {
                *(u16 *)(arg0 + 0x1208) = 0;
            }
        }
        if (*(u16 *)(arg0 + 0x1208) == 0) {
            if (func_0885B718(D_08A62C50, *(char **)(arg0 + 0x5A8), 1, 0) == 1) {
                *(s16 *)(arg0 + 0x5FC) = *(s16 *)(*(char **)(arg0 + 0x5A8) + 2) + 0x18;
            } else {
                *(s16 *)(arg0 + 0x5FC) = 9;
            }
        }
    } else {
        *(s32 *)(arg0 + 0x5E8) &= ~4;
    }
}
