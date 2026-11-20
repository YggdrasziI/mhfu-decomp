/* unit_088C0468: 0x088C0468-0x088C0554 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088C0420 and
 * unit_088C0554.
 *
 * The 0x16A100-byte save image at +0x94C: the 0x24-byte header at
 * +0x16A0DC holds a 0x14-byte digest at +0xC, computed by func_089040A0
 * over 0x16A0F0 bytes with the digest field set to D_089B4DF8.
 * Seals the image (digest, a word at +0x16A0FC) and writes it.
 *
 * NonMatching: the image keeps the original code.
 */

typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;

typedef struct {
    u8 pad0[0xC];
    u8 digest[0x14];
    u8 pad20[4];
} Hdr;

extern char *D_089CC438;
extern char *D_08A631A0;
extern u8 D_089B2B94[];
extern u8 D_089B4DF8[];
extern void memcpy(void *, void *, s32);
extern void func_088572E8(char *);
extern void func_088C2D74(char *, char *, s32, u8 *, s32);
extern void func_089040A0(char *, s32, u8 *);

/* NonMatching, 99.66 %: the original loads +0x4468 into $a0 and the
 * other term into $a1 and adds $a0 + $a1; ours swaps the registers (the
 * operands swapped reorders the loads). Tried: a temporary, u32 terms,
 * array indexing, the header word as an array element. */
void func_088C0468(char *arg0) {
    Hdr hdr;

    memcpy(&hdr, *(char **) (arg0 + 0x94C) + 0x16A0DC, sizeof(Hdr));
    memcpy(*(char **) (arg0 + 0x94C) + 0x16A0DC, D_089B4DF8, 0x14);
    func_089040A0(*(char **) (arg0 + 0x94C), 0x16A0F0, hdr.digest);
    memcpy(*(char **) (arg0 + 0x94C) + 0x16A0DC, &hdr, sizeof(Hdr));
    func_088572E8(D_089CC438);
    *(s32 *) (*(char **) (arg0 + 0x94C) + 0x16A0FC) =
        *(s32 *) (D_089CC438 + 0x4468) + *(s32 *) (D_08A631A0 + 0xF7A554);
    func_088C2D74(arg0, *(char **) (arg0 + 0x94C), 0x16A100, D_089B2B94, 0);
}
