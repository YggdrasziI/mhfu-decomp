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

s32 func_088C022C(char *arg0, char *buf, s32 nocopy) {
    char *tmp;
    s32 i;
    char *e;
    s32 n;
    u32 p;
    u8 digest[0x14];
    Hdr hdr;

    func_088C2D74(arg0, buf, 0x16A100, D_089B2C94, 1);
    memcpy(&hdr, buf + 0x16A0DC, sizeof(Hdr));
    memcpy(buf + 0x16A0DC, D_089B4DF8, 0x14);
    func_089040A0(buf, 0x16A0F0, digest);
    memcpy(buf + 0x16A0DC, &hdr, sizeof(Hdr));
    if (func_0880BFF0(digest, hdr.digest, 0x14) == 0) {
        tmp = func_08898694(D_09A0B540, 0x17, 0x6800);
        memset(arg0 + 0x9B0, 0, 0xF0);
        for (i = 0, p = 0; i < 6; i++, p += 0x6810) {
            e = (*(char **) (arg0 + 0x94C) + 0x142300) + (s32) p;
            if (*(s32 *) e != 0) {
                n = func_088C2BE0(arg0, tmp, e);
                if (n != 0) {
                    func_088C03CC(arg0, tmp, i);
                    if (nocopy == 0) {
                        memcpy(e, tmp, n);
                    }
                }
            }
        }
        func_08898748(D_09A0B540, 0x17);
        return 1;
    }
    return 0;
}

void func_088C03CC(char *arg0, char *blk, s32 i) {
    char *e;
    char **t;

    e = *(char **) (blk + *(s32 *) blk + 0x14);
    t = (char **) (blk + (s32) e);
    t = &t[*(s32 *) (D_08A631A0 + 0xF7A574)];
    e = *t;
    func_0880ED70(arg0 + i * 0x28 + 0x9B0, *(char **) (e + (s32) blk) + (s32) blk);
}
