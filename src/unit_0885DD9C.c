/* unit_0885DD9C: 0x0885DD9C-0x0885DF38 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_0885DD38 and code still in
 * assembly. Its jump table (0x089315A0-0x089315BC) is linked from this unit.
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
extern char *D_089CC438;

s32 func_0885DD9C(s32 arg0, u8 *arg1) {
    char *p = D_089CC438 + 0x4A0;
    u8 mask = 0;

    if (*(u8 *)(p + 0x13) == 0) {
        mask |= 1;
    } else {
        mask |= 2;
    }
    if (*(u8 *)(p + 0x21) == 6) {
        mask |= 8;
    } else {
        mask |= 4;
    }
    switch (arg1[1]) {
    case 1:
        if ((mask & D_08963258[*(u16 *)(arg1 + 2)].unk0) != mask) {
            return 0;
        }
        break;
    case 2:
        if ((mask & D_08967678[*(u16 *)(arg1 + 2)].unk0) != mask) {
            return 0;
        }
        break;
    case 4:
        if ((mask & D_0896F850[*(u16 *)(arg1 + 2)].unk0) != mask) {
            return 0;
        }
        break;
    case 3:
        if ((mask & D_0896B818[*(u16 *)(arg1 + 2)].unk0) != mask) {
            return 0;
        }
        break;
    case 0:
        if ((mask & D_08973838[*(u16 *)(arg1 + 2)].unk0) != mask) {
            return 0;
        }
        break;
    case 5:
    case 6:
        break;
    }
    return 1;
}
