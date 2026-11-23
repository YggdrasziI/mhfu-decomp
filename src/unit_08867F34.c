/* unit_08867F34: 0x08867F34-0x08868234 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08867F34 (ULES01213)
 *
 * Needs the speed setting: with the size setting the saved registers of
 * the two byte arguments, the slot pointer and the index are permuted.
 */

#pragma optimize_for_size off

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

extern char *func_088B89B0(s32, s32);
extern s32 func_088627AC(char *);
extern s32 func_08859B44(void *, s32, s32);
extern s32 func_08866B8C(char *, s32, s32);
extern s32 func_0886271C(char *);
extern char *func_08862710(char *);
extern void func_088623DC(char *, char *, char *, s32);
extern void func_088642FC(char *);
extern void func_0886789C(char *, char *, char *, float, float, float);
extern void func_088640F8(char *, char *, float, float, float);
extern void func_088641C0(char *);
extern void func_08862518(char *, char *, s32, s32);
extern s32 sceDmacMemcpy(s32, char *, s32);
extern void sceKernelDcacheWritebackInvalidateAll(void);

s32 func_08867F34(char *arg0, char *arg1, u8 arg2, u8 arg3) {
    u8 idx;
    s32 *slot;
    char *r;
    s32 size;
    s32 a;
    s32 b;
    s32 dst;
    char *model;
    float x;
    float y;
    float z;
    s32 n;

    idx = arg3 + arg2 * 8;
    slot = &((s32 *)(arg0 + 0x80258))[idx];
    r = func_088B89B0(*slot, 0);
    b = *(u16 *)(r + 0x1C);
    size = func_088627AC(r) * 16;
    a = func_08859B44(arg0 + 0x80000, size + b * 8, 16);
    if (((u8 (*)[8])(arg0 + 0x800A8))[idx][0] == 1) {
        dst = func_08866B8C(arg0, arg2, arg3);
        size = func_0886271C(r);
        sceKernelDcacheWritebackInvalidateAll();
        sceDmacMemcpy(dst, func_08862710(r), size);
    } else {
        dst = (s32)func_08862710(r);
    }
    func_088623DC(arg3 == 0 ? arg1 + 0x50 : arg1 + (arg3 - 1) * 0x20 + 0x830, (char *)a, r, dst);
    r = func_088B89B0(*slot, 1);
    n = ((s32 *)r)[1];
    if (((u32 *)r)[0] & 0x80000000) {
        n--;
    }
    b = func_08859B44(arg0 + 0x80000, n * 0x250, 16);
    {
        char *pos = arg3 == 0 ? arg1 + 0x50 : arg1 + (arg3 - 1) * 0x20 + 0x830;
        z = *(float *)(pos + 0x18);
        y = *(float *)(pos + 0x14);
        x = *(float *)(pos + 0x10);
    }
    model = arg3 == 0 ? arg1 + 0x80 : arg1 + (arg3 - 1) * 0x140 + 0x8D0;
    if (model != 0) {
        func_088642FC(model);
        func_0886789C(model, r, (char *)b, x, y, z);
        func_088640F8(model, 0, 1.0f, 1.0f, 1.0f);
        func_088641C0(model);
    }
    r = func_088B89B0(*slot, 2);
    a = func_08859B44(arg0 + 0x80000, 0x40, 16);
    func_08862518(arg3 == 0 ? arg1 + 0x70 : arg1 + (arg3 - 1) * 0x10 + 0xF10, (char *)a, (s32)r, 0);
    func_08862518(arg3 == 0 ? arg1 + 0x70 : arg1 + (arg3 - 1) * 0x10 + 0xF10, (char *)a, ((s32 *)(arg0 + 0x80274))[arg2 * 8], 1);
    return 1;
}
