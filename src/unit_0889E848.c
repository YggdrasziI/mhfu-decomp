/* unit_0889E848: 0x0889E848-0x0889E8F8 (ULES01213)
 *
 * Logs three strings, runs the init helpers and stores arg0.
 */

typedef int s32;

extern int func_0880D9EC(char *, ...);
extern void func_0889EEA0(void);
extern void func_0889EF40(void);
extern void func_088A3F30(s32);
extern void func_088A3FF4(void *);
extern void func_088A32A0(s32, s32);
extern void func_0889F9C4(void);

extern char D_089B1F44[];
extern char D_089B1F4C[];
extern char D_089B1F54[];
extern char D_089B1F88[];
extern s32 D_09A0B560;

void func_0889E848(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_0880D9EC(D_089B1F44);
    func_0880D9EC(D_089B1F4C);
    func_0880D9EC(D_089B1F54, D_089B1F88, 1, 8);
    func_0889EEA0();
    func_0889EF40();
    func_088A3F30(arg1);
    func_088A3FF4(func_0889F9C4);
    func_088A32A0(arg2, arg3);
    D_09A0B560 = arg0;
}
