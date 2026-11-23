/* unit_08863198: 0x08863198-0x088632D8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off
typedef int s32;
typedef unsigned int u32;
typedef unsigned short u16;
typedef float f32;

typedef struct Entry {
    u16 unk0;
    u16 unk2;
    s32 unk4;
    s32 unk8;
} Entry;

typedef struct Header {
    u32 unk0;
    u32 unk4;
    s32 unk8;
} Header;

extern s32 D_089A5C44[];
extern f32 func_088630D0(void *arg0, Entry *arg1, void *arg2, f32 arg3);

s32 func_08863198(char *arg0, char *arg1, u32 arg2, char *arg3) {
    Header *hdr = *(Header **)(arg0 + 0x64);
    Entry *e;
    u32 i;
    f32 *dst;
    s32 idx;

    if (hdr != 0 && (hdr->unk0 & 0x1FF) != 0) {
        e = (Entry *)(hdr + 1);
        for (i = 0; i < hdr->unk4; i++) {
            idx = D_089A5C44[e->unk0];
            dst = (f32 *)(arg1 + idx * 4);
            *dst = func_088630D0(arg0, e, arg3 + idx * 2, (f32)arg2);
            if (e->unk0 & 0x38) {
                *dst *= 0.0003834952f;
            } else {
                *dst *= 0.0625f;
            }
            hdr = *(Header **)(arg0 + 0x64);
            e = (Entry *)((char *)e + e->unk8);
        }
    }
    return 1;
}
