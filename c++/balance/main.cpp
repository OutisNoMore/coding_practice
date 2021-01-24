#include <cstdio>

#include "balanced.h"

#define ASSERT(t, b) (printf("%s %s\n", t, (b ? "PASSED" : "FAILED")))

int main(){
	Balanced test("hello"); //expect ""
	ASSERT("Expect fail:", test.isBalanced());

	Balanced test2("())"); // expect ())
	ASSERT("Expect fail:", test2.isBalanced());

	Balanced test3("{{()}}");
	ASSERT("Expect passed:", test3.isBalanced());

	Balanced test4("{{([][])}()}");
	ASSERT("Expect passed:", test4.isBalanced());

	Balanced test5("{((}))");
	ASSERT("Expect fail:", test5.isBalanced());

	Balanced test6("(()");
	ASSERT("Expect fail:", test6.isBalanced());

	return 0;
}
