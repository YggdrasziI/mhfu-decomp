/* unit_088C022C: 0x088C022C-0x088C0420 (ULES01213)
 *
 * Bounds (hypothesis): 2 functions between unit_088C0200 and
 * unit_088C0420.
 *
 * The 0x16A100-byte save image at +0x94C: the 0x24-byte header at
 * +0x16A0DC holds a 0x14-byte digest at +0xC, computed by func_089040A0
 * over 0x16A0F0 bytes with the digest field set to D_089B4DF8.
 * func_088C022C checks a loaded image and copies its six 0x6810-byte
 * blocks at +0x142300 (their names into +0x9B0, 0x28 bytes each, by
 * func_088C03CC).
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

extern char *D_08A631A0;
extern s32 D_09A0B540;
extern u8 D_089B2C94[];
extern u8 D_089B4DF8[];
extern void memcpy(void *, void *, s32);
extern void memset(void *, s32, s32);
extern s32 func_0880BFF0(void *, void *, s32);
extern void func_0880ED70(char *, char *);
extern char *func_08898694(s32, s32, s32);
extern void func_08898748(s32, s32);
extern s32 func_088C2BE0(char *, char *, char *);
extern void func_088C2D74(char *, char *, s32, u8 *, s32);
extern void func_089040A0(char *, s32, u8 *);

void func_088C03CC(char *arg0, char *blk, s32 i);

/* NonMatching, 99.47 %: in the block loop the original keeps the offset in
 * $s0, the block in $s2 and the size in $s1; ours uses $s2, $s1, $s0. Tried:
 * every declaration order, an s32 offset, the block address inline (worse).
 * The early `return 0` form gives a `beqzl` over the body (96.01 %). */
s32 func_088C022C(char *arg0, char *buf, s32 nocopy) {
    u8 digest[0x14];
    Hdr hdr;
    char *tmp;
    s32 i;
    char *p;
    char *e;
    s32 n;

    func_088C2D74(arg0, buf, 0x16A100, D_089B2C94, 1);
    memcpy(&hdr, buf + 0x16A0DC, sizeof(Hdr));
    memcpy(buf + 0x16A0DC, D_089B4DF8, 0x14);
    func_089040A0(buf, 0x16A0F0, digest);
    memcpy(buf + 0x16A0DC, &hdr, sizeof(Hdr));
    if (func_0880BFF0(digest, hdr.digest, 0x14) == 0) {
        tmp = func_08898694(D_09A0B540, 0x17, 0x6800);
        memset(arg0 + 0x9B0, 0, 0xF0);
        i = 0;
        p = 0;
        do {
            e = *(char **) (arg0 + 0x94C) + (s32) p + 0x142300;
            if (*(s32 *) e != 0) {
                n = func_088C2BE0(arg0, tmp, e);
                if (n != 0) {
                    func_088C03CC(arg0, tmp, i);
                    if (nocopy == 0) {
                        memcpy(e, tmp, n);
                    }
                }
            }
            i++;
            p += 0x6810;
        } while (i < 6);
        func_08898748(D_09A0B540, 0x17);
        return 1;
    }
    return 0;
}

/* NonMatching (objdiff shows 0 % for this tail call; only the order
 * differs): the original reads the language table first and computes the
 * destination +0x9B0 + i * 0x28 last, ours computes it first. Tried: the
 * source and destination in locals, a Name array, the language index in a
 * local, other groupings of the sum. */
void func_088C03CC(char *arg0, char *blk, s32 i) {
    s32 *tbl;
    char *src;

    tbl = (s32 *) (blk + *(s32 *) (blk + *(s32 *) blk + 0x14));
    src = blk + *(s32 *) (blk + tbl[*(s32 *) (D_08A631A0 + 0xF7A574)]);
    func_0880ED70(arg0 + i * 0x28 + 0x9B0, src);
}
