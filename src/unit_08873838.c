/* unit_08873838: 0x08873838-0x088738D4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef int s32;

typedef struct {
    u8 pad0[0x7CC];
    s8 unk7CC[90];
    u8 pad826[2];
    s32 unk828[20];
    s16 unk878[20];
    s32 unk8A0;
} Struct08873838;

void func_08873838(Struct08873838 *arg0) {
    s32 i;

    for (i = 0; i < 20; i++) {
        arg0->unk828[i] = 0;
        arg0->unk878[i] = 0;
    }
    arg0->unk8A0 = 0;
    for (i = 0; i < 90; i++) {
        arg0->unk7CC[i] = 0;
    }
}
