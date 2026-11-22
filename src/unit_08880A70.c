/* unit_08880A70: 0x08880A70-0x08880CF8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * Field names are not known.
 */

#pragma optimize_for_size off

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    u16 a[4];
    u16 b[4];
    u16 unk10;
    u16 unk12;
    s32 count;
} Req;

extern s32 D_08A62D84;
extern u8 func_0887FE3C(s32, s32);
extern u16 func_0887FDF4(s32, s32);
extern u16 func_0887FE24(s32, s32);
extern u16 func_0887FE0C(s32, s32);
extern void func_088802C4(s32, s32, s32);
extern void func_0887FD64(s32, s32);

s32 func_08880A70(char *arg0, s32 arg1, u16 *arg2, u16 *arg3, s32 arg4, s32 arg5) {
    u8 flag = 0;
    Req *r;
    s32 i;

    if (func_0887FE3C(D_08A62D84, arg1) == 1) {
        flag = 1;
    } else {
        if (func_0887FDF4(D_08A62D84, arg1) != 0xFFFF) {
            flag = 1;
        }
        if (func_0887FE24(D_08A62D84, arg1) != 0xFFFF) {
            flag = 1;
        }
        if (func_0887FE0C(D_08A62D84, arg1) != 0xFFFF) {
            flag = 1;
        }
    }
    if (flag == 1) {
        func_088802C4(D_08A62D84, arg1, 0);
        func_0887FD64(D_08A62D84, arg1);
    }
    if (*(s32 *)(arg0 + 0x8B94) == 0) {
        r = (Req *)(arg0 + 0xB34 + 0x7FF8);
        for (i = 0; i < arg5; i++) {
            r->a[i] = arg2[i];
            r->b[i] = arg3[i];
        }
        r->unk12 = arg1;
        r->unk10 = arg4;
        r->count = arg5;
        *(s32 *)(arg0 + 0x8B94) = 3;
        return 1;
    }
    return 0;
}
