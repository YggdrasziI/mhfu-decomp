/* unit_08868234: 0x08868234-0x08868498 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef float f32;

extern char *func_088B89B0(char *, s32);
extern s32 func_088627AC(char *);
extern char *func_08859B44(void *, s32, s32);
extern char *func_08866B8C(char *, s32, s32);
extern s32 func_0886271C(char *);
extern char *func_08862710(char *);
extern void sceKernelDcacheWritebackInvalidateAll(void);
extern s32 sceDmacMemcpy(char *, char *, s32);
extern void func_088623DC(char *, char *, char *, char *);
extern void func_088642FC(char *);
extern void func_0886789C(char *, char *, char *, f32, f32, f32);
extern void func_088640F8(char *, char *, f32, f32, f32);
extern void func_088641C0(char *);
extern void func_08862518(char *, char *, char *, s32);

s32 func_08868234(char *arg0, char *arg1, s32 arg2) {
    u8 idx = arg2;
    s32 slot = (u8)(idx * 8 + 6);
    char **ent = (char **)(arg0 + 0x80258) + slot;
    char *res;
    char *buf;
    char *dst;
    s32 size;
    s32 n;
    f32 x, y, z;
    char *model;
    s32 *hdr;
    s32 cnt;

    res = func_088B89B0(*ent, 0);
    if (res == 0) {
        return 0;
    }
    cnt = *(u16 *)(res + 0x1C);
    size = func_088627AC(res);
    buf = func_08859B44(arg0 + 0x80000, size * 16 + cnt * 8, 0x10);
    if (*((u8 (*)[8])(arg0 + 0x800A8))[(u8)slot] == 1) {
        dst = func_08866B8C(arg0, idx, 6);
        size = func_0886271C(res);
        sceKernelDcacheWritebackInvalidateAll();
        sceDmacMemcpy(dst, func_08862710(res), size);
    } else {
        dst = func_08862710(res);
    }
    func_088623DC(arg1 + 0xF60, buf, res, dst);

    hdr = (s32 *)func_088B89B0(*ent, 1);
    if (hdr == 0) {
        return 0;
    }
    n = hdr[1];
    if (hdr[0] & 0x80000000) {
        n--;
    }
    buf = func_08859B44(arg0 + 0x80000, n * 0x250, 0x10);
    z = *(f32 *)(arg1 + 0xF78);
    y = *(f32 *)(arg1 + 0xF74);
    x = *(f32 *)(arg1 + 0xF70);
    model = arg1 + 0xF80;
    if (model != 0) {
        func_088642FC(model);
        func_0886789C(model, (char *)hdr, buf, x, y, z);
        func_088640F8(model, 0, 1.0f, 1.0f, 1.0f);
        func_088641C0(model);
    }

    hdr = (s32 *)func_088B89B0(*ent, 2);
    if (hdr == 0) {
        return 0;
    }
    buf = func_08859B44(arg0 + 0x80000, hdr[2] << 5, 0x10);
    func_08862518(arg1 + 0x10C0, buf, (char *)hdr, 0);
    return 1;
}
