/* unit_088DC6E8: 0x088DC6E8-0x088DC720 (ULES01213)
 *
 * Bounds (hypothesis): a run of accessors between a VFPU function (before) and an
 * initialiser of the same object (func_088DC720, after: it clears the fields at
 * 0x144, 0x148 and 0x14C set here). Field names are not known.
 */

typedef struct {
    char pad[0x144];
    int unk144;
    int unk148;
    int unk14C;
} Obj;

typedef struct {
    char pad[0x8];
    int offset; /* from the start of the block */
} Block;

char *func_088DC6E8(Obj *o, Block *b) { return (char *)b + b->offset; }
void func_088DC6F4(Obj *o, int v) { o->unk148 = v; }
void func_088DC6FC(Obj *o, int v) { o->unk14C = v; }
void func_088DC704(Obj *o, int v) { o->unk144 = v; }
char *func_088DC70C(Obj *o, Block *b) { return (char *)b + b->offset; }
char *func_088DC718(Obj *o, char *p) { return p + 0xC; }
