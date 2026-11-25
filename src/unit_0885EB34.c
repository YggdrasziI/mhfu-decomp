/* unit_0885EB34: 0x0885EB34-0x0885EBC8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0885EB34: returns a byte of the record selected by arg1: kinds 5 and 6
 * index D_08959FDE (24-byte entries) and D_08960BA8 (28-byte entries);
 * other kinds read byte 0x12 of the 40-byte entry of table D_08978474[kind].
 * The last read adds the table pointer and the offset as two s32 values;
 * plain indexing swaps the operands of the final addu.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct {
    u8 type;
    u8 kind;
    u16 id;
} Item;

typedef struct {
    char pad[0x12];
    u8 f12;
    char pad2[0x15];
} E40;

extern u8 D_08959FDE[];
extern u8 D_08960BA8[];
extern E40 *D_08978474[];

u8 func_0885EB34(s32 arg0, Item *arg1) {
    u8 k = arg1->kind;
    u8 r;

    if ((u32)(k - 5) < 2) {
        if (k == 5) {
            r = D_08959FDE[arg1->id * 24];
        } else {
            r = D_08960BA8[arg1->id * 28];
        }
    } else {
        r = ((E40 *)((s32)D_08978474[k] + (s32)(arg1->id * 40)))->f12;
    }
    return r;
}
