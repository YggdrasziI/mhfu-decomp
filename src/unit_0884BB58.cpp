/* unit_0884BB58: 0x0884BB58-0x0884C128 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed char s8;
typedef int s32;
typedef unsigned int u32;

typedef struct Node {
    virtual void vfunc_08();
    virtual void vfunc_0C();
    s32 unk4;
    struct Node *next;
} Node;

typedef struct Obj {
    char pad0[0x3D4];
    u8 unk3D4;
} Obj;

extern "C" {

extern u32 *D_089CC000;
extern char *D_089CBBE4;
extern char *D_089CC438;
extern Obj **D_09A4F060;
extern s8 D_0893B7BC[];
extern s32 func_0884C89C(char *, u8);
extern void func_0884C914(char *);
extern void func_0884C128(char *);
extern void func_088CACD4(Obj *);

void func_0884BB58(char *arg0) {
    s32 i;
    s32 j;
    s8 *cnt;
    Node *n;

    for (i = 0; i < 20; i++) {
        if (func_0884C89C(arg0, i) == 0) {
            continue;
        }
        if (i == 1) {
            u32 m[16] __attribute__((aligned(16)));
            u32 *p = m;
            char *g;
            asm {
                vmidt.q E000
                sv.q C000, 0x0(p)
                sv.q C010, 0x10(p)
                sv.q C020, 0x20(p)
                sv.q C030, 0x30(p)
            }
            *D_089CC000++ = 0x3C000000;
            *D_089CC000++ = (m[0] >> 8) | 0x3D000000;
            *D_089CC000++ = (m[1] >> 8) | 0x3D000000;
            *D_089CC000++ = (m[2] >> 8) | 0x3D000000;
            *D_089CC000++ = (m[4] >> 8) | 0x3D000000;
            *D_089CC000++ = (m[5] >> 8) | 0x3D000000;
            *D_089CC000++ = (m[6] >> 8) | 0x3D000000;
            *D_089CC000++ = (m[8] >> 8) | 0x3D000000;
            *D_089CC000++ = (m[9] >> 8) | 0x3D000000;
            *D_089CC000++ = (m[10] >> 8) | 0x3D000000;
            *D_089CC000++ = (m[12] >> 8) | 0x3D000000;
            *D_089CC000++ = (m[13] >> 8) | 0x3D000000;
            *D_089CC000++ = (m[14] >> 8) | 0x3D000000;
            g = D_089CBBE4;
            *D_089CC000++ = 0x3E000000;
            *D_089CC000++ = (*(u32 *)(g + 0xC00) >> 8) | 0x3F000000;
            *D_089CC000++ = (*(u32 *)(g + 0xC04) >> 8) | 0x3F000000;
            *D_089CC000++ = (*(u32 *)(g + 0xC08) >> 8) | 0x3F000000;
            *D_089CC000++ = (*(u32 *)(g + 0xC0C) >> 8) | 0x3F000000;
            *D_089CC000++ = (*(u32 *)(g + 0xC10) >> 8) | 0x3F000000;
            *D_089CC000++ = (*(u32 *)(g + 0xC14) >> 8) | 0x3F000000;
            *D_089CC000++ = (*(u32 *)(g + 0xC18) >> 8) | 0x3F000000;
            *D_089CC000++ = (*(u32 *)(g + 0xC1C) >> 8) | 0x3F000000;
            *D_089CC000++ = (*(u32 *)(g + 0xC20) >> 8) | 0x3F000000;
            *D_089CC000++ = (*(u32 *)(g + 0xC24) >> 8) | 0x3F000000;
            *D_089CC000++ = (*(u32 *)(g + 0xC28) >> 8) | 0x3F000000;
            *D_089CC000++ = (*(u32 *)(g + 0xC2C) >> 8) | 0x3F000000;
            *D_089CC000++ = (*(u32 *)(g + 0xC30) >> 8) | 0x3F000000;
            *D_089CC000++ = (*(u32 *)(g + 0xC34) >> 8) | 0x3F000000;
            *D_089CC000++ = (*(u32 *)(g + 0xC38) >> 8) | 0x3F000000;
            *D_089CC000++ = (*(u32 *)(g + 0xC3C) >> 8) | 0x3F000000;
        }
        cnt = &D_0893B7BC[i];
        for (j = 0; j < *cnt; j++) {
            n = (*(Node ***)(arg0 + 0x1BC + i * 4))[j];
            while (n != 0) {
                n->vfunc_0C();
                n = n->next;
            }
        }
        if (i == 8 && *(u16 *)(D_089CC438 + 0x6AF0E) != 0 && *D_09A4F060 != 0
            && (*D_09A4F060)->unk3D4 == 1) {
            func_088CACD4(*D_09A4F060);
        }
        func_0884C914(arg0);
    }
    if (*(u8 *)(arg0 + 0x214) == 1) {
        func_0884C128(arg0);
        *(u8 *)(arg0 + 0x214) = 0;
    }
}

}
