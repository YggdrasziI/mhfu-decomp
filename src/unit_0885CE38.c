/* unit_0885CE38: 0x0885CE38-0x0885CF9C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly and
 * unit_0885CF9C.
 *
 * Optimized for speed: divisions by a constant are multiplications.
 */

#pragma optimize_for_size off

typedef int s32;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 unk0;
    u8 unk1;
    u16 unk2;
    u16 unk4;
} Item;

extern u8 D_08960B9F[];
extern s16 D_08960BA4[];
extern char *D_08979448[];
extern s16 D_089CC004;

extern u8 func_0885CD18(s32, u8, u16);

s16 func_0885CE38(s32 arg0, Item *arg1) {
    s16 base;
    s16 val;
    u8 kind;

    if (arg1->unk1 != 6) {
        return -1;
    }
    base = *(s16 *)((char *) D_08960BA4 + arg1->unk2 * 0x1C);
    val = base;
    kind = func_0885CD18(arg0, arg1->unk1, arg1->unk2);
    if (kind != 0xA) {
        val += *(s16 *)(D_08979448[D_08960B9F[arg1->unk2 * 0x1C]] + (arg1->unk4 & 0xF) * 0x18);
        if (arg1->unk4 & 0x10) {
            val += D_089CC004;
        }
        if (arg1->unk4 & 0x20) {
            if (kind == 1) {
                val = val + base / 10;
            } else {
                val = val + base / 15;
            }
        }
    }
    return val;
}
