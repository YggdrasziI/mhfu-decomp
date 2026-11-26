/* unit_088375C8: 0x088375C8-0x088378A8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function.
 *
 * .rodata: the jump table of the switch (jtbl_089310C0, 6 entries).
 */

typedef int s32;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

extern char *D_089CC438;
extern s32 D_09A4F0C4;
extern char *D_08A631A8;
extern s32 D_09B22D70;
extern u16 D_09B04DE0;
extern u16 D_09B04DF6;
extern u16 D_09B04DF8;
extern char D_0893B220[];
extern char D_0893B224[];

extern char *func_088DCEBC(s32, u8);
extern s32 func_08838AB4(s32, u8, u8);
extern int func_08890E08(char *, s32);
extern void func_08825DA8(char *);
extern void func_08890E38(char *, s8);
extern void func_08890DE8(char *, s8, u8);
extern void func_08890DFC(char *, s16, s16);
extern char *func_09A7B790(s32, u16);
extern void func_08891474(char *, s16, s16, char *, ...);
extern s32 func_08890E48(char *, char *);
extern void func_08838B08(char *, s32, s32, s16, s32, u32, s32);
extern void func_08838E0C(char *, s32, s32, s32, s32, s32);

void func_088375C8(char *arg0, u32 arg1) {
    char *p;
    char *q;

    p = func_088DCEBC(D_09A4F0C4, D_089CC438[0x28]);
    if (((u8 *)p)[0x299] != 0x10 && (u8)func_08838AB4((s32)arg0, ((u8 *)p)[0x298], ((u8 *)p)[0x299]) == 1) {
        arg0[0x535] = 0x28;
        return;
    }
    switch (arg1) {
    case 0:
        arg0[0x534] = 9;
        break;
    case 1:
        arg0[0x534] = 10;
        break;
    case 2:
        arg0[0x534] = 11;
        break;
    case 3:
        arg0[0x534] = 12;
        break;
    case 4:
        arg0[0x534] = 13;
        break;
    case 5:
        arg0[0x534] = 14;
        break;
    }
    func_08890E08(D_08A631A8, (s8)arg1);
    func_08825DA8(arg0);
    func_08890E38(D_08A631A8, 0);
    func_08890DE8(D_08A631A8, 14, 14);
    q = *(char **)(p + 0x554);
    if (q != 0 && *(u16 *)(q + 2) == 2) {
        if (--*(s8 *)(arg0 + 0x535) <= 0) {
            arg0[0x535] = 0x28;
        }
        func_08890DFC(D_08A631A8, 0x24, 0x12);
        func_08891474(D_08A631A8, 0x24, 0x12, D_0893B224,
                      func_09A7B790(D_09B22D70, D_09B04DE0),
                      func_09A7B790(D_09B22D70, D_09B04DF8));
        func_08838B08(arg0, 0, 0x10,
                      (func_08890E48(D_08A631A8, func_09A7B790(D_09B22D70, D_09B04DF8)) + 4) * 7 + 0x24,
                      0x10, 0x801D3905, 0);
        func_08838E0C(arg0, 0x10, 0x10, 0x35, *(s8 *)(arg0 + 0x535), 0x14);
    } else {
        arg0[0x535] = 0x28;
        func_08891474(D_08A631A8, 0x24, 0x12, D_0893B220,
                      func_09A7B790(D_09B22D70, D_09B04DF6));
        func_08838B08(arg0, 0, 0x10,
                      (func_08890E48(D_08A631A8, func_09A7B790(D_09B22D70, D_09B04DF6)) + 2) * 7 + 0x24,
                      0x10, 0x801D3905, 0);
    }
}
