/* unit_0889A024: 0x0889A024-0x0889A064 (ULES01213)
 *
 * Bounds (hypothesis): two functions that set a flag and register a callback, between unrelated code.
 */

typedef int s32;

extern void func_088B1708(int kind, void (*callback)(), void *arg);
extern void func_0889AA08(s32);
extern void func_0889AACC(s32);

void func_0889A024(char *o) {
    *(int *)(o + 0x12C0) |= 0x800;
    func_088B1708(1, func_0889AA08, o);
}

void func_0889A044(char *o) {
    *(int *)(o + 0x12C0) |= 0x1000;
    func_088B1708(0, func_0889AACC, o);
}
