/* unit_08821BD4: 0x08821BD4-0x08821CA8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;

typedef struct {
    s16 x, y, z;
} Vec3s;

extern s32 D_08A62C54;

extern u16 func_0885DF38(s32, char *);
extern u8 func_0885CCD0(s32, u16);
extern u8 func_0885CE00(s32, u8);
extern u8 func_0885CE1C(s32, u8);
extern u8 func_0885CDB8(s32, char *);
extern void func_088DAAA0(char *);
extern u8 func_088DAB94(char *, s16);

void func_08821BD4(char *arg0, char *arg1) {
    *(u8 *)(arg0 + 0x4E8) = *(u8 *)(arg1 + 0);
    *(u8 *)(arg0 + 0x4E9) = *(u8 *)(arg1 + 1);
    *(u16 *)(arg0 + 0x4EA) = *(u16 *)(arg1 + 2);
    *(u16 *)(arg0 + 0x4EC) = *(u16 *)(arg1 + 4);
    *(Vec3s *)(arg0 + 0x4EE) = *(Vec3s *)(arg1 + 6);
    *(u16 *)(arg0 + 0x534) = func_0885DF38(D_08A62C54, arg0 + 0x4E8);
    *(u8 *)(arg0 + 0x1E8) = func_0885CCD0(D_08A62C54, *(u16 *)(arg0 + 0x534));
    *(u8 *)(arg0 + 0x5F3) = func_0885CE00(D_08A62C54, *(u8 *)(arg0 + 0x1E8));
    *(u8 *)(arg0 + 0x5F4) = func_0885CE1C(D_08A62C54, *(u8 *)(arg0 + 0x1E8));
    *(u8 *)(arg0 + 0x5F5) = func_0885CDB8(D_08A62C54, arg0 + 0x4E8);
    func_088DAAA0(arg0);
    *(u8 *)(arg0 + 0x5F2) = func_088DAB94(arg0, *(s16 *)(arg0 + 0x60C));
}
