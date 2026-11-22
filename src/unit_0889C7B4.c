/* unit_0889C7B4: 0x0889C7B4-0x0889C81C (ULES01213) */

typedef int s32;
typedef signed char s8;
typedef unsigned char u8;

extern void func_088B3A3C(void *);
extern void func_0889C66C(u8 *, s32, u8 *, s32, u8 *, u8 *, u8 *);
extern void func_0889C524(u8 *, s32, u8 *, s32, u8 *, u8 *);

void func_0889C7B4(u8 *arg0) {
    u8 tmp[0xC8];
    u8 buf[0x64];

    func_088B3A3C(buf);
    func_0889C66C(arg0, *(s8 *)(arg0 + 0xEE1), arg0 + 0x25C, 0xC8, arg0 + 0x25C, tmp, buf);
    func_0889C524(arg0, *(s8 *)(arg0 + 0xEE1) - 1, arg0 + 0x324, 0xC8, arg0 + 0x324, tmp);
}
