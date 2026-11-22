/* unit_08880E50: 0x08880E50-0x08881114 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * C++: virtual call.
 */

#pragma optimize_for_size off

typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef struct V18_0 { virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual u32 vfunc_18(u16); } V18_0;

extern "C" {

extern char *D_08A62C7C;
extern s32 D_08A62D84;
extern V18_0 *D_089CC434;
extern u8 func_0887FE3C(s32, s32);
extern u16 func_0887FDF4(s32, s32);
extern u16 func_0887FE24(s32, s32);
extern u16 func_0887FE0C(s32, s32);
extern void func_088802C4(s32, s32, s32);
extern void func_0887FD64(s32, s32);
extern void func_0888334C(char *, s32, s32, u32);
extern void func_088832F8(char *, s32, s32, s32);

void func_08880E50(char *arg0, u32 *arg1, u16 *arg2, u16 *arg3, u16 *arg4, u8 *arg5, s32 arg6, s32 arg7, u32 *arg8) {
    char *base;
    u8 found;
    s32 i;
    u32 v;

    base = arg0 + 0xB6C + 0x7FF8;
    for (i = *(s16 *)(D_08A62C7C + 0x5C0); i < arg6; i++) {
        found = 0;
        if (func_0887FE3C(D_08A62D84, arg1[i]) == 1) {
            found = 1;
        } else {
            if (func_0887FDF4(D_08A62D84, arg1[i]) != 0xFFFF) {
                found = 1;
            }
            if (func_0887FE24(D_08A62D84, arg1[i]) != 0xFFFF) {
                found = 1;
            }
            if (func_0887FE0C(D_08A62D84, arg1[i]) != 0xFFFF) {
                found = 1;
            }
        }
        if (found == 1) {
            func_088802C4(D_08A62D84, arg1[i], 0);
            func_0887FD64(D_08A62D84, arg1[i]);
        }
        v = D_089CC434->vfunc_18(arg3[i]);
        if (arg8 != 0) {
            if (v < arg8[i]) {
                v = arg8[i];
            }
        }
        func_0888334C(arg0, 1, arg1[i], v);
        if (*(s32 *)(arg0 + 0x8B94) == 0) {
            ((s16 *)base)[i] = arg2[i];
            ((s16 *)base)[i + 4] = arg3[i];
            ((s16 *)base)[i + 8] = arg4[i];
            ((s16 *)base)[i + 12] = arg1[i];
            base[i + 0x20] = arg5[i];
        }
    }
    if (*(s32 *)(arg0 + 0x8B94) == 0 && arg6 > 0) {
        *(s32 *)(arg0 + 0x8B94) = 4;
        *(s32 *)(base + 0x24) = arg6;
        *(s32 *)(base + 0x28) = *(s16 *)(D_08A62C7C + 0x5C0);
        func_088832F8(arg0, 1, arg1[*(s32 *)(base + 0x28)], arg1[arg6 - 1]);
    }
}

}
