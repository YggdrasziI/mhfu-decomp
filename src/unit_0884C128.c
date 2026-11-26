/* unit_0884C128: 0x0884C128-0x0884C22C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0884C128: 0x0884C128-0x0884C22C (ULES01213)
 *
 * Builds a 12-word GE command list (texture base/width words from the
 * surface of func_088125A4 and from arg0 + 0x218) and submits it through
 * func_08859480 (hypothesis on the meaning).
 */

typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;

typedef struct {
    s32 unk0;
    s32 unk4;
    u32 unk8;
    s32 unkC[3];
} Surface;

extern s32 D_089CBBE0;
extern char *D_08A62C40;

extern void func_088125A4(s32, s32, Surface *);
extern s32 func_08859480(char *, u32 *, s32, s32);

void func_0884C128(char *arg0) {
    Surface surf;
    u32 cmd[16];

    func_088125A4(D_089CBBE0, (u8)(*(s32 *)(D_08A62C40 + 4) ^ 1), &surf);
    cmd[0] = 0xCC000000;
    cmd[1] = (surf.unk8 & 0xFFFFFF) | 0xB2000000;
    cmd[2] = ((surf.unk8 & 0xFF000000) >> 8) | 0xB3000100;
    cmd[3] = (*(u32 *)(arg0 + 0x218) & 0xFFFFFF) | 0xB4000000;
    cmd[4] = ((*(u32 *)(arg0 + 0x218) & 0xFF000000) >> 8) | 0xB5000100;
    cmd[5] = 0xEB000000;
    cmd[6] = 0xEC000000;
    cmd[7] = 0xEE043CFF;
    cmd[8] = 0xEA000001;
    cmd[9] = 0xCC000000;
    cmd[10] = 0x10000000;
    cmd[11] = 0x08000000;
    func_08859480(D_08A62C40, cmd, 12, *(u8 *)(arg0 + 0x215));
}
