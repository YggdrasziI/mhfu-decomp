/* unit_08859188: 0x08859188-0x08859218 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;

extern u8 D_08A62C44;
extern s32 D_08A62C48;
extern s32 D_08A62C4C;
extern s32 D_08A631A0;
extern s32 func_088905EC(s32);
extern int sceKernelWakeupThread(s32);

void func_08859188(void) {
    s32 temp_a0;

    temp_a0 = D_08A62C48 + 1;
    D_08A62C48 = temp_a0;
    if ((temp_a0 >= 2) && (D_08A62C44 == 0)) {
        D_08A62C44 = 1;
        D_08A62C48 = 0;
        func_088905EC(D_08A631A0);
        sceKernelWakeupThread(*(s32 *)((char *)D_08A631A0 + 0xF7F024));
        return;
    }
    D_08A62C4C = 1;
}
