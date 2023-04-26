#include "Sequence.h"
#include <cassert>
using namespace std;

int main() {

    /* ItemType = std::string */

    // Sequence ss;
    // ss.insert(0, "aaa");
    // ss.insert(1, "bbb");
    // ss.insert(2, "ccc");
    // ItemType z = "zzz";
    // assert(!ss.get(3, z)  &&  z == "zzz");  // x is unchanged
    // assert(ss.get(1, z)  &&  z == "bbb");
    
    // Sequence s;
    // assert(s.insert(0, "lavash") == 0);
    // assert(s.insert(0, "tortilla") == 0);
    // assert(s.size() == 2);
    // ItemType p = "injera";
    // assert(s.get(0, p)  &&  p == "tortilla");
    // assert(s.get(1, p)  &&  p == "lavash");
   
    // Sequence q;
    // q.insert(0, "hello");
    // q.insert(1, "goodbye");
    
    // Sequence m = q;         //copy constructor
    
    // assert(q.remove("hello") == 1);

    // cout << "Passed all tests" << endl;
 





    /* ItemType = unsigned long */
 
    // test insert()
    Sequence p;
    p.insert(0, 1);
    p.insert(1, 2);
    p.insert(2, 4);
    p.insert(3, 5);
    p.insert(4, 6);
    p.insert(0, 7);
    p.insert(3, 8);
    
    Sequence q;
    q.insert(0, 8);
    q.insert(1, 4);
    q.insert(2, 5);
    
    Sequence r;
    r.insert(0, 7);
    r.insert(1, 1);
    r.insert(2, 2);
    r.insert(3, 4);
    r.insert(4, 5);
    
    Sequence m;
    m.insert(0, 7);
    m.insert(1, 1);
    m.insert(2, 2);
    m.insert(3, 8);
    m.insert(4, 4);
    
    Sequence cool;
    cool.insert(0, 1);
    cool.insert(1, 2);
    cool.insert(2, 4);
    cool.insert(3, 5);
    cool.insert(4, 6);
    
    Sequence my;
    my.insert(0, 1);
    my.insert(1, 2);
    my.insert(2, 4);
    my.insert(3, 5);
    my.insert(4, 6);
  
    // test subsequence()
    assert(subsequence(p, q) == 3);
    assert(subsequence(p, r) == -1);
    assert(subsequence(p, m) == 0);

    // test insert()
    assert(m.insert(8) == 3);  // with 1
    assert(cool.insert(3) == 2);
    assert(cool.insert(0) == 0);
    assert(m.insert(9) == 6);
    assert(my.insert(6) == 4 && my.size() == 6);
    
    // test erase()
    assert(r.erase(0) && r.size() == 4);
    ItemType boo;
    assert(r.get(0, boo) && boo == 1);
    assert(r.erase(3) && r.size() == 3);
    assert(r.get(2, boo) && boo == 4);
    assert(!r.get(3, boo));
    assert(r.erase(1) && r.size() == 2);
    assert(r.get(0, boo) && boo == 1);
    assert(r.get(1, boo) && boo == 4);
    
    Sequence seq1;
    seq1.insert(0, 30);
    seq1.insert(1, 21);
    seq1.insert(2, 63);
    seq1.insert(3, 42);
    seq1.insert(4, 17);
    seq1.insert(5, 63);
    
    Sequence seq2;
    seq2.insert(0, 42);
    seq2.insert(1, 63);
    seq2.insert(2, 84);
    seq2.insert(3, 19);
    
    // test concatReverse()
    Sequence result;  // with diff sizes, bigger first
    concatReverse(seq1, seq2, result);
    ItemType k;
    assert(result.get(0, k)  &&  k == 30);
    assert(result.get(1, k)  &&  k == 42);
    assert(result.get(2, k)  &&  k == 21);
    assert(result.get(3, k)  &&  k == 63);
    assert(result.get(4, k)  &&  k == 63);
    assert(result.get(5, k)  &&  k == 84);
    assert(result.get(6, k)  &&  k == 42);
    assert(result.get(7, k)  &&  k == 19);
    assert(result.get(8, k)  &&  k == 17);
    assert(result.get(9, k)  &&  k == 63);

    Sequence a;
    a.insert(0, 1);
    a.insert(1, 2);

    Sequence b;
    b.insert(0, 3);
    b.insert(1, 4);
    b.insert(2, 5);
    b.insert(3, 6);

    // test concatReverse()
    Sequence result2;
    concatReverse(a, b, result2);  // different sizes, bigger second
    ItemType blah;
    assert(result2.get(0, blah)  &&  blah == 1);
    assert(result2.get(1, blah)  &&  blah == 3);
    assert(result2.get(2, blah)  &&  blah == 2);
    assert(result2.get(3, blah)  &&  blah == 4);
    assert(result2.get(4, blah)  &&  blah == 5);
    assert(result2.get(5, blah)  &&  blah == 6);

    Sequence c;
    c.insert(0, 1);
    c.insert(1, 2);
    
    Sequence d;
    d.insert(0, 3);
    d.insert(1, 4);
    
    // test concatReverse()
    Sequence result3;
    concatReverse(c, d, result3);  // with same size
    ItemType woo;
    assert(result3.get(0, woo)  &&  woo == 1);
    assert(result3.get(1, woo)  &&  woo == 3);
    assert(result3.get(2, woo)  &&  woo == 2);
    assert(result3.get(3, woo)  &&  woo == 4);
    
    // empty
    Sequence e;
    
    Sequence f;
    f.insert(0, 1);
    f.insert(1, 2);
    
    // test concatReverse()
    Sequence result4;
    concatReverse(e, f, result4);  // with first empty
    ItemType ya;
    assert(result4.get(0, ya)  &&  ya == 1);
    assert(result4.get(1, ya)  &&  ya == 2);
    
    Sequence result5;
    concatReverse(f, e, result5);  // with second empty
    ItemType hi;
    assert(result5.get(0, hi)  &&  hi == 1);
    assert(result5.get(1, hi)  &&  hi == 2);
    
    Sequence h;
    Sequence resultempty;  // with both empty
    concatReverse(e, h, resultempty);
    ItemType empty;
    assert(!resultempty.get(0, empty));
    assert(resultempty.empty());
  
 
    Sequence x;
    x.insert(0, 0);
    x.insert(1, 1);
  
    // test copy constructor
    Sequence x2 = x;
    ItemType ab;
    assert(x2.get(0, ab) && ab == 0);
    assert(x2.get(1, ab) && ab == 1);
    

    // test assignment operator
    Sequence o;
    o = x2;
    ItemType ba;
    assert(o.get(0, ba) && ba == 0);
    assert(o.get(1, ba) && ba == 1);
 
    x = x2;
    ItemType cd;
    assert(x.get(0, cd) && cd == 0);
    assert(x.get(1, cd) && cd == 1);
 
  
  
    Sequence yz;
    yz.insert(0, 0);
    yz.insert(1, 1);
    yz.insert(2, 2);
    yz.insert(3, 3);
    yz.insert(4, 4);
    yz.insert(5, 5);

    // test remove()
    ItemType z;
    assert(yz.remove(1) == 1 && yz.size() == 5);
    assert(yz.get(1, z) && z == 2);
    assert(yz.remove(5) == 1 && yz.size() ==4);  // last element
    assert(yz.get(3, z) && z == 4);
    assert(yz.remove(0) == 1 && yz.size() == 3);  // first element
    assert(yz.get(0, z) && z == 2);

    Sequence op;
    op.insert(0, 0);
    op.insert(1, 1);
    op.insert(2, 2);
    op.insert(3, 3);
    op.insert(4, 4);
    op.insert(5, 5);
    
    // test find()
    assert(op.find(0) == 0);
    assert(op.find(1) == 1);
    assert(op.find(2) == 2);
    assert(op.find(3) == 3);
    assert(op.find(4) == 4);
    assert(op.find(5) == 5);
    assert(op.find(100) == -1);

    Sequence pi;
    pi.insert(0, 10);
    pi.insert(1, 11);
    pi.insert(2, 12);
    pi.insert(3, 13);
    pi.insert(4, 14);
    pi.insert(5, 15);
    
    // test swap(), same sizes
    op.swap(pi);
    assert(pi.get(0, z) && z == 0);
    assert(pi.get(1, z) && z == 1);
    assert(pi.get(2, z) && z == 2);
    assert(pi.get(3, z) && z == 3);
    assert(pi.get(4, z) && z == 4);
    assert(pi.get(5, z) && z == 5);
    
    assert(op.get(0, z) && z == 10);
    assert(op.get(1, z) && z == 11);
    assert(op.get(2, z) && z == 12);
    assert(op.get(3, z) && z == 13);
    assert(op.get(4, z) && z == 14);
    assert(op.get(5, z) && z == 15);
    
    
    Sequence ii;
    ii.insert(0, 20);
    ii.insert(1, 21);
    ii.insert(2, 22);
    ii.insert(3, 23);
    
    // test swap(), different sizes
    op.swap(ii);
    
    assert(ii.get(0, z) && z == 10);
    assert(ii.get(1, z) && z == 11);
    assert(ii.get(2, z) && z == 12);
    assert(ii.get(3, z) && z == 13);
    assert(ii.get(4, z) && z == 14);
    assert(ii.get(5, z) && z == 15);
    
    assert(op.get(0, z) && z == 20);
    assert(op.get(1, z) && z == 21);
    assert(op.get(2, z) && z == 22);
    assert(op.get(3, z) && z == 23);

    
    // test alias
    op.swap(op);
  
    cout << "Passed all tests" << endl;
}
