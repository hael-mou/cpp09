/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 07:05:31 by hael-mou          #+#    #+#             */
/*   Updated: 2023/12/15 18:36:08 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector.hpp"

/*##############################################################################
#       * static variable :                                                    #
##############################################################################*/

const unsigned long	Vector::jacobsthal[] = {
    2u, 2u, 6u, 10u, 22u, 42u, 86u, 170u, 342u, 682u, 1366u,
    2730u, 5462u, 10922u, 21846u, 43690u, 87382u, 174762u, 349526u, 699050u,
    1398102u, 2796202u, 5592406u, 11184810u, 22369622u, 44739242u, 89478486u,
    178956970u, 357913942u, 715827882u, 1431655766u, 2863311530u, 5726623062u,
    11453246122u, 22906492246u, 45812984490u, 91625968982u, 183251937962u,
    366503875926u, 733007751850u, 1466015503702u, 2932031007402u, 5864062014806u,
    11728124029610u, 23456248059222u, 46912496118442u, 93824992236886u,
	187649984473770u, 375299968947542u, 750599937895082u, 1501199875790165u,
	3002399751580331u, 6004799503160661u, 12009599006321322u, 24019198012642644u,
	48038396025285288u, 96076792050570576u, 192153584101141152u,
	384307168202282304u, 768614336404564608u, 1537228672809129216u,
	3074457345618258432u, 6148914691236516864u
};

/*##############################################################################
#       * Constructor & Destructor  :                                          #
##############################################################################*/

//=== Default Constructor : ====================================================
Vector::Vector(void) {
}

//=== Copy Constructor : =======================================================
Vector::Vector(const Vector &other) 
{
	*this = other;
}

//=== Destructor : =============================================================
Vector::~Vector(void) {
}

/*##############################################################################
#       *  Operators  :                                                        #
##############################################################################*/

//=== Assignment Operators : ===================================================
Vector&		Vector::operator=(const Vector &other)
{
	if (this != &other)
	{
		this->mMain = other.mMain;
		this->mPend = other.mPend;
	}
	return (*this);
}

/*##############################################################################
#       * Methods  :                                                           #
##############################################################################*/

//=== mainSize : ===============================================================
size_t	Vector::size(void) const
{
	return (mMain.size());
}

//=== display : ================================================================
void	Vector::display(void) const
{
	for (CmainIterator it = mMain.begin() ; it != mMain.end(); ++it)
	{
		std::cout <<  "{ " ;
		for (CuintIterator it2 = it->begin() ; it2 != it->end(); ++it2) 
			std::cout << *it2 << " " ;
		std::cout << "}" ;
	}
	std::cout << std::endl;
}

//=== reserve : ================================================================
void	Vector::reserve(size_t __size)
{
	mMain.reserve(__size);
}

//=== push : ===================================================================
void	Vector::push(unsigned int nbr)
{
	mMain.push_back(vector_uint(1, nbr));
}

//=== init Container : =========================================================
bool	Vector::hasAtLeastTwoPairs(void)
{
	if (mMain.size() < 4)
		return (false);
	if (mMain[1].size() != mMain[0].size())
		return (false);
	if (mMain[2].size() != mMain[0].size())
		return (false);
	return (mMain[3].size() == mMain[0].size());
}

//=== combinePairs : ===========================================================
void	Vector::combinePairs(void)
{
	mainIterator it  =  mMain.begin();
	while (it + 1 < mMain.end() && it->size() == (it + 1)->size())
	{
		it->insert(it->end(), (it + 1)->begin(), (it + 1)->end());
		mMain.erase(++it);
	}
}

//=== sortPair : ===============================================================
void	Vector::sortPair(void)
{
	mainIterator it = mMain.begin() ;
	while (it + 1 < mMain.end() && it->size() == (it + 1)->size())
	{
		if (container_cmp(*(it + 1), *it))
			std::iter_swap(it, it + 1);	
		it += 2;
	}
}

//=== split Pairs : ============================================================
void	Vector::splitPairs(void)
{
	if(mMain.size() != 0)
	{
		mainIterator it  = mMain.begin();
		size_t	halfSize = it->size() / 2;
		while (it != mMain.end() &&  it->size() / (float)halfSize == 2.0)
		{
			vector_uint	vNew;
			vNew.reserve(halfSize);
			while (it->size() > halfSize)
			{
				vNew.insert(vNew.begin(), it->back());
				it->pop_back();
			}
			mMain.insert((++it)++, vNew);
		}
	}
}

//=== Create Pend : ============================================================
void Vector::CreatePend(void)
{
	mainIterator mit = mMain.begin() + 2;
	while (mit < mMain.end() && mit->size() == mMain.begin()->size())
	{
		mPend.push_back(std::make_pair(*mit, mit));
		mMain.erase(mit++);
	}
}

//=== InsertPend : =============================================================
void Vector::InsertPend(void)
{
	int i = 0;
	int index = -1;
	while (mPend.size() != 0)
	{
		if (--i == -1) {
			i = jacobsthal[++index] - 1;
			if (i > mPend.size() - 1)
				i =  mPend.size() - 1;
		}
		mainIterator pos = std::lower_bound(mMain.begin(), mPend[i].second,
			 mPend[i].first, container_cmp<vector_uint>);
		mMain.insert(pos, mPend[i].first);
		mPend.erase(mPend.begin() + i);
		for (pendIterator it = mPend.begin() ; it !=  mPend.end() ; it++) {
			if (it->second >= pos)
				it->second++;
		}
	}
}
