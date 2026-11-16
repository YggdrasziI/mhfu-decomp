/* unit_0885DC30: 0x0885DC30-0x0885DD38 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly and
 * unit_0885DD38. Its jump table (0x08931568-0x08931584) is linked from this
 * unit.
 */

typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 unk0;
    char pad[39];
} E40;

extern E40 D_08963258[];
extern E40 D_08967678[];
extern E40 D_0896B818[];
extern E40 D_0896F850[];
extern E40 D_08973838[];

s32 func_0885DC30(s32 arg0, u8 *arg1) {
    switch (arg1[1]) {
    case 1:
        return (D_08963258 + *(u16 *)(arg1 + 2))->unk0 & 0xF;
    case 2:
        return (D_08967678 + *(u16 *)(arg1 + 2))->unk0 & 0xF;
    case 4:
        return (D_0896F850 + *(u16 *)(arg1 + 2))->unk0 & 0xF;
    case 3:
        return (D_0896B818 + *(u16 *)(arg1 + 2))->unk0 & 0xF;
    case 0:
        return (D_08973838 + *(u16 *)(arg1 + 2))->unk0 & 0xF;
    case 5:
    case 6:
        return 0xF;
    default:
        return 0;
    }
}
