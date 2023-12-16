/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 07:05:31 by hael-mou          #+#    #+#             */
/*   Updated: 2023/11/27 09:46:07 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _BITCOINEXCHANGE_HPP
# define _BITCOINEXCHANGE_HPP

/*##############################################################################
#        Includes:                                                             #
##############################################################################*/
# include <iostream>
# include <cstdlib>
# include <cstring>
# include <fstream>
# include <sstream>
# include <map>

//==============================================================================
# define OFF	(-1)

/*##############################################################################
#        BitcoinExchange Class:                                                #
##############################################################################*/
class BtcExchange {

	public:
		// === type define : =========================================
		typedef	unsigned int						uint;
		typedef std::string							string;
		typedef std::map<string, double>			base_type;
		typedef std::pair<string, double>			pair;
		typedef base_type::iterator					iterator;

		// === Constructor & Destructor : ============================
		BtcExchange(const char *dataBase = "NON_FILE");
		BtcExchange(const BtcExchange&	other);
		virtual	~BtcExchange(void);

		// === Operator : ============================================
		BtcExchange&		operator=(const BtcExchange &other);

		// == Methods : ==============================================
		void		setDataBase(const char *dataBase);
		void		showDataBase(void);
		double		getValueFromDataBase(const string& date);
		void		exchange(const char *filename);
	
	private:
		// === Attributes : ==========================================
		base_type	mDataBase;

		// == Methods : ==============================================
		void	handleException(string line, uint nline, const char *msg);
		void	uploadDataBase(base_type& dtb, std::ifstream& file);
		pair	parse_pair(string& line, const char *delim, int max);
		double	checkValue(string valueStr, int max);
		string	checkDate(string dateStr);
};

#endif // _BITCOINEXCHANGE_HPP
