/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: Arthur Boltak
 * 
 * Date: 2020-02
 */

#include "doctest.h"
#include "PhoneticFinder.hpp"
using namespace phonetic;

#include <string>
using namespace std;



TEST_CASE("Test replacement of p and b") {
    string text = "xxx happy yyy";
    CHECK(find(text, "happy") == string("happy"));
    CHECK(find(text, "habby") == string("happy"));
    CHECK(find(text, "hapby") == string("happy"));
    CHECK(find(text, "habpy") == string("happy"));
}
TEST_CASE("Test replacement of p and f") {
    string text = "aaaa bbb Happy";
    CHECK(find(text, "Happy") == string("Happy"));
    CHECK(find(text, "Haffy") == string("Happy"));
    CHECK(find(text, "Hapfy") == string("Happy"));
    CHECK(find(text, "Hafpy") == string("Happy"));
}
TEST_CASE("Test replacement of b and f") {
    string text = "this is brief";
    CHECK(find(text, "brief") == string("brief"));
    CHECK(find(text, "frief") == string("brief"));
    CHECK(find(text, "frieb") == string("brief"));
    CHECK(find(text, "brieb") == string("brief"));
}
TEST_CASE("Test replacement of i and y") {
    string text = "aaaa bbb Happiy";
    CHECK(find(text, "Happiy") == string("Happiy"));
    CHECK(find(text, "Happyi") == string("Happiy"));
    CHECK(find(text, "Happyy") == string("Happiy"));
    CHECK(find(text, "Happii") == string("Happiy"));
}
TEST_CASE("Test replacement of v and w") {
    string text = "aaaa view";
    CHECK(find(text, "view") == string("view"));
    CHECK(find(text, "viev") == string("view"));
    CHECK(find(text, "wiew") == string("view"));
    CHECK(find(text, "wiev") == string("view"));
}
TEST_CASE("Test replacement of g and j") {
    string text = "going home";
    CHECK(find(text, "going") == string("going"));
    CHECK(find(text, "joing") == string("going"));
    CHECK(find(text, "joinj") == string("going"));
    CHECK(find(text, "goinj") == string("going"));
}
TEST_CASE("Test replacement of s and z") {
    string text = "our stars";
    CHECK(find(text, "stars") == string("stars"));
    CHECK(find(text, "starz") == string("stars"));
    CHECK(find(text, "ztarz") == string("stars"));
    CHECK(find(text, "ztars") == string("stars"));
}
TEST_CASE("Test replacement of k and q") {
    string text = "a quark of water";
    CHECK(find(text, "quark") == string("quark"));
    CHECK(find(text, "kuark") == string("quark"));
    CHECK(find(text, "kuarq") == string("quark"));
    CHECK(find(text, "quarq") == string("quark"));
}
TEST_CASE("Test replacement of g,j and o,u and d,t") {
    string text = "on the ground";
    CHECK(find(text, "ground") == string("ground"));
    CHECK(find(text, "jround") == string("ground"));
    CHECK(find(text, "jruund") == string("ground"));
    CHECK(find(text, "jruond") == string("ground"));
    CHECK(find(text, "jruont") == string("ground"));
}
TEST_CASE("Test replacement of g,j and o,u and d,t upper/lower cases") {// 11 test cases
    string text = "on the GROUND";
    CHECK(find(text, "GROUND") == string("GROUND"));
    CHECK(find(text, "ground") == string("GROUND"));
    CHECK(find(text, "Ground") == string("GROUND"));
    CHECK(find(text, "GrounD") == string("GROUND"));
    CHECK(find(text, "GroUnD") == string("GROUND"));
    CHECK(find(text, "GRoUnD") == string("GROUND"));
    CHECK(find(text, "GRoUND") == string("GROUND"));
    CHECK(find(text, "grOund") == string("GROUND"));
    CHECK(find(text, "gRoUnD") == string("GROUND"));
    CHECK(find(text, "gRoUND") == string("GROUND"));
    CHECK(find(text, "gROUND") == string("GROUND"));
    CHECK(find(text, "JRUONT") == string("GROUND"));
    CHECK(find(text, "jruont") == string("GROUND"));
}

TEST_CASE("Test replacement of k and q upper/lower cases") {    //7 tests
    string text = "just a quarter";
    CHECK(find(text, "quarter") == string("quarter"));
    CHECK(find(text, "Quarter") == string("quarter"));
    CHECK(find(text, "Kuarter") == string("quarter"));
    CHECK(find(text, "QUARTER") == string("quarter"));
    CHECK(find(text, "QuArTeR") == string("quarter"));
    CHECK(find(text, "kUaRtEr") == string("quarter"));
    CHECK(find(text, "KUARTER") == string("quarter"));
}

TEST_CASE("Test replacement of c and q and thier upper/lower cases") {
    string text = "ur cute";
    CHECK(find(text, "cute") == string("cute"));
    CHECK(find(text, "qute") == string("cute"));
    CHECK(find(text, "Cute") == string("cute"));
    CHECK(find(text, "Qute") == string("cute"));
    CHECK(find(text, "QUTE") == string("cute"));
}
TEST_CASE("Test replacement of c and k") {  //8 tests
    string text = "aaaaaaaa clock kkkk";
    CHECK(find(text, "clock") == string("clock"));
    CHECK(find(text, "clocc") == string("clock"));
    CHECK(find(text, "klock") == string("clock"));
    CHECK(find(text, "klokk") == string("clock"));
    CHECK(find(text, "clokc") == string("clock"));
    CHECK(find(text, "clokk") == string("clock"));
    CHECK(find(text, "klokc") == string("clock"));
    CHECK(find(text, "klocc") == string("clock"));

}
TEST_CASE("Test replacement of t and d and lower/upper case") {  //7 tests
    string text = "aaaa Dont bbbbbb";
    CHECK(find(text, "Dond") == string ("Dont"));
    CHECK(find(text, "Dont") == string ("Dont"));
    CHECK(find(text, "Tond") == string ("Dont"));
    CHECK(find(text, "Tont") == string ("Dont"));
    CHECK(find(text, "tond") == string ("Dont"));
    CHECK(find(text, "tonD") == string ("Dont"));
    CHECK(find(text, "tonT") == string ("Dont"));
}
TEST_CASE("Test replacement of c,q,k and o,u") {    //10 tests
    string text = "the cook";
    CHECK(find(text, "cook") == string("cook"));
    CHECK(find(text, "qook") == string("cook"));
    CHECK(find(text, "kook") == string("cook"));
    CHECK(find(text, "kooq") == string("cook"));
    CHECK(find(text, "qooq") == string("cook"));
    CHECK(find(text, "cuuk") == string("cook"));
    CHECK(find(text, "couk") == string("cook"));
    CHECK(find(text, "cuok") == string("cook"));
    CHECK(find(text, "quok") == string("cook"));
    CHECK(find(text, "kuoq") == string("cook"));
}
TEST_CASE("Test replacement of s,z and c,q,k and o,u") {// 12 tests
    string text = "try to squeeze";
    CHECK(find(text, "squeeze") == string("squeeze"));
    CHECK(find(text, "zqueeze") == string("squeeze"));
    CHECK(find(text, "zqueese") == string("squeeze"));
    CHECK(find(text, "zcueeze") == string("squeeze"));
    CHECK(find(text, "skueese") == string("squeeze"));
    CHECK(find(text, "skoeeze") == string("squeeze"));
    CHECK(find(text, "cqoeese") == string("squeeze"));
    CHECK(find(text, "zkueeze") == string("squeeze"));
    CHECK(find(text, "squeeze") == string("squeeze"));
    CHECK(find(text, "scoeese") == string("squeeze"));
    CHECK(find(text, "zkoeeze") == string("squeeze"));
    CHECK(find(text, "zkoeese") == string("squeeze"));
}
TEST_CASE("Test replacement of lower-case and upper-case") {
    string text = "Happi xxx yyy";
    CHECK(find(text, "happi") == string("Happi"));
    CHECK(find(text, "Happi") == string("Happi"));
    CHECK(find(text, "HAPPI") == string("Happi"));
    CHECK(find(text, "HaPpI") == string("Happi"));
}

