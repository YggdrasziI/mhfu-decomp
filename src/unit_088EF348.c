/* unit_088EF348: 0x088EF348-0x088EF380 (ULES01213)
 *
 * Bounds (hypothesis): four forwarders that pass the address of D_09A4F0D4 to
 * func_088AD378 / func_088AD46C, then an empty function; the code around is
 * unrelated. Other parameters, if any, are passed through unchanged.
 */

extern char D_09A4F0D4[];
extern void func_088AD378();
extern void func_088AD46C();

void func_088EF348(void) { func_088AD378(D_09A4F0D4); }
void func_088EF354(void) { func_088AD46C(D_09A4F0D4); }
void func_088EF360(void) { func_088AD378(D_09A4F0D4); }
void func_088EF36C(void) { func_088AD46C(D_09A4F0D4); }
void func_088EF378(void) {}
