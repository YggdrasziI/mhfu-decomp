/* unit_08867B34: 0x08867B34-0x08867D10 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08867B34 */
typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;

extern char *func_088B89B0(s32, s32);
extern s32 func_088627AC(char *);
extern s32 func_08859B44(void *, s32, s32);
extern s32 func_08862710(char *);
extern void func_088623DC(char *, s32, char *, s32);
extern void func_088642FC(char *);
extern void func_0886789C(char *, char *, s32, float, float, float);
extern void func_088640F8(char *, char *, float, float, float);
extern void func_088641C0(char *);
extern void func_08862518(char *, s32, char *, s32);

void func_08867B34(char *a0, char *a1, u8 a2)
{
    s32 *slot;
    char *p;
    s32 r;
    s32 n;
    float x, y, z;

    slot = &((s32 *)(a0 + 0x80258))[(u8)(a2 + 8)];
    p = func_088B89B0(*slot, 0);
    n = *(u16 *)(p + 0x1C);
    r = func_08859B44(a0 + 0x80000, (s32)((char *)(func_088627AC(p) * 16) + n * 8), 16);
    func_088623DC(a1 + 0x50, r, p, func_08862710(p));

    p = func_088B89B0(*slot, 1);
    n = *(s32 *)(p + 4);
    if (*(s32 *)p & 0x80000000) {
        n--;
    }
    r = func_08859B44(a0 + 0x80000, n * 0x250, 16);
    z = *(float *)(a1 + 0x68);
    y = *(float *)(a1 + 0x64);
    x = *(float *)(a1 + 0x60);
    if (a1 + 0x80 != 0) {
        func_088642FC(a1 + 0x80);
        func_0886789C(a1 + 0x80, p, r, x, y, z);
        func_088640F8(a1 + 0x80, 0, 1.0f, 1.0f, 1.0f);
        func_088641C0(a1 + 0x80);
    }

    p = func_088B89B0(*slot, 2);
    r = func_08859B44(a0 + 0x80000, 0x40, 16);
    func_08862518(a1 + 0x70, r, p, 0);
    func_08862518(a1 + 0x70, r, *(char **)(a0 + 0x80274), 1);
}
