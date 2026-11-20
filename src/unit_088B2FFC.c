/* unit_088B2FFC: 0x088B2FFC-0x088B30CC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088B2ED4 and unit_088B30CC.
 *
 * Counts an attempt in arg0[0x22], then for each of the D_09A29685 records
 * of D_09A29688 (index in D_09A29684): when func_088B04EC rejects it,
 * copies the whole list to D_09A299AC; else sends the list to it with
 * func_088B2854.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    s8 b[0x14];
} Id;

typedef struct {
    char unk0[0xC8];
} Rec;

extern u8 D_09A29684;
extern u8 D_09A29685;
extern Rec D_09A29688[];
extern u8 D_09A299AC;
extern u8 D_09A299AD;
extern Rec D_09A299B0[];

extern void memcpy(void *, void *, s32);
extern s32 func_088B04EC(Rec *);
extern void func_088B2854(Id *, Rec *, u8 *, Rec *);

void func_088B2FFC(u8 *arg0) {
    Id a;
    s32 i;
    Rec *rec;

    arg0[0x22]++;
    rec = D_09A29688;
    i = 0;
    if (D_09A29685 > 0) {
        do {
            D_09A29684 = i;
            if (func_088B04EC(rec) == 0) {
                D_09A299AC = D_09A29684;
                D_09A299AD = D_09A29685;
                memcpy(D_09A299B0, D_09A29688, 0x320);
            } else {
                func_088B2854(&a, rec, &D_09A29684, D_09A29688);
            }
            i++;
            rec++;
        } while (i < D_09A29685);
    }
}
