//#pragma once
#include "UTFramework.h"
#include "Task.h"

void TestNull() {
    AssertEqual(IsPalindrom(""), true, "");
}

void Test1Smbl() {
    AssertEqual(IsPalindrom("q"), true, "q");
    AssertEqual(IsPalindrom("1"), true, "1");
    AssertEqual(IsPalindrom("%"), true, "%");
}

void Test2SmblOK() {
    AssertEqual(IsPalindrom("ww"), true, "ww");
    AssertEqual(IsPalindrom("22"), true, "22");
    AssertEqual(IsPalindrom("%%"), true, "%%");
}

void Test2SmblNOK() {
    AssertEqual(IsPalindrom("er"), false, "er");
    AssertEqual(IsPalindrom("34"), false, "34");
    AssertEqual(IsPalindrom("%*"), false, "%*");
}

void TestDiffSmbOK() {
    AssertEqual(IsPalindrom("ererrere"), true, "ererrere");
    AssertEqual(IsPalindrom("!345612216543!"), true, "!345612216543!");
    AssertEqual(IsPalindrom("%*%*%*%*%*%*%*%"), true, "%*%*%*%*%*%*%*%");
    AssertEqual(IsPalindrom("z% %2%*%4%*%2% %z"), true, "z% %2%*%4%*%2% %z");
    AssertEqual(IsPalindrom("n/ %2% %4% %2% /n"), true, "n/ %2% %4% %2% /n");
}

void TestDiffSmbNOK() {
    AssertEqual(IsPalindrom(" tytyytyt"), false, " tytyytyt");
    AssertEqual(IsPalindrom("uiuiiuiu "), false, "uiiuuiiu ");
    AssertEqual(IsPalindrom("!34561-+16543!"), false, "!34561-+16543!");
    AssertEqual(IsPalindrom("/%*%*%*%*%*%*%*%."), false, "/%*%*%*%*%*%*%*%.");
    AssertEqual(IsPalindrom("z% %2%*%/.%*%2% %z"), false, "z% %2%*%/.%*%2% %z");
    AssertEqual(IsPalindrom("n. %2% %,.% %2% .n"), false, "n. %2% %,.% %2% .n");
}
