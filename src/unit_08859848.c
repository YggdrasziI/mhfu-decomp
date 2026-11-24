/* unit_08859848: 0x08859848-0x08859AE4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08859848 (ULES01213), 0x29C bytes.
 *
 * Reads a chunk container whose header starts with ".TMH" (bytes checked at
 * 0x08859848), then walks size-prefixed chunks: group i (kind 0), entry j of
 * that group (kind 1) and, unless the entry type is 1 or 3, entry
 * count(0x08)+k of the group (kind 2). Field names are hypotheses.
 *
 * Speed setting: the first two walks are unrolled by 8. The third walk is
 * not: its counter is s32 against a u32 bound (an u32 counter unrolls). */
#pragma optimize_for_size off

typedef int s32;
typedef short s16;
typedef unsigned int u32;
typedef unsigned short u16;

typedef struct {
    char *data; /* 0x00 */
    s32 type; /* 0x04 */
    u16 w; /* 0x08 */
    u16 h; /* 0x0A */
    char *pal; /* 0x0C */
    s32 palType; /* 0x10 */
    s32 palCount; /* 0x14 */
} Out;

s32 func_08859848(void *arg0, char *hdr, s32 i, s32 j, u32 k, Out *out) {
    char *p;
    char *q;
    char *r;
    s32 n;
    s32 m;
    u32 cnt;
    char *data;
    s32 type;
    u16 w;
    u16 h;
    s32 palCount;
    s32 palType;
    char *pal;

    if (hdr[0] != '.' || hdr[1] != 'T' || hdr[2] != 'M' || hdr[3] != 'H') return 0;
    if (i >= *(s32 *)(hdr + 8)) return 0;
    p = hdr + 0x10;
    for (n = 0; n < i; n++) p += *(s32 *)p;
    if (*(s32 *)(p + 4) != 0) return 0;
    if ((u32)j >= *(u32 *)(p + 8)) return 0;
    q = p + 0x10;
    for (n = 0; n < j; n++) q += *(s32 *)q;
    if (*(s32 *)(q + 4) != 1) return 0;
    data = q + 0x10;
    type = *(s32 *)(q + 8);
    w = *(u16 *)(q + 0xC);
    h = *(u16 *)(q + 0xE);
    if (type == 1 || type == 3) {
        pal = 0;
        palType = 0;
        palCount = 0;
    } else {
        if (k >= *(u32 *)(p + 0xC)) return 0;
        r = p + 0x10;
        cnt = *(u32 *)(p + 8) + k;
        m = 0;
        while (m < cnt) {
            r += *(s32 *)r;
            m++;
        }
        if (*(s32 *)(r + 4) != 2) return 0;
        palType = *(s32 *)(r + 8);
        palCount = *(s16 *)(r + 0xC);
        pal = r + 0x10;
    }
    out->data = data;
    out->type = type;
    out->w = w;
    out->h = h;
    out->pal = pal;
    out->palType = palType;
    out->palCount = palCount;
    return 1;
}
