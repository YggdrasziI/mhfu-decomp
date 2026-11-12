/* unit_088B0240: 0x088B0240-0x088B0318 (ULES01213)
 *
 * Bounds (hypothesis): 3 small functions between code still in assembly.
 */

typedef unsigned short u16;
typedef int s32;

extern s32 func_088B0010(s32, s32);
extern void func_088B0084(void *, void *, s32);

void func_088B0240(s32 arg0, char *arg1) {
    func_088B0010(arg0, 8);
    func_088B0084((char *) arg0, arg1, 8);
}

void func_088B0284(s32 arg0, char *arg1) {
    func_088B0010(arg0, (s32) *(u16 *)(arg1 + 0x12));
    func_088B0084((char *) arg0, arg1, (s32) *(u16 *)(arg1 + 0x12));
}

void func_088B02C8(s32 arg0, char *arg1) {
    u16 temp_s0;

    temp_s0 = *(u16 *)(arg1 + 0xA0);
    func_088B0010(arg0, (s32) temp_s0);
    func_088B0084((char *) arg0, arg1, (s32) temp_s0);
}
