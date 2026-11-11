/* unit_0885148C: 0x0885148C-0x088516A4 (ULES01213)
 *
 * Bounds (hypothesis): func_0885148C and func_088514AC with the 21 small functions
 * that call func_088514AC with a constant section number; the code before is an
 * unrelated loop, the code after a switch.
 *
 * D_089CC440 holds a block whose word 2 + n is the offset of section n; each
 * section starts with a table of 32-bit offsets, -1 for an empty entry.
 */

typedef unsigned short u16;

extern int D_089CC440[];
extern u16 D_0899A1FC[];
extern u16 D_0899AAF8[];
extern u16 D_0899ADBC[];
extern u16 D_0899B124[];
extern u16 D_0899B46C[];
extern u16 D_0899B7A4[];
extern u16 D_0899BAD8[];

extern void func_0880C084(void *dst, const void *src, int size);

char *func_0885148C(int unused, int section) {
    int i = section + 2;

    return (char *)D_089CC440 + D_089CC440[i];
}

char *func_088514AC(int arg, int section, u16 entry) {
    char *base = func_0885148C(arg, section);
    int offset;

    if (entry == 0xFFFF) {
        return 0;
    }
    func_0880C084(&offset, base + entry * 4, 4);
    if (offset == -1) {
        return 0;
    }
    return base + offset;
}

char *func_0885151C(int arg, u16 entry) { return func_088514AC(arg, 0, entry); }
char *func_08851528(int arg, u16 entry) { return func_088514AC(arg, 1, entry); }
char *func_08851534(int arg, u16 entry) { return func_088514AC(arg, 2, entry); }
char *func_08851540(int arg, u16 entry) { return func_088514AC(arg, 3, entry); }
char *func_0885154C(int arg, u16 i) { return func_088514AC(arg, 4, D_0899A1FC[i]); }
char *func_0885156C(int arg, u16 entry) { return func_088514AC(arg, 5, entry); }
char *func_08851578(int arg, u16 i) { return func_088514AC(arg, 6, D_0899AAF8[i]); }
char *func_08851598(int arg, u16 entry) { return func_088514AC(arg, 7, entry); }
char *func_088515A4(int arg, u16 i) { return func_088514AC(arg, 8, D_0899ADBC[i]); }
char *func_088515C4(int arg, u16 entry) { return func_088514AC(arg, 9, entry); }
char *func_088515D0(int arg, u16 i) { return func_088514AC(arg, 10, D_0899B124[i]); }
char *func_088515F0(int arg, u16 entry) { return func_088514AC(arg, 11, entry); }
char *func_088515FC(int arg, u16 i) { return func_088514AC(arg, 12, D_0899B46C[i]); }
char *func_0885161C(int arg, u16 entry) { return func_088514AC(arg, 13, entry); }
char *func_08851628(int arg, u16 i) { return func_088514AC(arg, 14, D_0899B7A4[i]); }
char *func_08851648(int arg, u16 entry) { return func_088514AC(arg, 15, entry); }
char *func_08851654(int arg, u16 i) { return func_088514AC(arg, 16, D_0899BAD8[i]); }
char *func_08851674(int arg, u16 entry) { return func_088514AC(arg, 17, entry); }
char *func_08851680(int arg, u16 entry) { return func_088514AC(arg, 18, entry); }
char *func_0885168C(int arg, u16 entry) { return func_088514AC(arg, 21, entry); }
char *func_08851698(int arg, u16 entry) { return func_088514AC(arg, 22, entry); }
