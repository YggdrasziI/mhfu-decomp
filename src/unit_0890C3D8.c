/* unit_0890C3D8: 0x0890C3D8-0x0890C3F4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* __ptmf_test: returns 1 when a pointer-to-member-function is not null
 * (Metrowerks C++ runtime). The three-word layout (this delta, vtable
 * offset, function) is a hypothesis; only the loads at 0, 4 and 8 are seen.
 * The `|=` statement form gives the original `or` operand order. */

typedef int s32;

typedef struct PTMF {
    s32 unk0;
    s32 unk4;
    s32 unk8;
} PTMF;

s32 __ptmf_test(PTMF *ptmf) {
    s32 r = ptmf->unk0 | ptmf->unk4;
    r |= ptmf->unk8;
    return r != 0;
}
