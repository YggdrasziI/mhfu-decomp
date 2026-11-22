/* unit_088A5AFC: 0x088A5AFC-0x088A5B50 (ULES01213) */

typedef int s32;

extern int func_0880D9EC(char *, ...);

extern s32 D_09A0EB6C;
extern char D_089B2710[];
extern char D_089B2718[];
extern char D_089B2720[];

s32 func_088A5AFC(void) {
    if (D_09A0EB6C == 0x40) {
        func_0880D9EC(D_089B2710);
        func_0880D9EC(D_089B2718);
        func_0880D9EC(D_089B2720);
        return 0x80000010;
    }
    return 0;
}
