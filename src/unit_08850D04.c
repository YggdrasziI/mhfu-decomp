/* unit_08850D04: 0x08850D04-0x08850E58 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 unk0;
    u8 pad1[0x27];
} Entry;

extern Entry D_08963258[];
extern Entry D_08967678[];
extern Entry D_0896F850[];
extern Entry D_0896B818[];
extern Entry D_08973838[];

void func_08850D04(char *arg0) {
    char *p = arg0 + 0x4A0;
    u8 mask = 0;
    u8 m;

    if (*(u8 *)(arg0 + 0x4B3) == 0) {
        mask |= 1;
    } else {
        mask |= 2;
    }
    if (*(u8 *)(p + 0x21) == 6) {
        mask |= 8;
    } else {
        mask |= 4;
    }
    m = mask;
    if ((m & D_08963258[*(u16 *)(p + 0x3A)].unk0) != m) {
        *(u16 *)(p + 0x4024) = 0xFFFF;
    }
    if ((m & D_08967678[*(u16 *)(p + 0x46)].unk0) != m) {
        *(u16 *)(p + 0x4026) = 0xFFFF;
    }
    if ((m & D_0896F850[*(u16 *)(p + 0x5E)].unk0) != m) {
        *(u16 *)(p + 0x402A) = 0xFFFF;
    }
    if ((m & D_0896B818[*(u16 *)(p + 0x52)].unk0) != m) {
        *(u16 *)(p + 0x4028) = 0xFFFF;
    }
    if ((m & D_08973838[*(u16 *)(p + 0x2E)].unk0) != m) {
        *(u16 *)(p + 0x4022) = 0xFFFF;
    }
}
