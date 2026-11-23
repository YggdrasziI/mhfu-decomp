/* unit_08865BD0: 0x08865BD0-0x08865C2C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08865BD0: offset a position by an entry of the D_09CDEF40 table. */

typedef unsigned short u16;

typedef struct {
    float x;
    float y;
    char pad08[0x18 - 0x08];
    float h0;
    float h1;
} Unk09CDEF40;

extern Unk09CDEF40 D_09CDEF40[];

void func_08865BD0(char *arg0) {
    Unk09CDEF40 *e = &D_09CDEF40[*(u16 *)(arg0 + 0x29A)];

    *(float *)(arg0 + 0x260) = *(float *)(arg0 + 0x200) + e->x;
    *(float *)(arg0 + 0x264) = *(float *)(arg0 + 0x204) + (e->h0 + e->h1) / 2.0f;
    *(float *)(arg0 + 0x268) = *(float *)(arg0 + 0x208) + e->y;
}
