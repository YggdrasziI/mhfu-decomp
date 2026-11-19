/* unit_088B29A4: 0x088B29A4-0x088B2AAC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088B2854 and unit_088B2AAC.
 *
 * Reads from the current message two bytes into D_09A299AC, then for each
 * of the D_09A299AC[1] entries an index and the three parts of the
 * 0xC8-byte record at that index in D_09A299B0 (func_088B0318,
 * func_088B0324, func_088B0370), storing the index at +0xC4. Sets
 * D_09A28877.
 */

typedef unsigned char u8;
typedef int s32;

typedef struct {
    u8 unk0;
    u8 count;
} Hdr;

typedef struct {
    char unk0[8];
    char unk8[0x18];
    char unk20[0xA4];
    u8 unkC4;
    char padC5[3];
} Rec;

extern char D_09A299AC[];
extern Rec D_09A299B0[];
extern u8 D_09A28877;

extern char *func_088AFE84(void);
extern char *func_088B03BC(u8 *, char *);
extern char *func_088B0318(Rec *, char *);
extern char *func_088B0324(char *, char *);
extern char *func_088B0370(char *, char *);

void func_088B29A4(void) {
    Hdr *hdr;
    Rec *recs;
    char *src;
    s32 i;
    u8 idx;

    src = func_088AFE84();
    hdr = (Hdr *) D_09A299AC;
    recs = D_09A299B0;
    src = func_088B03BC(&hdr->unk0, src);
    src = func_088B03BC(&hdr->count, src);
    i = 0;
    if (hdr->count > 0) do {
        src = func_088B03BC(&idx, src);
        recs[idx].unkC4 = idx;
        src = func_088B0318(&recs[idx], src);
        src = func_088B0324(recs[idx].unk8, src);
        src = func_088B0370(recs[idx].unk20, src);
        i++;
    } while (i < hdr->count);
    D_09A28877 = 1;
}
