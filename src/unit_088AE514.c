/* unit_088AE514: 0x088AE514-0x088AE598 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088AE4FC and unit_088AE598.
 *
 * Clears the 0x6C-byte message at D_09A29DEC, fills its header
 * (func_088AEF64, func_088B0324), its trailer at +0x62
 * (func_088B03CC) and its 0x42-byte body at +0x20 (func_088B040C),
 * then hands it over as message 8 (func_088B6B14). The symbol is a byte
 * array cast to the message type: a structure symbol folds the member
 * addresses into each argument.
 */

typedef int s32;

typedef struct {
    char unk0[8];
    char hdr[0x18];
    char body[0x42];
    char tail[0xA];
} Msg;

extern char D_09A29DEC[];

extern s32 func_088AFE84(void);
extern void func_0880C464(void *, s32, s32);
extern void func_088AEF64(char *);
extern s32 func_088B0324(char *, s32);
extern void func_088B03CC(char *, s32);
extern void func_088B040C(char *, s32, s32);
extern void func_088B6B14(s32);

void func_088AE514(void) {
    s32 n = func_088AFE84();
    Msg *m;

    func_0880C464(D_09A29DEC, 0, 0x6C);
    m = (Msg *) D_09A29DEC;
    func_088AEF64((char *) m);
    n = func_088B0324(m->hdr, n);
    func_088B03CC(m->tail, n);
    func_088B040C(m->body, 0x42, n);
    func_088B6B14(8);
}
