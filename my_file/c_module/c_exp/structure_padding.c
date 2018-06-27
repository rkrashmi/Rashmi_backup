
/*Find the size of structures given below with and without using 
 * #pragma pack and with different alignments 
 * and find out the proper reasons.
 * check all possibilities for each and every structure
 */

struct A {
    int a;
    int b:16;
    int c:16;
}s1;


struct B {
    char a:8;
    int b:24;
    short int c:12;
}s2;


struct C {
    int a:16;
    float b:16;
    char c:7;
}s3;


struct D {
    int a;
    char b:7;
    short int c:9;
    char d:6;
}s4;


struct E {
    int a;
    char b:7;
    short int c:10;
    char d:7;
}s5;



struct F {
    char b:6;
    short int a:10;
}s6;


struct G {
    short int a:9;
    char b;
    char c:6;
    char d:6;
    short int e:10;
}s7;


struct H {
    int a:20;
    char b:9;

}s8;



struct I {
    char a:6;
    static int b:20;
}s9;


struct J {
// NO elements
}s10;



struct K {
    char a;
    char :0;
    char c:7;
}s11;


struct L {
    int a:6;
    int :0;
    char b:4;
}s12;


struct M {
    int a:6;
    int :27;
    char c;
    char b:4;
}s13;



struct N {
    char a;
    char b:0;
}s14;



