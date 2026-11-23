/* unit_08867D10: 0x08867D10-0x08867EC8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08867D10 */
typedef int s32;
typedef unsigned short u16;
typedef unsigned int u32;

extern char *func_088B89B0(char *, s32);
extern s32 func_088627AC(char *);
extern s32 func_08859B44(void *, s32, s32);
extern s32 func_08862710(char *);
extern void func_088623DC(char *, s32, char *, s32);
extern void func_088642FC(char *);
extern void func_0886789C(char *, char *, s32, float, float, float);
extern void func_088640F8(char *, char *, float, float, float);
extern void func_088641C0(char *);
extern void func_08862518(char *, s32, char *, s32);

void func_08867D10(char *a0, char *a1)
{
    char *p;
    s32 n;
    float x, y, z;

    {
        s32 h;
        s32 r;
        s32 t;
        p = func_088B89B0(*(char **)(a0 + 0x80290), 0);
        h = *(u16 *)(p + 0x1C);
        t = func_088627AC(p) << 4;
        r = func_08859B44(a0 + 0x80000, t + h * 8, 0x10);
        func_088623DC(a1 + 0xF60, r, p, func_08862710(p));
    }

    {
        s32 r;
        char *m;
        p = func_088B89B0(*(char **)(a0 + 0x80290), 1);
        n = *(s32 *)(p + 4);
        if (*(u32 *)p & 0x80000000) {
            n--;
        }
        r = func_08859B44(a0 + 0x80000, n * 0x250, 0x10);
        z = *(float *)(a1 + 0xF78);
        y = *(float *)(a1 + 0xF74);
        x = *(float *)(a1 + 0xF70);
        m = a1 + 0xF80;
        if (m != 0) {
            func_088642FC(m);
            func_0886789C(m, p, r, x, y, z);
            func_088640F8(m, 0, 1.0f, 1.0f, 1.0f);
            func_088641C0(m);
        }
    }

    p = func_088B89B0(*(char **)(a0 + 0x80290), 2);
    func_08862518(a1 + 0x10C0, func_08859B44(a0 + 0x80000, *(s32 *)(p + 8) << 5, 0x10), p, 0);
}
