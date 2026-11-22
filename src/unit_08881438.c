/* unit_08881438: 0x08881438-0x08881458 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;
typedef unsigned short u16;

/* Two parallel u16 arrays at offset 0x8B54 of the object (layout hypothesis). */
typedef struct {
    u16 unk0[3];
    u16 unk6[3];
} UnkPair;

void func_08881438(void *arg0, s32 arg1) {
    UnkPair *t = (UnkPair *)((char *)arg0 + 0x8B54);

    t->unk0[arg1] = 0xFFFF;
    t->unk6[arg1] = 0;
}
