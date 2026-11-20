/* unit_088AE610: 0x088AE610-0x088AE694 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088AE598 and unit_088AE694.
 *
 * Clears the 0x324-byte message at D_09A29E58, fills its header
 * (func_088AEF64, func_088B0324), its trailer at +0x320
 * (func_088B03CC) and its 0x300-byte body at +0x20 (func_088B040C),
 * then hands it over as message 9 (func_088B6B14). The symbol is a byte
 * array cast to the message type: a structure symbol folds the member
 * addresses into each argument.
 */

typedef int s32;

typedef struct {
    char unk0[8];
    char hdr[0x18];
    char body[0x300];
    char tail[0x4];
} Msg;

extern char D_09A29E58[];

extern s32 func_088AFE84(void);
extern void memset(void *, s32, s32);
extern void func_088AEF64(char *);
extern s32 func_088B0324(char *, s32);
extern void func_088B03CC(char *, s32);
extern void func_088B040C(char *, s32, s32);
extern void func_088B6B14(s32);

void func_088AE610(void) {
    s32 n = func_088AFE84();
    Msg *m;

    memset(D_09A29E58, 0, 0x324);
    m = (Msg *) D_09A29E58;
    func_088AEF64((char *) m);
    n = func_088B0324(m->hdr, n);
    func_088B03CC(m->tail, n);
    func_088B040C(m->body, 0x300, n);
    func_088B6B14(9);
}
