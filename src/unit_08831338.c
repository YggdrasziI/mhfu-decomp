/* unit_08831338: 0x08831338-0x08831418 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08831338 (ULES01213)
 *
 * Needs #pragma opt_propagation off: with copy propagation on, the
 * (u16)arg5 < 0x18 flag is sunk to the call instead of computed first
 * into a saved register. The local record is 12 bytes (hypothesis: its
 * real size is unknown, 12 places it at sp+0x34 as in the original).
 */

#pragma opt_propagation off
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef unsigned int u32;

typedef struct {
    u8 r, g, b, a;
} B4;

typedef struct {
    u8 type;
    u8 kind;
    u16 id;
    u8 pad[8];
} Item;

extern char *D_08A62C54;

extern s32 func_0885C83C(char *, u8, u16);
extern u32 func_08830354(char *, s32, s32, s32);
extern s32 func_0883029C(char *, Item *, s32);
extern void func_0882C11C(char *, s32, s32, s32, s32, u8, u8, u8, u8, s32);

void func_08831338(char *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, u8 arg8) {
    s32 flag = (u16)arg5 < 0x18;
    Item it;
    union {
        u32 w;
        B4 c;
    } col;
    s32 tex;

    it.kind = arg1;
    it.id = arg2;
    col.w = func_08830354(arg0, (u8)func_0885C83C(D_08A62C54, arg1, arg2), arg7, arg8);
    tex = func_0883029C(arg0, &it, flag);
    func_0882C11C(arg0, arg3, arg4, (s16)arg5, (s16)arg6, col.c.b, col.c.g, col.c.r, col.c.a, tex);
}
