typedef int s32;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

extern char *D_089CC438;
extern char *D_08A631A8;
extern char *D_08A62C54;
extern u16 D_089AC97C;
extern char D_08938478;
extern u8 D_089B7E18[][3];
extern u8 D_0893ACE0[][4];

extern char *func_0885151C(char *, u16);
extern void func_088915B0(char *, s16, s16, s32, char *, ...);
extern u8 func_0885CDB8(char *, char *);
extern void func_0882BE60(char *, u16, u16, u16, u16, u8, u8, u8, s32);

void func_08822210(char *arg0, char *arg1, u16 x, s32 y) {
    u8 *p;
    s32 i;
    char *s;

    s = func_0885151C(D_089CC438, D_089AC97C);
    func_088915B0(D_08A631A8, (s16)(x + 0x62), (s16)y, 0, &D_08938478, s);
    x += 0x98;
    p = D_089B7E18[func_0885CDB8(D_08A62C54, arg1)];
    y = (u16)y - 2;
    for (i = 3; i > 0; i--) {
        func_0882BE60(arg0, x, y, 12, 16, D_0893ACE0[*p][0], D_0893ACE0[*p][1],
                      D_0893ACE0[*p][2], 0x177);
        p++;
        x += 16;
    }
}
