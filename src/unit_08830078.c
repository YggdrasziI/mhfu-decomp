/* unit_08830078: 0x08830078-0x0883029C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08830078
 *
 * Needs the speed setting: the flag byte c is spilled to the stack only
 * then (size setting spills the table pointer instead).
 */

#pragma optimize_for_size off

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

typedef struct { u16 v; u16 pad[3]; } T8;

extern T8 D_08938758[];
extern T8 D_0893875A[];
extern char D_08938478[];
extern char *D_08A631A8;
extern char *D_089CC438;
extern u16 D_089AC8E4;

extern void func_0882DCA0(char *, u16, u16, u16, u16, s32);
extern void func_08890DE8(char *, s8, u8);
extern void func_08890E38(char *, s8);
extern char *func_0885151C(char *, u16);
extern void func_08891474(char *, s16, s16, char *, ...);
extern s32 func_088303E8(char *, char *, s32, char *);
extern void func_08832F20(char *, s16, s16, s32, s32, s32);
extern void func_0881EE84(char *, char *, s16, s16, s32, char *, s32, s32);

s32 func_08830078(char *arg0, char *arg1, s16 arg2, s16 arg3, s32 arg4, char *arg5, s32 arg6) {
    u16 *pb;
    u16 *pa;
    u8 c;
    s32 r;
    s16 x;
    s32 m;

    pb = &D_0893875A[arg6].v;
    pa = &D_08938758[arg6].v;
    func_0882DCA0(arg0, arg2, arg3, *pa, *pb, 0xFF);
    if (arg1 != 0 && *(u16 *)(arg1 + 2) == 0) {
        arg1 = 0;
    }
    if (arg5 != 0 && *(u16 *)(arg5 + 2) == 0) {
        arg5 = 0;
    }
    if (!(arg4 & 8)) {
        c = 0;
    } else {
        c = 10;
        arg5 = 0;
    }
    func_08890DE8(D_08A631A8, 14, 14);
    if (arg1 != 0 && *(u16 *)(arg1 + 2) > 0x5DC) {
        func_08890E38(D_08A631A8, c);
        func_08891474(D_08A631A8, (s16)(arg2 + 0x2A), (s16)(arg3 + 8), D_08938478,
                      func_0885151C(D_089CC438, D_089AC8E4));
        return 0;
    }
    if (!(arg4 & 0x80)) {
        r = (u8)func_088303E8(arg0, arg1, arg4, arg5);
        if (r > 0) {
            x = arg2 + *pa - 0x2C;
            m = 1;
            if (arg4 & 0x40) {
                x -= 15;
                m |= 6;
            }
            func_08832F20(arg0, x, (s16)(arg3 + *pb - 0x14), arg4 & 7, r, m);
        }
    }
    func_0881EE84(arg0, arg1, arg2, arg3, arg4, arg5, *(s32 *)(arg0 + 0x530), arg6);
    return 0;
}
