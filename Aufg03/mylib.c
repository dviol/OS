/* Dennis Violante
 * Gruppe 5
 * 09.04.16*/
 
/*Because it should be compiled as a library, the command should look like this:
 * gcc -Wall -shared -o mylib.so -fPIC mylib.c
 * to clarify that this is compiled as a shared object
 * 
 * Explanation:
 * -shared
 * 		Linker Option
 *		Produce a shared object which can then be linked with other objects to form an executable.
 * 		For predictable results, you must also specify the same set of options used for compilation 
 * 		(-fpic, -fPIC, or model suboptions) when you specify this linker option
 * -fPIC
 * 		Code Generation Convention
 * 		If supported for the target machine, emit position-independent code, 
 * 		suitable for dynamic linking and avoiding any limit on the size of the global offset table.
 * 		This option makes a difference on AArch64, m68k, PowerPC and SPARC.
 * 		Position-independent code requires special support, and therefore works only on certain machines.
 * 
 * source: https://gcc.gnu.org/onlinedocs/gcc/Option-Summary.html
 */

//Local method, won't work from outside
static int addTwoLoc(int num){
	return num+2;
	
	}

//Normal Global method	
int addTwo(int num){
	return num+2;
}

int main(){
	
	return 0;
}
