/* unit_08832B98: 0x08832B98-0x08832C60 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;

extern s32 D_08A62C40;
extern int func_088596C8(s32, s32 *, s32, u8);
extern s32 *func_088597FC(s32);
extern int func_0885980C(s32, s32 *);

void func_08832B98(char *arg0, s32 arg1) {
    s32 *buf;
    s32 n;

    n = 0;
    buf = func_088597FC(D_08A62C40);
    if (arg1 == 0) {
        buf[n++] = 0xC6000000;
    } else {
        buf[n++] = 0xC6000101;
    }
    buf[n++] = 0x10000000;
    buf[n++] = 0x08000000;
    func_088596C8(D_08A62C40, buf, n, *(u8 *)(arg0 + 0x534));
    func_0885980C(D_08A62C40, buf + n);
}
