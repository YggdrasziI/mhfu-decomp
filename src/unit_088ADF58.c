/* unit_088ADF58: 0x088ADF58-0x088ADFD4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088ADEF0 and unit_088ADFD4.
 *
 * When the record at D_09A43FA4 is active (+0x20), runs the handler of its
 * phase (+0x21). The record is declared as a byte array and cast: a
 * structure symbol has its member addresses folded into the loads.
 */

typedef unsigned char u8;

typedef struct {
    char unk0[0x20];
    u8 active;
    u8 phase;
} Record;

extern char D_09A43FA4[];

extern void func_088ADFD4(Record *);
extern void func_088AE0BC(Record *);
extern void func_088AE0C8(Record *);

void func_088ADF58(void) {
    Record *r = (Record *) D_09A43FA4;

    if (r->active) {
        switch (r->phase) {
        case 0:
            func_088ADFD4(r);
            break;
        case 1:
            func_088AE0BC(r);
            break;
        case 2:
            func_088AE0C8(r);
            break;
        }
    }
}
