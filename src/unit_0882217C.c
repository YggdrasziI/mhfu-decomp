/* unit_0882217C: 0x0882217C-0x08822210 (ULES01213) */

typedef int s32;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

extern s32 D_08A62C54;
extern char *D_089CC438;
extern char *D_08A631A8;
extern u16 D_089AC9D4[];
extern char D_08938478;

extern u8 func_0885CDB8(s32, char *);
extern char *func_0885151C(char *, u16);
extern void func_08892148(char *, s16, s16, s32, char *, ...);

void func_0882217C(char *arg0, char *arg1, u16 x, u16 y) {
    char *s;

    s = func_0885151C(D_089CC438, D_089AC9D4[func_0885CDB8(D_08A62C54, arg1) % 3]);
    func_08892148(D_08A631A8, (s16)(x + 0x70), (s16)y, 0, &D_08938478, s);
}
