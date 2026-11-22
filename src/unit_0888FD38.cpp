/* unit_0888FD38: 0x0888FD38-0x0888FDFC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;

typedef struct V18 { virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); } V18;

extern "C" {

extern V18 *D_089CC434;
extern char *D_08A62C40;
extern char *D_08A62C64;
extern char *D_08A631A8;
extern char *D_09A4F0D0;
extern char *D_089CBFFC;
extern char *D_08A8B1E8;
extern char *D_08A62D8C;

extern void func_0888FDFC(char *);
extern void func_088590B0(char *);
extern void func_08868F50(char *);
extern void func_08890BBC(char *);
extern void func_088DDA44(char *);
extern void func_0884C22C(char *);
extern void func_08895538(char *);
extern void func_0884BB58(char *);
extern void func_0884BB00(char *);
extern void func_08880708(char *);
extern void func_08891B14(char *);

void func_0888FD38(char *arg0) {
    func_0888FDFC(arg0);
    for (;;) {
        func_088590B0(D_08A62C40);
        func_08868F50(D_08A62C64);
        func_08890BBC(D_08A631A8);
        D_089CC434->vfunc_14();
        func_088DDA44(D_09A4F0D0);
        func_0884C22C(D_089CBFFC);
        func_08895538(D_08A8B1E8);
        func_0884BB58(D_089CBFFC);
        func_0884BB00(D_089CBFFC);
        func_08880708(D_08A62D8C);
        func_08891B14(D_08A631A8);
        (*(s32 *)(arg0 + 0xF7A554))++;
    }
}

}
