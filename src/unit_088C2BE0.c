/* unit_088C2BE0: 0x088C2BE0-0x088C2CE0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088C2B94 (NonMatching) and
 * unit_088C2CE0.
 *
 * Decodes a block with the four-state key arg2 through func_088C2CE0: an
 * 0x18-byte header (length, digest), then the data, checked against the
 * digest of the data and D_089B4F08; returns the length or 0.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

/* The decoder state: four 16-bit keystream states at +0xAA0. */
typedef struct {
    u8 pad0[0xAA0];
    u16 keys[4];
} Dec;

typedef struct {
    u32 len;
    u8 digest[0x14];
} BlkHdr;

extern char D_089B4F08[];

extern s32 func_0880BFF0(void *, void *, s32);
extern void func_0880ED70(char *, char *);
extern void func_088C2B54(Dec *, s32, u16);
extern void func_088C2CE0(Dec *, void *, u16 *, s32, s32, u32);
extern void func_089040A0(char *, s32, u8 *);

u32 func_088C2BE0(Dec *arg0, char *out, u16 *key) {
    BlkHdr hdr;
    u8 digest[0x14];
    u32 i;
    u16 *k;

    i = 0;
    k = key;
    do {
        func_088C2B54(arg0, i, *k);
        i++;
        k++;
    } while (i < 4);
    func_088C2CE0(arg0, &hdr, key, 0, 8, sizeof(BlkHdr));
    if (hdr.len < 0x6800) {
        func_088C2CE0(arg0, out, key, 0, 0x20, hdr.len);
        func_0880ED70(out + hdr.len, D_089B4F08);
        func_089040A0(out, hdr.len + 0x10, digest);
        if (func_0880BFF0(digest, hdr.digest, 0x14) == 0) {
            return hdr.len;
        }
    }
    return 0;
}
