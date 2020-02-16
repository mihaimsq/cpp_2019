#include "assignment2.h"
#include "gtest/gtest.h"

int vectorInitial[] = { 23,67,89,102,560,1000};
int nrElemente = 6;

TEST(NumarElementeMaiMari, TestNormal) {
	int valoarePrag = 100;
	int rezultat = numarElementeMaiMari(vectorInitial, nrElemente, valoarePrag);
	EXPECT_EQ(rezultat, 3);
}

TEST(NumarElementeMaiMari, TestLimita) {
	int valoarePrag = 102;
	int rezultat = numarElementeMaiMari(vectorInitial, nrElemente, valoarePrag);
	EXPECT_EQ(rezultat, 3);
}

TEST(NumarElementeMaiMari, TestOut) {
	int valoarePrag = 2000;
	int rezultat = numarElementeMaiMari(vectorInitial, nrElemente, valoarePrag);
	EXPECT_EQ(rezultat, 0);
}

TEST(FiltrareElementeMaiMari, TestNormal1) {
	int valoarePrag = 100;
	int* rezultat = filtrareElementeMaiMari(vectorInitial, nrElemente, valoarePrag);
	EXPECT_EQ(rezultat[0], 102);
}

TEST(FiltrareElementeMaiMari, TestNormal2) {
	int valoarePrag = 100;
	int* rezultat = filtrareElementeMaiMari(vectorInitial, nrElemente, valoarePrag);
	EXPECT_EQ(rezultat[2], 1000);
}

TEST(FiltrareElementeMaiMari, TestNULL) {
	int valoarePrag = 2000;
	int* rezultat = filtrareElementeMaiMari(vectorInitial, nrElemente, valoarePrag);
	ASSERT_TRUE(rezultat == NULL);
}

TEST(FiltrareElementeMaiMari2, TestNormal1) {
	int valoarePrag = 100;
	int* rezultat;
	filtrareElementeMaiMari2(vectorInitial, nrElemente, valoarePrag, &rezultat);
	EXPECT_EQ(rezultat[1], 560);
}

TEST(FiltrareElementeMaiMari2, TestNormal2) {
	int valoarePrag = 100;
	int* rezultat;
	filtrareElementeMaiMari2(vectorInitial, nrElemente, valoarePrag, &rezultat);
	EXPECT_EQ(rezultat[2], 1000);
}

TEST(FiltrareElementeMaiMari2, TestNULL) {
	int valoarePrag = 2000;
	int* rezultat;
	filtrareElementeMaiMari2(vectorInitial, nrElemente, valoarePrag, &rezultat);
	EXPECT_TRUE(rezultat == NULL);
}


TEST(GetElement, TestNormal1) {
	int rezultat = getElement(vectorInitial, nrElemente, 1);
	EXPECT_EQ(rezultat, 67);
}

TEST(GetElement, TestNormal2) {
	for (int i = 0; i < nrElemente; i++) {
		int rezultat = getElement(vectorInitial, nrElemente, i);
		EXPECT_EQ(rezultat, vectorInitial[i]);
	}
}

TEST(GetElement, TestExceptieIndexNegativ) {
	try {
		int rezultat = getElement(vectorInitial, nrElemente, -1);
		FAIL();
	}
	catch (ExceptieAssignment2* ex) {
		SUCCEED();
	}
	catch (...) {
		FAIL();
	}
}

TEST(GetElement, TestExceptieIndexLimita) {
	try {
		int rezultat = getElement(vectorInitial, nrElemente, nrElemente);
		FAIL();
	}
	catch (ExceptieAssignment2* ex) {
		SUCCEED();
	}
	catch (...) {
		FAIL();
	}
}

TEST(GetElement, TestExceptieIndexPreaMare) {
	try {
		int rezultat = getElement(vectorInitial, nrElemente, 1000);
		FAIL();
	}
	catch (ExceptieAssignment2* ex) {
		SUCCEED();
	}
	catch (...) {
		FAIL();
	}
}


TEST(Slice, TestNormal1) {
	//89,102,560
	int dimSlice;
	int* rezultat = slice(vectorInitial, nrElemente, 2, 4, dimSlice);
	EXPECT_EQ(rezultat[0], 89);
}

TEST(Slice, TestNormal2) {
	//89,102,560
	int dimSlice;
	int* rezultat = slice(vectorInitial, nrElemente, 2, 4, dimSlice);
	EXPECT_EQ(rezultat[2], 560);
}

TEST(Slice, TestNormal3) {
	//89,102,560
	int dimSlice;
	int* rezultat = slice(vectorInitial, nrElemente, 2, 4, dimSlice);
	EXPECT_EQ(dimSlice, 3);
}

TEST(Slice, TestNormalIndexEgal1) {
	//89,102,560
	int dimSlice;
	int* rezultat = slice(vectorInitial, nrElemente, 2, 2, dimSlice);
	EXPECT_EQ(dimSlice, 1);
}

TEST(Slice, TestNormalIndexEgal2) {
	//89,102,560
	int dimSlice;
	int* rezultat = slice(vectorInitial, nrElemente, 2, 2, dimSlice);
	EXPECT_EQ(rezultat[0], 89);
}

TEST(Slice, TestExceptieIndexStartNegativ) {
	try {
		int dimSlice;
		int* rezultat = slice(vectorInitial, nrElemente, -2, 4, dimSlice);
		FAIL();
	}
	catch (ExceptieAssignment2* ex) {
		SUCCEED();
	}
	catch (...) {
		FAIL();
	}
}

TEST(Slice, TestExceptieIndexFinalNegativ) {
	try {
		int dimSlice;
		int* rezultat = slice(vectorInitial, nrElemente, 2, -4, dimSlice);
		FAIL();
	}
	catch (ExceptieAssignment2* ex) {
		SUCCEED();
	}
	catch (...) {
		FAIL();
	}
}

TEST(Slice, TestExceptieIndexFinalPreaMare) {
	try {
		int dimSlice;
		int* rezultat = slice(vectorInitial, nrElemente, 2, 40, dimSlice);
		FAIL();
	}
	catch (ExceptieAssignment2* ex) {
		SUCCEED();
	}
	catch (...) {
		FAIL();
	}
}

TEST(Slice, TestExceptieIndex) {
	try {
		int dimSlice;
		int* rezultat = slice(vectorInitial, nrElemente, 2, 1, dimSlice);
		FAIL();
	}
	catch (ExceptieAssignment2* ex) {
		SUCCEED();
	}
	catch (...) {
		FAIL();
	}
}