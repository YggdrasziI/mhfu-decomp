/* unit_088676D8: 0x088676D8-0x0886789C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_088676D8 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

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

s32 func_088676D8(char *arg0, char *arg1, s32 arg2) {
    s32 *ent;
    char *p;
    s32 a;
    s32 n;
    float x, y, z;

    ent = &((s32 *)(arg0 + 0x80258))[(u8)((u8)arg2 << 3)];
    p = func_088B89B0(*ent, 0);
    a = *(u16 *)(p + 0x1C);
    a = func_08859B44(arg0 + 0x80000, (s32)((char *)(func_088627AC(p) << 4) + (a << 3)), 0x10);
    func_088623DC(arg1 + 0x50, a, p, func_08862710(p));

    p = func_088B89B0(*ent, 1);
    n = *(s32 *)(p + 4);
    if (*(s32 *)p & 0x80000000) {
        n--;
    }
    a = func_08859B44(arg0 + 0x80000, n * 0x250, 0x10);
    z = *(float *)(arg1 + 0x68);
    y = *(float *)(arg1 + 0x64);
    x = *(float *)(arg1 + 0x60);
    if (arg1 + 0x80 != 0) {
        func_088642FC(arg1 + 0x80);
        func_0886789C(arg1 + 0x80, p, a, x, y, z);
        func_088640F8(arg1 + 0x80, 0, 1.0f, 1.0f, 1.0f);
        func_088641C0(arg1 + 0x80);
    }

    p = func_088B89B0(*ent, 2);
    func_08862518(arg1 + 0x70, func_08859B44(arg0 + 0x80000, *(s32 *)(p + 8) << 5, 0x10), p, 0);
    return 1;
}
