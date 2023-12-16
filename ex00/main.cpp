/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:09:15 by hael-mou          #+#    #+#             */
/*   Updated: 2023/11/27 07:57:06 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr << "Error : expected one argument !!" << std::endl;
	}
	else {
		BtcExchange	btc("data.csv");
		//btc.showDataBase();
		btc.exchange(argv[1]);
	}
}
