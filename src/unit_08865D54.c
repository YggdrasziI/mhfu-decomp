/* unit_08865D54: 0x08865D54-0x08865D84 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08865D54: copy a u16 from a 0x1D0-byte table entry. */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Entry {
    u16 unk0;
    char pad2[0x1CE];
} Entry;

extern Entry D_09BB8A04[];

void func_08865D54(char *arg0) {
    *(u16 *)(arg0 + 0x27C) = D_09BB8A04[*(u8 *)(arg0 + 0x1E8)].unk0;
}
