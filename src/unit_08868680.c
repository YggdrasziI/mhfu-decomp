/* unit_08868680: 0x08868680-0x08868778 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef struct { char b[8]; } E8;

extern int func_0880C464(void *, s32, s32);
extern int func_08859C40(void *, s32);
extern void func_08868678(s32, void *);

void func_08868680(char *arg0, char *arg1) {
    s32 temp_a1;
    s32 temp_a1_2;

    if (*(s32 *)(arg1 + 0xF68) != 0) {
        if (*(u8 *)((E8 *)(arg0 + 0x800A8))[(*(u16 *)(arg1 + 0x1E6) * 8) + 6].b == 1) {
            *(s32 *)(arg0 + 0x80238) = (s32) (*(s32 *)(arg0 + 0x80238) - 0x3800);
        }
        func_08859C40(arg0 + 0x80000, *(s32 *)(arg1 + 0xF68));
    }
    func_0880C464(arg1 + 0xF60, 0, 0x20);
    temp_a1 = *(s32 *)(arg1 + 0x1090);
    if (temp_a1 != 0) {
        func_08859C40(arg0 + 0x80000, temp_a1);
    }
    func_0880C464(arg1 + 0xF80, 0, 0x140);
    temp_a1_2 = *(s32 *)(arg1 + 0x10C4);
    if (temp_a1_2 != 0) {
        func_08859C40(arg0 + 0x80000, temp_a1_2);
    }
    func_0880C464(arg1 + 0x10C0, 0, 0x10);
    func_08868678((s32) arg0, arg1);
}
