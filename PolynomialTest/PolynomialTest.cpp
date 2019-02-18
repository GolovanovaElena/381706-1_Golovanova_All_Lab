#include "gtest.h"
#include "Polynomial.h"

int deg1[] = { 1, 2, 3 };
int deg2[] = { 1, 0, 3 };
int deg3[] = { 1, -2, 3 };
int deg4[] = { 1, 0, 3, 5 };
int deg5[] = { 4, 5, 6 };

TEST(TMonom, can_create_monom_wiht_zero_size)
{
  ASSERT_NO_THROW(TMonom mon(0, deg1, 1));
}

TEST(TMonom, can_create_monom)
{
  ASSERT_NO_THROW(TMonom mon(3, deg1, 1));
}

TEST(TMonom, throws_when_create_monom_with_negative_size)
{
  ASSERT_ANY_THROW(TMonom mon(-1, deg1, 1));
}

TEST(TMonom, throws_when_create_monom_with_negative_deg)
{
  ASSERT_ANY_THROW(TMonom mon(3, deg3, 1));
}

TEST(TMonom, can_create_copy_monom)
{
  TMonom mon1(3, deg1, 1);
  ASSERT_NO_THROW(TMonom mon2(mon1));
}

TEST(TMonom, can_set_and_get_next)
{
  TMonom mon1(3, deg1, 1);
  TMonom mon2(3, deg2, 1);
  ASSERT_NO_THROW(mon1.SetNext(&mon2));
  ASSERT_EQ(mon1.GetNext(), &mon2);
}

TEST(TMonom, can_set_and_get_coef)
{
  TMonom mon(3, deg1, 12);
  ASSERT_NO_THROW(mon.SetCoef(1.25));
  ASSERT_EQ(1.25, mon.GetCoef());
}

TEST(TMonom, can_set_and_get_deg)
{
  TMonom mon(3, deg1, 1);
  ASSERT_NO_THROW(mon.SetDeg(deg2));
  ASSERT_EQ(deg2[0], mon.GetDeg()[0]);
  ASSERT_EQ(deg2[1], mon.GetDeg()[1]);
  ASSERT_EQ(deg2[2], mon.GetDeg()[2]);
}

TEST(TMonom, can_set_and_get_count_big)
{
  TMonom mon(3, deg1, 1);
  ASSERT_NO_THROW(mon.SetCount(5));
  ASSERT_EQ(5, mon.GetCount());
}

TEST(TMonom, can_set_and_get_count_small)
{
  TMonom mon(3, deg1, 1);
  ASSERT_NO_THROW(mon.SetCount(1));
  ASSERT_EQ(1, mon.GetCount());
}

TEST(TMonom, assign_operator_monoms_return_true)
{
  TMonom mon1(3, deg1, 1);
  TMonom mon2(3, deg2, 5);
  ASSERT_NO_THROW(mon1 = mon2);
  ASSERT_EQ(1, mon1.GetDeg()[0]);
  ASSERT_EQ(0, mon1.GetDeg()[1]);
  ASSERT_EQ(3, mon1.GetDeg()[2]);
  ASSERT_EQ(5, mon1.GetCoef());
}

TEST(TMonom, throws_when_assign_monoms_with_different_count)
{
  TMonom mon1(3, deg1, 1);
  TMonom mon2(4, deg2, 4);
  ASSERT_ANY_THROW(mon1 = mon2);
}

TEST(TMonom, can_add_equal_monoms)
{
  TMonom mon1(3, deg1, 2.5);
  TMonom mon2(3, deg1, 1.0);
  ASSERT_NO_THROW(mon1 + mon2);
  TMonom mon3(3, deg1, 1);
  mon3 = mon1 + mon2;
  ASSERT_EQ(3.5, mon3.GetCoef());
}

TEST(TMonom, trows_when_add_different_monoms)
{
  TMonom mon1(3, deg1, 2.5);
  TMonom mon2(3, deg2, 1.0);
  TMonom mon3(4, deg4, 1);
  ASSERT_ANY_THROW(mon1 + mon2);
  ASSERT_ANY_THROW(mon1 + mon3);
}

TEST(TMonom, can_substract_equal_monoms)
{
  TMonom mon1(3, deg1, 2.5);
  TMonom mon2(3, deg1, 1.0);
  ASSERT_NO_THROW(mon1 - mon2);
  TMonom mon3(3, deg1, 1);
  mon3 = mon1 - mon2;
  ASSERT_EQ(1.5, mon3.GetCoef());
}

TEST(TMonom, trows_when_substract_different_monoms)
{
  TMonom mon1(3, deg1, 2.5);
  TMonom mon2(3, deg2, 1.0);
  TMonom mon3(4, deg4, 1);
  ASSERT_ANY_THROW(mon1 - mon2);
  ASSERT_ANY_THROW(mon1 - mon3);
}

TEST(TMonom, can_multiply_equal_monoms)
{
  TMonom mon1(3, deg1, 5);
  TMonom mon2(3, deg2, 4);
  ASSERT_NO_THROW(mon1 * mon2);
  TMonom mon3(3, deg1, 4);
  mon3 = mon1 * mon2;
  ASSERT_EQ(20, mon3.GetCoef());
  ASSERT_EQ(2, mon3.GetDeg()[0]);
  ASSERT_EQ(2, mon3.GetDeg()[1]);
  ASSERT_EQ(6, mon3.GetDeg()[2]);
}

TEST(TMonom, trows_when_multiply_different_monoms)
{
  TMonom mon1(3, deg1, 2);
  TMonom mon2(4, deg4, 2);
  ASSERT_ANY_THROW(mon1 * mon2);
}

TEST(TMonom, can_equivalence_monoms)
{
  TMonom mon1(3, deg1, 2.5);
  TMonom mon2(3, deg1, 2.5);
  TMonom mon3(3, deg2, 2.5);

  ASSERT_TRUE(mon1 == mon2);
  ASSERT_FALSE(mon1 == mon3);
}

TEST(TMonom, trows_when_equivalence_monoms_with_different_count)
{
  TMonom mon1(3, deg1, 1);
  TMonom mon2(4, deg4, 1);
  ASSERT_ANY_THROW(mon1 == mon2);
}

TEST(TMonom, can_compare_equal_monoms)
{
  TMonom mon1(3, deg1, 1);
  TMonom mon2(3, deg2, 2);
  ASSERT_TRUE(mon1 > mon2);
  ASSERT_FALSE(mon1 < mon2);
  TMonom mon3(3, deg5, 4);
  ASSERT_TRUE(mon1 < mon3);
  ASSERT_FALSE(mon3 < mon1);
}

TEST(TMonom, trows_compare_monoms_with_different_count)
{
  TMonom mon1(3, deg1, 1);
  TMonom mon2(4, deg4, 2);
  ASSERT_ANY_THROW(mon1 > mon2);
  ASSERT_ANY_THROW(mon1 < mon2);
}

TEST(TMonom, trows_compare_when_monoms_equal)
{
  TMonom mon1(3, deg1, 1);
  TMonom mon2(3, deg1, 1);
  ASSERT_ANY_THROW(mon1 > mon2);
  ASSERT_ANY_THROW(mon2 < mon1);
}

TMonom tmon1(3, deg1, 1);
TMonom tmon2(3, deg2, 2);
TMonom tmon3(4, deg4, 1);
TMonom tmon4(3, deg5, 3);
TMonom tmon5(3, deg1, 0);


TEST(TPolynom, can_create_polynom)
{
  ASSERT_NO_THROW(TPolynom pol(5));
}

TEST(TPolynom, throws_when_create_polynom_with_negative_size)
{
  ASSERT_ANY_THROW(TPolynom pol(-5));
}

TEST(TPolynom, can_create_copy_polynom)
{
  TPolynom pol1(3);
  pol1 += tmon1;
  pol1 += tmon2;
  ASSERT_NO_THROW(TPolynom pol2(pol1));
  TPolynom pol2(pol1);
  ASSERT_TRUE(pol2 == pol1);
}

TEST(TPolynom, can_get_size_polynom)
{
  TPolynom pol(3);
  pol += tmon1;
  pol += tmon2;
  ASSERT_EQ(pol.GetSize(), 2);
}

TEST(TPolynom, trows_when_add_different_polynoms)
{
  TPolynom pol(4);
  pol += tmon3;
  TPolynom pol2(3);
  pol2 += tmon1;
  ASSERT_ANY_THROW(pol + pol2);
}

TEST(TPolynom, can_add_equal_polynoms)
{
  TPolynom pol1(3);
  pol1 += tmon1;
  pol1 += tmon2;
  TPolynom pol2(3);
  pol2 += tmon1;
  pol2 += tmon4;
  ASSERT_NO_THROW(pol1 + pol2);
  TPolynom pol3(3);
  pol3 = pol1 + pol2;
  TMonom* mon = pol3.GetBegin();
  ASSERT_EQ(3, pol3.GetSize());
  ASSERT_TRUE(*mon == tmon4);
  mon = mon->GetNext();
  ASSERT_TRUE(*mon == tmon1);
  mon = mon->GetNext();
  ASSERT_TRUE(*mon == tmon2);
  mon = mon->GetNext();
  ASSERT_TRUE(mon == 0);
}

TEST(TPolynom, trows_when_sub_different_polynoms)
{
  TPolynom pol1(4);
  pol1 += tmon3;
  TPolynom pol2(3);
  pol2 += tmon1;
  ASSERT_ANY_THROW(pol1 - pol2);
}

TEST(TPolynom, can_sub_equal_polynoms)
{
  TPolynom pol1(3);
  pol1 += tmon1;
  pol1 += tmon2;
  TPolynom pol2(3);
  pol2 += tmon1;
  pol2 += tmon4;
  ASSERT_NO_THROW(pol1 - pol2);
  TPolynom pol3(3);
  pol3 = pol1 - pol2;
  TMonom* mon = pol3.GetBegin();
  ASSERT_EQ(2, pol3.GetSize());
  ASSERT_TRUE(*mon == tmon4);
  ASSERT_TRUE(mon->GetCoef() == -3);
  mon = mon->GetNext();
  ASSERT_TRUE(*mon == tmon2);
  ASSERT_TRUE(mon->GetCoef() == 2);
  mon = mon->GetNext();
  ASSERT_TRUE(mon == 0);
}

TEST(TPolynom, assign_operator_polynoms_work)
{
  TPolynom pol1(3);
  pol1 += tmon1;
  pol1 += tmon5;
  TPolynom pol2(3);
  pol2 += tmon2;
  pol2 += tmon4;
  ASSERT_NO_THROW(pol1 = pol2);
  TMonom* mon = pol1.GetBegin();
  ASSERT_TRUE(*mon == tmon4);
  ASSERT_EQ(3, mon->GetCoef());
  mon = mon->GetNext();
  ASSERT_TRUE(*mon == tmon2);
  ASSERT_EQ(2, mon->GetCoef());
  mon = mon->GetNext();
  ASSERT_TRUE(mon == 0);
}

TEST(TPolynom, throws_when_assign_monoms_with_different_count)
{
  TPolynom pol1(4);
  TPolynom pol2(3);
  ASSERT_ANY_THROW(pol1 = pol2);
}

TEST(TPolynom, can_equivalence_polynoms)
{
  TPolynom pol1(3);
  pol1 += tmon1;
  pol1 += tmon5;
  TPolynom pol2(3);
  pol2 += tmon2;
  pol2 += tmon4;
  ASSERT_FALSE(pol1 == pol2);
  pol2 = pol1;
  ASSERT_TRUE(pol1 == pol2);
  TMonom mon(3, deg1, 2);
  TPolynom pol3(3);
  pol3 += tmon1;
  TPolynom pol4(3);
  pol4 += mon;
  ASSERT_FALSE(pol3 == pol4);
}

TEST(TPolynom, trows_when_equivalence_polynoms_with_different_count)
{
  TPolynom pol1(3);
  TPolynom pol2(4);
  ASSERT_ANY_THROW(pol1 == pol2);
}

TEST(TPolynom, can_multiply_equal_polynoms)
{
  TPolynom pol1(3);
  pol1 += tmon1;
  pol1 += tmon5;
  TPolynom pol2(3);
  pol2 += tmon2;
  pol2 += tmon4;

  ASSERT_NO_THROW(pol1 * pol2);

  TPolynom Res(3);
  Res = pol1 * pol2;
  ASSERT_EQ(2, Res.GetSize());

  TMonom* mon = Res.GetBegin();
  TMonom mon1 = tmon1 * tmon2;
  TMonom mon2 = tmon1 * tmon4;
  ASSERT_TRUE(*mon == mon2);
  ASSERT_EQ(mon->GetCoef(), 3);
  mon = mon->GetNext();
  ASSERT_TRUE(*mon == mon1);
  ASSERT_EQ(mon->GetCoef(), 2);
  mon = mon->GetNext();
  ASSERT_TRUE(mon == NULL);
}

TEST(TPolynom, trows_when_multiply_different_polynoms)
{
  TPolynom pol1(3);
  TPolynom pol2(4);
  ASSERT_ANY_THROW(pol1 * pol2);
}

TEST(TPolynom, can_plus_eq_polynoms)
{
  TPolynom pol1(3);
  pol1 += tmon2;
  pol1 += tmon4;
  TMonom* mon = pol1.GetBegin();
  ASSERT_TRUE(*mon == tmon4);
  ASSERT_EQ(mon->GetCoef(), 3);
  mon = mon->GetNext();
  ASSERT_TRUE(*mon == tmon2);
  ASSERT_EQ(mon->GetCoef(), 2);
  mon = mon->GetNext();
  ASSERT_TRUE(mon == NULL);
}

TEST(TPolynom, trows_when_plus_eq_different_polynoms)
{
  TPolynom pol1(3);
  ASSERT_ANY_THROW(pol1 += tmon3);
}

TEST(TPolynom, can_sub_eq_polynoms)
{
  TPolynom pol1(3);
  pol1 -= tmon2;
  pol1 += tmon1;
  pol1 -= tmon4;
  TMonom* mon = pol1.GetBegin();
  ASSERT_TRUE(*mon == tmon4);
  ASSERT_EQ(mon->GetCoef(), -3);
  mon = mon->GetNext();
  ASSERT_TRUE(*mon == tmon1);
  ASSERT_EQ(mon->GetCoef(), 1);
  mon = mon->GetNext();
  ASSERT_TRUE(*mon == tmon2);
  ASSERT_EQ(mon->GetCoef(), -2);
  mon = mon->GetNext();
  ASSERT_TRUE(mon == NULL);
}

TEST(TPolynom, trows_when_sub_eq_different_polynoms)
{
  TPolynom pol(3);
  ASSERT_ANY_THROW(pol -= tmon3);
}


