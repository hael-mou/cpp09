/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pmerge.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 07:05:31 by hael-mou          #+#    #+#             */
/*   Updated: 2023/12/15 18:46:54 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PMERGE_HPP
# define _PMERGE_HPP

/*##############################################################################
#        Include :                                                             #
##############################################################################*/
# include "IContainer.hpp"
# include "Vector.hpp"
# include <stdexcept>
# include <cstdlib>
# include <climits>
# include <cerrno>

/*##############################################################################
#        Pmerge Class:                                                         #
##############################################################################*/
class Pmerge {

	public:
		// === Constructor & Destructor : ============================
		Pmerge(IContainer *container = new Vector());
		virtual		~Pmerge(void);

		// === Method : ==============================================
		void		initContainer(const char **list);
		void		mergeInsertionSort(void);
		void		display(void);
	
	private:
		// === Constructor : =========================================
		Pmerge(const Pmerge &other);

		// === Attributes  : =========================================
		IContainer		*mContainer;

		// === Operators : ===========================================
		Pmerge&		operator=(const Pmerge &other);
};

#endif // _PMERGE_HPP
