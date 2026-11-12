/* unit_088688C8: 0x088688C8-0x088689F4 (ULES01213)
 *
 * Bounds (hypothesis): 2 small functions between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;

extern s32 D_089CBBE0;
extern int func_0880C464(void *, s32, s32);
extern int func_08812264(s32, s32);
extern int func_08859C40(s32, s32);

void func_088688C8(char *arg0, char *arg1) {
    s32 temp_a1;
    s32 temp_a1_2;
    s32 temp_a1_3;

    temp_a1 = *(s32 *)(arg1 + 0x58);
    if (temp_a1 != 0) {
        func_08859C40((int) (arg0 + 0x80000), temp_a1);
    }
    func_0880C464(arg1 + 0x50, 0, 0x20);
    temp_a1_2 = *(s32 *)(arg1 + 0x190);
    if (temp_a1_2 != 0) {
        func_08859C40((int) (arg0 + 0x80000), temp_a1_2);
    }
    func_0880C464(arg1 + 0x80, 0, 0x140);
    temp_a1_3 = *(s32 *)(arg1 + 0x74);
    if (temp_a1_3 != 0) {
        func_08859C40((int) (arg0 + 0x80000), temp_a1_3);
    }
    func_0880C464(arg1 + 0x70, 0, 0x10);
}

void func_08868968(char *arg0, char *arg1) {
    s32 temp_a1;
    s32 temp_a1_2;
    s32 temp_a1_3;

    temp_a1 = *(s32 *)(arg1 + 0x58);
    if (temp_a1 != 0) {
        func_08859C40((int) (arg0 + 0x80000), temp_a1);
        if (*(u8 *)(arg1 + 0x1E8) == 0) {
            func_08812264(D_089CBBE0, 0x29);
        }
    }
    temp_a1_2 = *(s32 *)(arg1 + 0x190);
    if (temp_a1_2 != 0) {
        func_08859C40((int) (arg0 + 0x80000), temp_a1_2);
    }
    temp_a1_3 = *(s32 *)(arg1 + 0x74);
    if (temp_a1_3 != 0) {
        func_08859C40((int) (arg0 + 0x80000), temp_a1_3);
    }
}
