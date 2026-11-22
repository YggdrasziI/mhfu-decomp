/* unit_0889BF08: 0x0889BF08-0x0889BFA0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;

typedef struct {
    s32 unk0;
    s32 unk4;
    char *unk8;
    s8 unkC;
    s8 padD[3];
    u16 unk10;
    u16 pad12;
} Arg_0889BF08;

extern char *D_089CC434;
extern s32 D_08A62D8C;

extern void func_088B3718(void *);
extern void func_0889CA88(char *, void *);
extern void func_08883988(s32, s32, s32, s32, s32, s32, s32, s32, s32);

void func_0889BF08(Arg_0889BF08 *arg0) {
    Arg_0889BF08 a;
    char buf[0x64];

    a = *arg0;
    func_088B3718(buf);
    func_0889CA88(a.unk8, buf);
    if (*(u8 *)(D_089CC434 + 0x2930C) == 0) {
        func_08883988(D_08A62D8C, 3, 0x1C, 0, 0, 0, 0, 0, 0);
    }
}
