/* unit_088A72F0: 0x088A72F0-0x088A7308 (ULES01213)
 *
 * Bounds (hypothesis): 3 small functions between code still in assembly.
 */

typedef int s32;

extern void func_088A9CE8(void);
extern void func_088A9E28(s32);
extern void func_088A9E60(void);

void func_088A72F0(s32 arg0) {
    func_088A9E28(arg0);
}

void func_088A72F8(void) {
    func_088A9E60();
}

void func_088A7300(void) {
    func_088A9CE8();
}
