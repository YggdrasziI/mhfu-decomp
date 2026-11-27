/* unit_0890C3A4: 0x0890C3A4-0x0890C3D8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* __ptmf_cmpr: compares two pointer-to-member-function records (three
 * words each) and returns nonzero when they differ.
 *
 * Field names of the record are a hypothesis (layout of the Metrowerks
 * PTMF: this adjustment, vtable offset, function or vtable slot); only
 * the three-word size and the word offsets come from the code.
 */

typedef int s32;

typedef struct PTMF {
    s32 unk0;
    s32 unk4;
    s32 unk8;
} PTMF;

s32 __ptmf_cmpr(const PTMF *a, const PTMF *b) {
    s32 x = a->unk0 ^ b->unk0;

    x |= a->unk4 ^ b->unk4;
    x |= a->unk8 ^ b->unk8;
    return x != 0;
}
