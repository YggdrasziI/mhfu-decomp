/* unit_088B0FAC: 0x088B0FAC-0x088B0FF8 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;

extern s32 func_088B0FF8(s32);
extern s32 func_088B118C(s32);

void func_088B0FAC(char *arg0) {
    u8 temp_a1;

    temp_a1 = *(u8 *)(arg0 + 0x22);
    switch (temp_a1) {                              /* irregular */
    case 0:
        func_088B0FF8((s32) arg0);
        return;
    case 1:
        func_088B118C((s32) arg0);
        return;
    }
}
