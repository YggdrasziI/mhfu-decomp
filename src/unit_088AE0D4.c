/* unit_088AE0D4: 0x088AE0D4-0x088AE16C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088AE0C8 and unit_088AE16C.
 *
 * When the record at D_09A43FCC is active (+0x20), runs the handler of its
 * phase (+0x21). The record is declared as a byte array and cast: a
 * structure symbol has its member addresses folded into the loads.
 */

typedef unsigned char u8;

typedef struct {
    char unk0[0x20];
    u8 active;
    u8 phase;
} Record;

extern char D_09A43FCC[];

extern void func_088AE16C(Record *);
extern void func_088AE274(Record *);
extern void func_088AE368(Record *);
extern void func_088AE374(Record *);

void func_088AE0D4(void) {
    Record *r = (Record *) D_09A43FCC;

    if (r->active) {
        switch (r->phase) {
        case 0:
            func_088AE16C(r);
            break;
        case 1:
            func_088AE274(r);
            break;
        case 2:
            func_088AE368(r);
            break;
        case 3:
            func_088AE374(r);
            break;
        }
    }
}
