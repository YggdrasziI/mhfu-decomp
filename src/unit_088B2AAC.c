/* unit_088B2AAC: 0x088B2AAC-0x088B2B28 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088B29A4 and unit_088B2B28.
 *
 * When the record at D_09A44044 is active, runs func_088B2B28,
 * func_088B3118 or func_088B3124 on it for phase 0, 1 or 2 (as
 * func_088ADF58).
 */

typedef unsigned char u8;

typedef struct {
    char unk0[0x20];
    u8 active;
    u8 phase;
} Record;

extern char D_09A44044[];

extern void func_088B2B28(Record *);
extern void func_088B3118(Record *);
extern void func_088B3124(Record *);

void func_088B2AAC(void) {
    Record *r = (Record *) D_09A44044;

    if (r->active) {
        switch (r->phase) {
        case 0:
            func_088B2B28(r);
            break;
        case 1:
            func_088B3118(r);
            break;
        case 2:
            func_088B3124(r);
            break;
        }
    }
}
