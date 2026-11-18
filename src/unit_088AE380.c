/* unit_088AE380: 0x088AE380-0x088AE3FC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088AE374 and unit_088AE3FC.
 *
 * When the record at D_09A43FF4 is active (+0x20), runs the handler of its
 * phase (+0x21). The record is declared as a byte array and cast: a
 * structure symbol has its member addresses folded into the loads.
 */

typedef unsigned char u8;

typedef struct {
    char unk0[0x20];
    u8 active;
    u8 phase;
} Record;

extern char D_09A43FF4[];

extern void func_088AE3FC(Record *);
extern void func_088AE4FC(Record *);
extern void func_088AE508(Record *);

void func_088AE380(void) {
    Record *r = (Record *) D_09A43FF4;

    if (r->active) {
        switch (r->phase) {
        case 0:
            func_088AE3FC(r);
            break;
        case 1:
            func_088AE4FC(r);
            break;
        case 2:
            func_088AE508(r);
            break;
        }
    }
}
